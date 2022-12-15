# PT8211-Arduino-library
Quick and dirty routines for the cheapest DAC available today.<br><br>
Install:<br>
Copy the pt8211 folder and its contents to your arduino library folder.<br>

Usage:
Only 2 functions provided;
- void PT8211_out(unsigned short left, unsigned short right)<br>
Outputs 16bit short integer for left channel and 16 bit short integer for right channel.
- void PT8211_init(char,char,char);<br>
Sets the I/O pins for data/bitclock/word select and initializes the DAC.

Take note:
This DAC is supposed to be used for audio, and as such it has an output range of 0.8V to 2.5V (when supplied with 3.3V power).
Due to the weird 2-complement implementation the usable input range excludes 0x0000 and 0xffff (the driver limits the input to 0x0001 and 0xfffe).
