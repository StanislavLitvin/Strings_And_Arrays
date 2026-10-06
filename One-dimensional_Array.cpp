#include <stdio.h>
#include "TXLib.h"

int main()
{
  int data[5] = {10, 20, 30};
  printf("%d\n", data[2]);

  *(data + 2) = 31;
  printf("%d\n", *(data + 2));
  
  *(int *)((size_t)data + 3 * sizeof(*data)) = 40;
  printf("%d\n", *(int *)((size_t)data + 3 * sizeof(*data)));

  return 0;
}