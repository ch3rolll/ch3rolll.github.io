#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include "opencv2/opencv.hpp"
#include "lane_line_postprocessing.hpp"

LaneLinePipeline::LaneLinePipeline() {
  transform_ = (cv::Mat_<double>(3, 3) 
      << 787.98212, -995.4483, 398359.25,
         -33.402023, -637.34857, 840914.19, 
         -0.05194585, -0.99118584, 1228.1084);
  for (int i = 0; i < 4; i++) {
    left_p_.push_back(0.0);
    right_p_.push_back(0.0);
  }
}

double LaneLinePipeline::Mean(std::vector<int> input) {
  double sum = 0;
  for (const auto& item : input) {
    sum += item;
  }
  return sum / input.size();
}

std::vector<double> LaneLinePipeline::Sum(const cv::Mat& image) {
  // TODO make sure this matches up with np sum
  std::vector<double> histogram;
  for (int i = 0; i < image.size().width; i++) {
    double sum = 0;
    for (int j = 0; j < image.size().height; j++) {
      // might need to be j, i
      sum += image.at<double>(i, j);
    }
    histogram.push_back(sum);
  }
  return histogram;
}

std::vector<int> LaneLinePipeline::GetPeaks(const cv::Mat& heat_map_slice, int noisy_th) {
  auto histogram = Sum(heat_map_slice);
  for (int i = 0; i < histogram.size(); i++) {
    if (histogram[i] < noisy_th) {
      histogram[i] = 0;
    }
  }
  auto peaks = ArgRelExtrema(histogram);
  if (peaks.size() == 0) {
    return peaks;
  }
  return FilterPeaks(peaks);
}

std::vector<int> LaneLinePipeline::FilterPeaks(const std::vector<int>& peaks) {
  // Filter peaks and get filtered peaks, link peaks gap < 30 as one group
  // and use mean(peak_group) as the center of peak_group
  std::vector<int> filtered_peaks;
  std::vector<int> current_i;
  for (const auto& p : peaks) {
    if (current_i.size() == 0 || p-current_i.back() >= 30) {
      if (current_i.size() == 0) {
        current_i.push_back(p);
      } else {
        filtered_peaks.push_back((int)Mean(current_i));
      }
    } else if (p - current_i.back() < 30) {
      current_i.push_back(p);
      if (p - current_i[0] > 100) {
        filtered_peaks.push_back((int)Mean(current_i));
        current_i.clear();
        current_i.push_back(p);
      }
    }
    filtered_peaks.push_back((int)Mean(current_i));
    return filtered_peaks;
  }
}

std::vector<int> LaneLinePipeline::ArgRelExtrema(const std::vector<double>& data) {
  std::vector<bool> results;
  for (int i = 0; i < data.size(); i++) {
    results.push_back(true);
  }
  for (int i = 0; i < data.size(); i++) {
    int plus_index = i + 1;
    if (plus_index >= data.size()) {
      plus_index = i;
    }
    int minus_index = i - 1;
    if (minus_index < 0) {
      minus_index = i;
    }
    results[i] = results[i] & data[i] > data[plus_index];
    results[i] = results[i] & data[i] > data[minus_index];
  }
  std::vector<int> indices;
  for (int i = 0; i < results.size(); i++) {
    if (results[i]) {
      indices.push_back(i);
    }
  }
  return indices;
}

int GetPoint(const cv::Mat& heat_map_slice, int start_col, int row_index, int half_range, int peak_th, int noisy_th, std::vector<int> row_points, std::vector<int> col_points) {
  
}

void LaneLinePipeline::PostProcessingBirdsEye(const cv::Mat& image, int ego_offset, bool debug) {
// bird_view, mask, points = from_image_to_points(image)

}

