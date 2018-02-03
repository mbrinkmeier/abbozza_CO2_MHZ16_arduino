# abbozza_CO2_MHZ16_arduino

This project is a plugin for [abbozza! Arduino](http://inf-didaktik.rz.uos.de/abbozza/).
It adds blocks for the MH-Z16 CO2-Sensor.

The MH-Z16 has a UART interface and can be connected to nearly any pair of pins.

It provides an device block for the configuration of the sensor, a calibration block,
a measurment block and a block to access the last measured value in ppm.

## Installation

Build it using `ànt`. Then copy the jar-file from `dist/abbozza_CO2_MHZ16_arduino` to `Arduino/tools/Abbozza/plugins`.

You can activate the plugin in the configuration dialog.
