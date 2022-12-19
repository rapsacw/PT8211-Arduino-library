#include <pt8211.h>
#include <Arduino.h>

// PT8211 audio R-2R dac
// 2 16 bit outputs (left+right)
// input: 16bit short integer for left output, 16 bit short integer for right channel
// wsl,din sampled on rising edge of bck and data is output after receiving 16 bits of data for each channel.
// The output voltage can be set between ~0.8V .. ~2.5V in 65536 steps

void PT8211_out(unsigned short left, unsigned short right)
{
  int i;
  unsigned int lr;

  // bounds check/limiting
  if(left<1) left = 1;
  if(right<1) right = 1;
  if(left>0xfffe) left = 0xfffe;
  if(right>0xfffe) right = 0xfffe;
  lr = (right<<16) | left;
  // convert to 'strange' 2-complement used by pt8211
  lr -= 0x80008000;
  for(i=0;i<32;i++)
  {
    if(i == 16)
      digitalWrite(pin_8211_ws, 1);

    digitalWrite(pin_8211_din, (lr&0x80000000)?1:0);
    digitalWrite(pin_8211_bck, 1);
    digitalWrite(pin_8211_bck, 0);
    lr <<= 1;
  }
  digitalWrite(pin_8211_ws, 0);
}

void PT8211_init(char pin_din,char pin_bck,char pin_ws)
{
  pinMode(pin_8211_din,OUTPUT);
  pinMode(pin_8211_bck,OUTPUT);
  pinMode(pin_8211_ws,OUTPUT);
  digitalWrite(pin_8211_din, 0);
  digitalWrite(pin_8211_bck, 0);
  digitalWrite(pin_8211_ws, 0);
  PT8211_out(0,0);
}
