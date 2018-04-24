import os
import numpy as np
from numpy.fft import fft, fftfreq
from scipy.ndimage.filters import gaussian_filter1d
import matplotlib.pyplot as plt
%matplotlib inline
a = np.loadtxt('Testing/random.dat', unpack=True)
plt.plot(a[0], a[1])
plt.ylim(-2,2)
plt.plot(fft(a[1]))
plt.plot([np.sum((a[1] - gaussian_filter1d(a[1], x))**2) for x in np.arange(0,10,0.1)])
np.sum((a[1] - gaussian_filter1d(a[1], 3))**2)
plt.plot(gaussian_filter1d(a[1], 3))

for i in range(1, 10, 1):
    plt.plot(gaussian_filter1d(np.sin(np.linspace(0, 10, 100)), i))
np.median(fft(a[1]))
np.average(a[1])
