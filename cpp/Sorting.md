# Inseration Sort

Take the first element from unsorted part and insert to the right palce of the sorted part.

 Cases| Runtime Complexity
 --|--
Best case (nearly sorted)| O(n)
Worst case | O(n^2)



```cpp
#include <iostream>
#include <cstdlib>

void insertion_sort(int arr[], const int length);
void print_array(const int array[],int size);

void insertion_sort(int arr[], const int length){

    for (int i = 1; i < length; i++){
    	int j = i;
    	while ( j > 0 && arr[j - 1] > arr[j]){
    		int tmp = arr[j];
    		arr[j] = arr[j - 1];
    		arr[j-1] = tmp;
    		j--;
    	}
    }
}

void print_array(const int array[], int size){
    for (int j = 0; j < size; j++)
    {
        std::cout << array[j] << std::endl;
    }
}

int main(){

    int array[] = {4,6,3,7,5,9,2,8,1,10};
    insertion_sort(array,10);
    print_array(array,10);
    return 0;
}
```
# Merge Sort

Merge sort is a Divide-and-conquer method. It divides input into two halves and call itself to the two halves and merge them together.

```cpp

#include <iostream>

void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
  std::cout << std::endl;
}

void Merger(int arr[], int lo, int  mi, int hi){
    int *temp = new int[hi-lo+1];//temporary merger array
    int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
    int k = 0;//k is for the temporary array
    while(i <= mi && j <=hi){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    //rest elements of left-half
    while(i <= mi)
        temp[k++] = arr[i++];
    //rest elements of right-half
    while(j <= hi)
        temp[k++] = arr[j++];
    //copy the mergered temporary array to the original array
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];

    delete []temp;
}
void MergeSortHelper(int arr[], int lo, int hi){
    int mid;
    if(lo < hi){
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, lo, mid);
        MergeSortHelper(arr, mid+1, hi);
        Merger(arr, lo, mid, hi);
    }
}
void MergeSort(int arr[], int arr_size){
    MergeSortHelper(arr, 0, arr_size-1);
}

int main() {
  int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
  int n = sizeof(array)/sizeof(array[0]);

  std::cout << "Before Merge Sort :" << std::endl;
  PrintArray(array, n);

  MergeSort(array, n);

  std::cout << "After Merge Sort :" << std::endl;
  PrintArray(array, n);
  return (0);
}
```

# Quick Sort 

Find a pivoting element and go through the array to put smaller elements to its left. And partition the left and right side.

```cpp
#include <iostream>
#include<cstdlib> // For rand();

void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
  std::cout << std::endl;
}

// Swapping two values. Dont use XOR swap or +/- swap, Not working for same address and not fast.
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
int Partition(int arr[], int lo, int hi){
	int j = lo + 1;
    for (int i = lo+1; i <= hi; i++){
    	if (arr[i] < arr[lo]){
    		swap(&arr[i], &arr[j]);
    		j++;
    	}
    }
    swap(&arr[lo], &arr[j-1]);
    return j-1;
}

void QuickSortHelper(int arr[], int lo, int hi){

    if (lo < hi){
    	int pvt = lo + rand()%(hi - lo + 1);
    	swap(&arr[lo], &arr[pvt]);

    	pvt = Partition(arr, lo, hi);
   		QuickSortHelper(arr, lo, pvt-1);
    	QuickSortHelper(arr, pvt+1, hi);
    }
}
void QuickSort(int arr[], int arr_size){
    QuickSortHelper(arr, 0, arr_size-1);
}

int main() {
  int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
  int n = sizeof(array)/sizeof(array[0]);

  std::cout << "Before Quick Sort :" << std::endl;
  PrintArray(array, n);

  QuickSort(array, n);

  std::cout << "After Quick Sort :" << std::endl;
  PrintArray(array, n);
  return (0);
}
```

# Heap sort

Build a heap for an array, extract the root node and heapify the rest.

```cpp
#include <iostream>

using namespace std;

void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
  std::cout << std::endl;
}

void Heapify(int arr[], int n, int index){
	int left = 2 * index+1, right = left + 1;
	int max_index = index;
	if (left < n && arr[left] > arr[index]){
		max_index = left;
	}
	if (right < n && arr[right] > arr[max_index]){
		max_index = right;
	}

	if(max_index != index){
		swap(arr[index], arr[max_index]);
		Heapify(arr, n, max_index);
	}
}

void BuildHeap(int arr[], int n){

	for (int i = n/2-1; i >= 0; i--){
		Heapify(arr, n, i);
	}
}

void HeapSort(int arr[], int n){
	BuildHeap(arr, n);
	int index = 0;
	while(index < n){
		swap(arr[n-1-index], arr[0]);
		Heapify(arr, n-1-index, 0);
		index++;
	}
}

int main() {
  int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
  int n = sizeof(array)/sizeof(array[0]);

  std::cout << "Before Heap Sort :" << std::endl;
  PrintArray(array, n);

  HeapSort(array, n);

  std::cout << "After Heap Sort :" << std::endl;
  PrintArray(array, n);
  return (0);
}

```
