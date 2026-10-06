#include <stdio.h>
#include <assert.h>

void Bubble_Sort(int Array[], size_t Length);
void Switch_Places(int *Value1, int *Value2);
void Print_Array(int Array[], size_t Length);

int main()
{
  int Array[] = {1, 5, 3, 7, 2, 8, 9, 4, 6, 0};
  size_t Length = sizeof(Array) / sizeof(Array[0]);

  Bubble_Sort(Array, Length);

  Print_Array(Array, Length);

  return 0;
}

void Bubble_Sort(int Array[], size_t Length)
{
  assert(Array);
  assert(Length > 0);

  for (size_t Pass_Number = 0; Pass_Number < Length - 1; Pass_Number++)
  {
    bool Already_Sorted = true;

    for (size_t Element_Number = 0; Element_Number < Length - 1 - Pass_Number; Element_Number++)
      if (Array[Element_Number] > Array[Element_Number + 1])
      {
        Switch_Places(Array + Element_Number, Array + Element_Number + 1);
        Already_Sorted = false;
      }

    if (Already_Sorted)
      break;
  }

  return;
}

void Switch_Places(int *Value1, int *Value2)
{
  assert(Value1);
  assert(Value2);

  int Temp = *Value1;
  *Value1 = *Value2;
  *Value2 = Temp;

  return;
}

void Print_Array(int Array[],  size_t Length)
{
  assert(Array);
  assert(Length > 0);

  for (size_t i = 0; i < Length; i++)
    printf("%d ", Array[i]);
  printf("\n");
  
  return;
}