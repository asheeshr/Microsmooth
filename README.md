Microsmooth
===========

A lightweight and fast signal smoothing library for the Arduino platform.

This library provides implementations of signal processing algorithms like:

- Simple Moving Average (`SMA`)
- Cumulative Moving Average (`CMA`)
- Exponential Moving Average (`EMA`)
- Savitzky Golay Filter (`SGA`)
- Ramer Douglas Peucker Algorithm (`RDP`)
- Kolmogorov Zurbenko Algorithm (`KZA`)

The library can be used as shown below:

- First, initialize the library: `uint16_t *history = ms_init(SMA);` where `SMA` can be replaced with any of the three  alphabet codes given above.
- Then, input your analog signal value using `analogRead()` or `pulseIn` into an `int` variable, referred here as `channel_value`.
- Pass the variable into the filter initialized in the first step: `int processed_value = sma_filter(channel_value, history);`
- Repeat for input channel for a time domain signal.
- When done, deinit library with: `ms_deinit(history);` (This releases the memory being utilized)

The filters all have the same interface:

    <Three digit code>_filter(channel_value, history)
where `<Three digit code>` can be `sma`, `cma`, `ema`, `rdp`, `sga`, `kza`.


The best performing filter at present is `EMA` with alpha parameter `0.10`. I will upload a detailed performance analysis in a couple of weeks.
