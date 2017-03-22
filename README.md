Microsmooth
===========

## Introduction

A lightweight and fast signal smoothing library for the Arduino platform.

This library provides implementations of signal processing algorithms like:

- Simple Moving Average (`SMA`)
- Cumulative Moving Average (`CMA`)
- Exponential Moving Average (`EMA`)
- Savitzky Golay Filter (`SGA`)
- Ramer Douglas Peucker Algorithm (`RDP`)
- Kolmogorov Zurbenko Algorithm (`KZA`)

## Installation

Use the standard process for Arduino libraries. The following steps are involved:

- Create a folder `libraries` in your Sketchbook
- Git clone, or download and extract, this library in that folder. So, your sketchbook should have the following structure -> `/libraries/microsmooth/microsmooth.[cpp|h]` and additional files.
- In your sketch, add `#include <microsmooth.h>` and compile. 

## Usage

The library can be used as shown below:

- First, initialize the library: `uint16_t *history = ms_init(SMA);` where `SMA` can be replaced with any of the three  alphabet codes given above.
- Then, input your analog signal value using `analogRead()` or `pulseIn` into an `int` variable, referred here as `channel_value`.
- Pass the variable into the filter initialized in the first step: `int processed_value = sma_filter(channel_value, history);`
- Repeat for input channel for a time domain signal.
- When done, deinit library with: `ms_deinit(history);` (This releases the memory being utilized)

The filters all have the same interface:

    <Three digit code>_filter(channel_value, history)
where `<Three digit code>` can be `sma`, `cma`, `ema`, `rdp`, `sga`, `kza`.

## Code Sample

A simple code sample for using any of the filters in the library is available [here](https://gist.github.com/asheeshr/bc87f8c6486f649ef029).

## Performance Analysis

The best performing filter at present is `EMA` with alpha parameter `0.10`.

The ranking strategy for the filters is discussed in this [paper](http://ieeexplore.ieee.org/xpls/abs_all.jsp?arnumber=6849804). 