std::unordered_map<std::string, std::vector<int>> LaneLinePipeline::GetPointsForOneLine(const cv::Mat& heatmap, bool debug, int slice_height, int half_range, int peak_th, int noisy_th) {
  // Calculate histogram

  int height = heatmap.rows;
  int width = heatmap.cols;

  cv::Mat histogram;
  cv::reduce(heatmap, histogram, 0, CV_REDUCE_SUM);

  int max_index = 0, max_his = 0;

  for (auto h : histogram[0]){
      if (h > max_his){
        max_his = h;
        max_index = i;
      }
  }

  double buttom_ration_to_start = std::max((double)max_index/1080, 0.5);

  std::unordered_map<std::string, std::vector<int>> result_hash;

  int slice_num = height/slice_height;

  int start_index = int(slice_num * (buttom_ration_to_start + ( 1 - buttom_ration_to_start ) * 0.5)); 

  // Find peaks
  auto peaks = GetPeaks(heatmap(cv::Range(int(height * buttom_ration_to_start), cv::Range::end), cv::Range:all()), noisy_th = noisy_th);

  if (peaks.size() > 0){
      for (int i = 0; i < peaks.size(); i++){
          auto pair = FindLineFromInitialPoint(heatmap, peaks[i], start_index, slice_height, slice_num, half_range);

          result_hash[std::to_string(i) + "_row"] = pair.first;
          result_hash[std::to_string(i) + "_col"] = pair.second;
      }
  }

  return result_hash;
}


  /*
        histogram = np.sum(heatmap, axis=1)
        histogram[histogram < noisy_th]=0    # filter some noise

        max_index = 0;
        max_his = 0;
        for i in range(0, len(histogram)):
            if histogram[i] > max_his:
                max_his = histogram[i]
                max_index = i;

        buttom_ration_to_start = max(max_index / 1080, 0.5)

        print("buttom_ration_to_start: " + str(buttom_ration_to_start))

        result_hash = {}
        height,width = heatmap.shape
        slice_num = height // slice_height
        start_index = int(slice_num*(buttom_ration_to_start+(1-buttom_ration_to_start)*0.5))

        # Find peaks
        peaks = self.get_peaks(heatmap[int(height*buttom_ration_to_start):,:], noisy_th = noisy_th)

        if len(peaks)>0:
            print("Peaks in total: ",len(peaks))
            print(peaks)
            for i in range(0,len(peaks)):
                row_points, col_points = self.find_line_from_initial_point(heatmap, peaks[i], start_index,
                                                                    slice_height = slice_height, slice_num = slice_num, half_range = half_range)
                result_hash[str(i) + "_row"] = row_points
                result_hash[str(i) + "_col"] = col_points
        else:
            print('No peaks found!')

        return result_hash
        */



std::pair<std::vector<int>, std::vector<int>> FindLineFromInitialPoint(const cv::Mat& heatmap, int peak, int start_index, int slice_height, int slice_num, int half_range = 70){
  std::vector<int> row_points, col_points;

  // Scan up
  int line_col = peak;
  double delta = 0;

  for(int i = start_index; i > 0; i--){

      auto tmp = GetPoint( heatmap(cv::Range(i * slice_height, (i + 1) * slice_height), cv::Range:all()), 
                      line_col, i * slice_height, half_range, peak_th, noisy_th, row_points, col_points);

      if (i < start_index -1 || tmp == -1){
          line_col = (tmp + delta >= 0) ? (tmp + delta) : line_col;
      } else {
          delta = tmp - line_col;
          line_col = (tmp >= 0) ? tmp : line_col; 
      }
  }

  // Scan down
  line_col = peak;

  for(int i = start_index + 1; i < slice_num; i++){

      tmp = GetPoint( heatmap(cv::Range(i * slice_height, (i + 1) * slice_height), cv::Range:all()), 
                      line_col, i * slice_height, half_range, peak_th, noisy_th, row_points, col_points);

      if (i < start_index + 2 || tmp == -1){
          line_col = (tmp + (tmp - line_col) >= 0) ? (tmp + (tmp - line_col)) : line_col;
      } else {
          line_col = (tmp >= 0) ? tmp : line_col; 
      }
  }
  return std::make_pair(row_points, col_points);
}

// 

bool PolyWithFilter(std::vector<double> x_pts, std::vector<double> y_pts, int order, std::vector<double>& p(4)){
    bool too_few = true;
    p.resize(4, 0);

    const int n = x_pts.size();

    if( n == 0){
        return too_few;
    } else if ( n < 5){
        auto tmp = cv::polyfit(x_pts, y_pts, 1);
        p[2] = tmp[0];
        p[3] = tmp[1];
    } else{
        too_few = false;
        p = cv::polyfit(x_pts, y_pts, order);
    }
    return too_few;
}

void LaneLinePipeline::FromImageToPoints(cv::Mat& image, int heat_map_threshold, int half_range, int peak_th) {
  cv::Mat bird_v = PreProcessing(image);
  // XXX Missing prediction step here. Later factor this out into preprocessing and postprocessing. 
  cv::Mat result = RunInference(bird_v);
  // TODO (dsew) might want to use adaptive thresholding here?
  cv::threshold(result, result, heat_map_threshold, 255, cv::THRESH_TOZERO);

  GetPointsForOneLine(result, true, 27, half_range, peak_th);
  
  // return three items: bird_v, result, get_points_for_one_line

}

cv::Mat LaneLinePipeline::RunInference(const cv::Mat& image) {
  cv::Mat output;
  return output;
}

// Converts input image to birds-eye view in preparation for feeding it into the network
cv::Mat LaneLinePipeline::PreProcessing(const cv::Mat& image) {
  cv::Mat output;
  cv::warpPerspective(image, output, transform_, image.size(), cv::INTER_NEAREST | cv::WARP_INVERSE_MAP);
  return output;
}

int main() {
  LaneLinePipeline pipeline;
  std::cout << "hello world" << std::endl;
  // Test case:
  // [2,1,2,3,2,0,1,0] -> [3, 6] 
  std::vector<double> input = {2,1,2,3,2,0,1,0};
  auto result = pipeline.ArgRelExtrema(input);
  std::cout << "Results: ";
  for (int item : result) {
    std::cout << item << ", ";
  }
  std::cout << std::endl;
}
