#include <pt8211.h>

// PT8211 audio R-2R dac
// 2 16 bit outputs (left+right)
// input: 32bit, upper 16bit for right output (wsl low), lower 16 bit for left channel (wsl high)
// wsl,din sampled on rising edge of bck and data is output on wsl change and rising edge of bck
// so the output of the left channel is set on the 2nd call to PT8211. If the left channel is used call PT811_out 2 times with the same data
// The output voltage can be set between ~0.8V .. ~2.5V in 65536 steps

unsigned char pin_8211_din,pin_8211_bck,pin_8211_ws;

void PT8211_out(unsigned int LRanalog)
{
  int i;


  // convert to 'strange' 2-complement used by pt8211
  LRanalog -= 0x80008000;
  for(i=0;i<32;i++)
  {
    if(i == 16)
      digitalWrite(pin_8211_ws, 1);

    digitalWrite(pin_8211_din, (LRanalog&0x80000000)?1:0);
    digitalWrite(pin_8211_bck, 1);
    digitalWrite(pin_8211_bck, 0);
    LRanalog <<= 1;
  }
  digitalWrite(pin_8211_ws, 0);
}

void PT8211_init(char Dpin_din,char Dpin_bck,char Dpin_ws)
{
  pin_8211_din = Dpin_din;
  pin_8211_bck = Dpin_bck;
  pin_8211_ws = Dpin_ws;
  pinMode(pin_8211_din,OUTPUT);
  pinMode(pin_8211_bck,OUTPUT);
  pinMode(pin_8211_ws,OUTPUT);
  digitalWrite(pin_8211_din, 0);
  digitalWrite(pin_8211_bck, 0);
  digitalWrite(pin_8211_ws, 0);
  PT8211_out(0);
  PT8211_out(0);
}
