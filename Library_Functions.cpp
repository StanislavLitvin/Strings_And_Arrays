#include "TXLib.h"
#include <stdio.h>
#include <assert.h>

void Enter_String(char Str[]);
unsigned My_Strlen(const char Str[]);
int My_Puts(const char Str[]);
char *My_Strcpy(char Str_To[], const char Str_From[]);
char *My_Strcat(char Answer[], const char Str_First[], const char Str_Second[]);
int My_Strcmp(const char Str_First[], const char Str_Second[]);

unsigned My_Strlen(const char Str[])
{
  assert(Str);

  unsigned Count = 0;
  while (Str[Count] != '\0')
  {
    assert(Str[Count] != EOF);

    Count++;
  }

  return Count;
}

int My_Puts(const char Str[])
{
  assert(Str);

  unsigned Count = 0;
  while (Str[Count] != '\0')
  {
    assert(Str[Count] != EOF);

    putchar(Str[Count++]);
  }

  putchar('\n');

  return 0;
}

char *My_Strcpy(char Str_To[], const char Str_From[])
{
  assert(Str_To);
  assert(Str_From);

  unsigned Count = 0;

  while (Str_From[Count] != '\0')
  {
    assert(Str_From[Count] != EOF);
    assert(Str_To[Count] != EOF);

    Str_To[Count] = Str_From[Count];
    Count++;
  }

  Str_To[Count] = '\0';

  return Str_To;
}

char *My_Strcat(char Answer[], const char Str_First[], const char Str_Second[])
{
  assert(Answer);
  assert(Str_First);
  assert(Str_Second);

  unsigned i = 0, k = 0;
  while (Str_First[i] != '\0')
  {
    assert(Str_First[i] != EOF);

    Answer[i] = Str_First[i];
    i++;
  }

  while (Str_Second[k] != '\0')
  {
    assert(Str_Second[k] != EOF);

    Answer[i] = Str_Second[k];
    k++;
    i++;
  }

  Answer[i] = '\0';
  
  return Answer;
}

int My_Strcmp(const char Str_First[], const char Str_Second[])
{
  assert(Str_First);
  assert(Str_Second);

  unsigned i = 0;
  for (; Str_First[i] == Str_Second[i]; i++)
    if (Str_First[i] == '\0')
      return 0;

  return (unsigned char)Str_First[i] - (unsigned char)Str_Second[i];
}

int main()
{
  char Str1[100] = {};
  char Str2[100] = {};
  char Str3[100] = {};
  char Str4[100] = {};

  printf("Enter first string\n");
  Enter_String(Str1);

  printf("Enter second string\n");
  Enter_String(Str2);

  printf("Lengh first string = %u\n", My_Strlen(Str1));
  printf("Lengh second string = %u\n", My_Strlen(Str2));

  My_Puts(Str1);
  My_Puts(Str2);

  printf("\nString 3\n");
  My_Strcpy(Str3, Str2);
  My_Puts(Str3);

  printf("\nString 4\n");
  My_Strcat(Str4, Str1, Str2);
  My_Puts(Str4);

  printf("Eq = %d\n", My_Strcmp(Str1, Str2));

  return 0;
}

void Enter_String(char Str[])
{
  assert(Str);

  unsigned int i = 0;
  int Symbol = 0;
  
  while ((Symbol = getchar()) != '\n' && Symbol != EOF)
  {
    Str[i++] = (char)Symbol;
  }

  Str[i] = '\0';
}