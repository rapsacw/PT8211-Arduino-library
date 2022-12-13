# PT8211-Arduino-library
Quick and easy routines for the cheapest DAC available today.<br>
Install:<br>
Copy the pt8211 folder and its contents to your arduino library folder.<br>

Usage:
Only 2 functions provided;
- void PT8211_out(unsigned int)<br>
Outputs the 32 bit integer to the DAC, the upper 16 bit go to the right channel output, the lower 16 bit to the left.
If you actually use the left channel then you need to call the function twice (with the same unsigned int).

- void PT8211_init(char,char,char);<br>
Sets the I/O pins for data/bitclock/word select and initializes the DAC.

Take note:
This DAC is supposed to be used for audio, and as such it has an output range of 0.8V to 2.5V (when supplied with 3.3V power).
