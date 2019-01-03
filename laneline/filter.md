1. Numpy

```python

window = np.hanning()
s = numpy.r_[x[window_len-1:0:-1],x,x[-2:-window_len-1:-1]]
numpy.convolve(w/w.sum(),s,mode='same')

```