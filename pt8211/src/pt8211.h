#ifndef PT8211
#define PT8211
#include <Arduino.h>
void PT8211_out(unsigned int LRanalog);
void PT8211_init(char Dpin_din,char Dpin_bck,char Dpin_ws);

#endif