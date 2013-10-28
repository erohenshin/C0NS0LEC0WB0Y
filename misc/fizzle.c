#include <stdio.h>

int main() {
	char f[] = {0x46,0x49,0x5A,0x5A,0x00};
	char b[] = {0x42,0x55,0x5A,0x5A,0x00};
  char i;
  for(i=0x01;i<=0x64;i++) {
    if      (!(i%0x0F)) printf("%s%s\n",f,b);
    else if (!(i%0x03)) puts(f);
    else if (!(i%0x05)) puts(b);
    else                printf("%i\n",i);
  } return 0;
}
