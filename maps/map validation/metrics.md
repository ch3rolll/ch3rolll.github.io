## LMQA
[link](http://faculty.cs.tamu.edu/dzsong/pdfs/Binbin_LaneQualityAssessment_V19.pdf)

### Correctness Metric

Using KL divergence to measure the likelihood between Prior Point Cloud overlapped with current PCL and Points from Images

` Sum [P(Ck|Sp)  log( P(Ck|Sp) / P(Ck|Sq) ) ]`


Where `P(Ck|Sp)` is estimated by bayesian

#### Kullback-leibler divergence

A measure of how one probability distribution is different from a second, reference probability distribution.

- A KL divergence of 0 indicates that we have two indentical distributions
- 1 indicates that two distributions are totally different

### Shape Metric

- Cubic Polynomial
- Take average of lane width
- Us indicates not only smoothness, but also the width requirement