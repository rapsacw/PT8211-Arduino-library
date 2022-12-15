#ifndef PT8211
#define PT8211

void PT8211_out(unsigned short left, unsigned short right);
void PT8211_init(char Dpin_din,char Dpin_bck,char Dpin_ws);

#endif