#include <stdio.h>

int main() {
  char i;
  for(i=0x01;i<=0x64;i++) {
    if      (!(i%0x0F)) puts("FIZZBUZZ");
    else if (!(i%0x03)) puts("FIZZ");
    else if (!(i%0x05)) puts("BUZZ");
    else                printf("%i\n",i);
  } return 0;
}
