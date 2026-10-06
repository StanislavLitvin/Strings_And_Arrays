#include <stdio.h>
#include "TXLib.h"

void Print_YX_Matrix(int data[], size_t Size_y, size_t Size_x);

int main()
{
  const size_t Size_y = 5, Size_x = 4;

  int data[Size_y][Size_x] = { {10, 11, 12, 13},
                               {20, 21, 22, 23},
                               {30, 31, 32, 33},
                               {40, 41, 42, 43},
                               {50, 51, 52, 53} };

  Print_YX_Matrix((int *)data, Size_y, Size_x);

  return 0;
}

void Print_YX_Matrix(int data[], size_t Size_y, size_t Size_x)
{
  for (unsigned y = 0; y < Size_y; y++)
  {
    for (unsigned x = 0; x < Size_x; x++)
      printf("%d ", data[y * Size_x + x]/**(data + y * Size_x + x)*/);
    
    printf("\n");
  }

  return;
}