#include <stdio.h>

int main() {
  unsigned char i;
  for(i=0x01;i<=0x64;i++) {
    if      (!(i%0x0F)) printf("FIZZBUZZ\n");
    else if (!(i%0x03)) printf("FIZZ\n");
    else if (!(i%0x05)) printf("BUZZ\n");
    else                printf("%i\n",i);
  } return 0;
}
