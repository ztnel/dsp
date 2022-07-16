# Digital Filters

Digital filtration is a large part of DSP. It can be used for:
1. Signal Seperation
2. Signal Restoration

A filter has typically 1 input signal and 1 filtered output signal. The input signal is represented by a discrete sequence of samples i.e. [0, -1, -0.2, 2.3 ... ], where the signal samples are taken over a fixed sampling frequency fs:

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Signal_Sampling.svg/1200px-Signal_Sampling.svg.png)

We can pass the input signal through a filter which has a certain frequency response which we can design for our use case:

![img](https://zipcpu.com/img/fir-lpf-design.png)

Since we are sampling discrete signals we have an upper bound in our frequency filter design called the Nyquist frequency limit which is half the sampling frequency. Therefore we can design a frequency response between 0 and fs/2 Hz.

After the input signal is passed through the filter we get another discrete signal with 2 properties:
1. Same length as input sequence (most filters)
2. Altered frequency (and time) domain characteristics due to filter