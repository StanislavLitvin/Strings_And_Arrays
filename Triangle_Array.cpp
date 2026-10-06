/*#include "TXLib.h"
#include <stdio.h>

enum Error_Code { Error_Negative_X_Y    = -1,
                  Error_Y_Less_X        = -2,
                  Error_Index_Out_Range = -3 };

void Print_Triangle_Matrix(unsigned int Data[]);
void Get_Triangle_Array(unsigned int Data[]);
int Analyze_Index_Element(unsigned int Y, unsigned int X);

int main()
{
  unsigned int Y = 0, X = 0, Teams_Number = 0;

  scanf("%u", &Teams_Number);
  unsigned Size_Array = Teams_Number * (Teams_Number - 1) / 2;

  char Data[Size_Array] = { "2_1",
                           3_1, 3_2,
                           4_1, 4_2, 4_3,
                           5_1, 52, 53, 54,
                           6_1, 62, 63, 64, 65,
                           71, 72, 73, 74, 75, 76 }; // “олько через дин. пам€ть

  Get_Triangle_Array(Data);

  Print_Triangle_Matrix(Data);

  printf("Refer to the element (Y is vertical, X is horizontal)\n");
  printf("Y = ");
  scanf("%u", &Y); //ѕроблема ввода отрицательного числа (он воспринимает его как беззнаковое),
  printf("X = ");  //я не могу его отловить, т к оно сразу становитс€ положительным
  scanf("%u", &X);

  int Index_Element = Analyze_Index_Element(Y, X);
  if (Index_Element < 0)
  {
    return 1;
  }

  printf("\nData[Y][X] = %d", Data[Index_Element]);

  return 0;
}

void Print_Triangle_Matrix(int Data[])
{
  unsigned Count_Numbers_Right_Now = 0, Count_Numbers_Current_Line = 1;

  for (unsigned i = 0; i < SIZE_ARRAY; i++)
  {
    printf("%d ", Data[i]);
    Count_Numbers_Right_Now++;

    if (Count_Numbers_Right_Now == Count_Numbers_Current_Line)
    {
      printf("\n");
      Count_Numbers_Current_Line++;
      Count_Numbers_Right_Now = 0;
    }
  }

  return;
}

int Analyze_Index_Element(unsigned Y, unsigned X)
{
  if (Y < 0 || X < 0)
  {
    printf("You have entered incorrect Data (Y < 0 or X < 0)\n");
    return Error_Negative_X_Y;
  }

  else if (Y < X)
  {
    printf("You have entered incorrect Data (Y < X)\n");
    return Error_Y_Less_X;
  }
  
  else
  {
    size_t Index = X + (Y * (Y + 1)) / 2;
    if (Index >= SIZE_ARRAY)
    {
      printf("Array index out of range\n");
      return Error_Index_Out_Range;
    }
    
    return (int)Index;
  }
}*/



#include "TXLib.h"
#include <stdio.h>

const size_t SIZE_ARRAY = 21;

enum Error_Code { Error_Negative_X_Y    = -1,
                  Error_Y_Less_X        = -2,
                  Error_Index_Out_Range = -3 };

void Print_Triangle_Matrix(int Data[]);
int Analyze_Index_Element(unsigned Y, unsigned X);

int main()
{
  unsigned Y = 0, X = 0;
  
  int Data[SIZE_ARRAY] = { 10,
                           20, 21,
                           30, 31, 32,
                           40, 41, 42, 43,
                           50, 51, 52, 53, 54,
                           60, 61, 62, 63, 64, 65 };

  Print_Triangle_Matrix(Data);

  printf("Refer to the element (Y is vertical, X is horizontal)\n");
  printf("Y = ");
  scanf("%u", &Y); //ѕроблема ввода отрицательного числа (он воспринимает его как беззнаковое),
  printf("X = "); //я не могу его отловить, т к оно сразу становитс€ положительным (%d)
  scanf("%u", &X);

  int Index_Element = Analyze_Index_Element(Y, X);
  if (Index_Element < 0)
  {
    return 1;
  }

  printf("\nData[Y][X] = %d", Data[Index_Element]);

  return 0;
}

void Print_Triangle_Matrix(int Data[]) // руговой вывод одномерного массива (in the plans)
{
  unsigned Count_Numbers_Right_Now = 0, Count_Numbers_Current_Line = 1;

  for (unsigned i = 0; i < SIZE_ARRAY; i++)
  {
    printf("%d ", Data[i]);
    Count_Numbers_Right_Now++;

    if (Count_Numbers_Right_Now == Count_Numbers_Current_Line)
    {
      printf("\n");
      Count_Numbers_Current_Line++;
      Count_Numbers_Right_Now = 0;
    }
  }

  return;
}

int Analyze_Index_Element(unsigned Y, unsigned X)
{
  if (Y < 0 || X < 0)
  {
    printf("You have entered incorrect Data (Y < 0 or X < 0)\n");
    return Error_Negative_X_Y;
  }

  else if (Y < X)
  {
    printf("You have entered incorrect Data (Y < X)\n");
    return Error_Y_Less_X;
  }
  
  else
  {
    size_t Index = X + (Y * (Y + 1)) / 2;
    if (Index >= SIZE_ARRAY)
    {
      printf("Array index out of range\n");
      return Error_Index_Out_Range;
    }
    
    return (int)Index;
  }
}