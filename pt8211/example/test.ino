
#include "pt8211.h"


void setup()
{

  unsigned short data = 0;
  long t;

  PT8211_init(8,4,5); // data,clk,ws
  // generate stepped sawtooth on both channels
  do
  {
    data += 0x1000;
    PT8211_out(data,data);
  } while(1);
}

void loop()
{
  
}
