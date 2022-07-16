# Finite Impulse Response Theory

Modified: 2022-07

FIR fitlers are a class of filters that when an impulse function is fed as the input the output will eventually return to 0. 
> In other words it is a filter whose *impulse response* or response to any *finite length* input is of *finite* duration because it settles to 0 in *finite* time. This means that the filter is always stable.

An FIR filter can be described by a sequence of numbers of finite length called an impulse response (typically denoted by h). The output of the FIR filter can be calculated by convolving the input signal and the impulse response.

How does the impulse response of the filter determine the frequency response of the filter?

1. Fourier Transform of impulse response is equal to frequency response of filter
2. Convolution in time domain is equal to multiplication in frequency domain

In essence, to design a filter we need to come up with the desired frequency response then take the inverse Fourier Transform to get the impulse response.

### Parameters for FIR Filter Design:
1. Sampling Frequency
2. Filter Length
3. Frequency Response
4. Windowing Function
5. Time Domain properties (rise-time, overshoot)