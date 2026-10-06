#include <stdio.h>
#include <assert.h>
#include <stdlib.h> //Стандартная qsort

void Bubble_Sort(void *Array, size_t Length, size_t Size_Elem,
                 int (*Compare_Function)(const void *Number1, const void *Number2));
void Switch_Places(void *Value1, void *Value2, size_t Size_Elem);
void Print_Array(int Array[], size_t Length);
int Compare_Up(const void *Number1, const void *Number2);
int Compare_Down(const void *Number1, const void *Number2);

int main()
{
  int Array[] = {1, 5, 3, 7, 2, 8, 9, 4, 6, 0};
  size_t Length = sizeof(Array) / sizeof(Array[0]);

  //Bubble_Sort(Array, Length, sizeof(Array[0]), &Compare_Up);

  qsort(Array, Length, sizeof(Array[0]), &Compare_Down); //Проверка компаратора в qsort

  Print_Array(Array, Length);

  return 0;
}

void Bubble_Sort(void *Array, size_t Length, size_t Size_Elem,
                 int (*Compare_Function)(const void *Number1, const void *Number2))
{
  assert(Array);
  assert(Length > 0);
  assert(Size_Elem > 0);

  void *Elem1 = NULL, *Elem2 = NULL;

  for (size_t Pass_Number = 0; Pass_Number < Length - 1; Pass_Number++)
  {
    bool Already_Sorted = true;

    for (size_t Element_Number = 0; Element_Number < Length - 1 - Pass_Number; Element_Number++)
    {
      Elem1 = (void *)((size_t)Array + Element_Number * Size_Elem);
      Elem2 = (void *)((size_t)Array + (Element_Number + 1) * Size_Elem);

      if ((*Compare_Function)(Elem1, Elem2) > 0)
      {
        Switch_Places(Elem1, Elem2, Size_Elem);

        Already_Sorted = false;
      }
    }

    if (Already_Sorted)
      break;
  }

  return;
}

void Switch_Places(void *Value1, void *Value2, size_t Size_Elem)
{
  assert(Value1);
  assert(Value2);
  assert(Size_Elem > 0);

  char Temp = 0;
  for (size_t i = 0; i < Size_Elem; i++)
  {
    Temp = *(char *)((size_t)Value1 + i);
    *(char *)((size_t)Value1 + i) = *(char *)((size_t)Value2 + i);
    *(char *)((size_t)Value2 + i) = Temp;
  }

  return;
}

void Print_Array(int Array[], size_t Length)
{
  assert(Array);
  assert(Length > 0);

  for (size_t i = 0; i < Length; i++)
    printf("%d ", Array[i]);
  printf("\n");
  
  return;
}

int Compare_Up(const void *Number1, const void *Number2)
{
  assert(Number1);
  assert(Number2);

  const int Value_Number1 = *(const int *)Number1;
  const int Value_Number2 = *(const int *)Number2;

  return (Value_Number1 - Value_Number2);
}

int Compare_Down(const void *Number1, const void *Number2)
{
  assert(Number1);
  assert(Number2);
  
  const int Value_Number1 = *(const int *)Number1;
  const int Value_Number2 = *(const int *)Number2;

  return (Value_Number2 - Value_Number1);
}
