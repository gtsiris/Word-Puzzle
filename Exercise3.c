/* File: Exercise3.c */
#include <stdio.h>
#include <string.h>
#define OK 0
#define ERROR -1

void swap(char *x, char *y);
void permute(char *array, int sart_index, int stop_index, char *arg1, char *arg2, char *arg3, int *cntr);
int arg2int(char *argument, char *encoding);


int main(int argc, char *argv[]) {
  int i, j, different_letters = 0, word1_length, word2_length, word3_length, cntr = 0;
  char letter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  if (argc != 6 || strcmp(argv[2], "+") || strcmp(argv[4], "=")) {
    printf("Not supported option, try something in this form: ./program WORD1 + WORD2 = WORD3\n");
    return ERROR;
  }
  /*
  word1_length = strlen(argv[1]);
  word2_length = strlen(argv[3]);
  word3_length = strlen(argv[5]);
  if (word3_length < word1_length || word3_length < word2_length || word3_length > word1_length + 1 || word1_length > word2_length + 1) {
    printf("Given puzzle cannot be solved. \n");
    return ERROR;
  }
  */
  
  for (i = 0; argv[1][i] != '\0'; i++) {
    different_letters++;
    for(j = 0; j <= 9; j++) {
      if (argv[1][i] == letter[j]) {
        different_letters--;
        break;
      }
    }
    if (different_letters > 10) {
      printf("Only 10 different letters can be represented by one decimal digit.\n");
      return ERROR;
    }
    letter[different_letters - 1] = argv[1][i];
  }
  
  for (i = 0; argv[3][i] != '\0'; i++) {
    different_letters++;
    for(j = 0; j <= 9; j++) {
      if (argv[3][i] == letter[j]) {
        different_letters--;
        break;
      }
    }
    if (different_letters > 10) {
      printf("Only 10 different letters can be represented by one decimal digit.\n");
      return ERROR;
    }
    letter[different_letters - 1] = argv[3][i];
  }
  
  for (i = 0; argv[5][i] != '\0'; i++) {
    different_letters++;
    for(j = 0; j <= 9; j++) {
      if (argv[5][i] == letter[j]) {
        different_letters--;
        break;
      }
    }
    if (different_letters > 10) {
      printf("Only 10 different letters can be represented by one decimal digit.\n");
      return ERROR;
    }
    letter[different_letters - 1] = argv[5][i];
  }
  /*
  for (i=0; i<=9; i++) {
    printf("%c, ", letter[i]);
  }
  printf("different_letters = %d\n", different_letters);
  */
  
  //permute(letter, 0, different_letters-1, argv[1], argv[3], argv[5], &cntr);
  letter[0] = 'O';
  letter[1] = 'M';
  letter[2] = 'Y';
  letter[3] = 0;
  letter[4] = 0;
  letter[5] = 'E';
  letter[6] = 'N';
  letter[7] = 'D';
  letter[8] = 'R';
  letter[9] = 'S';
  permute(letter, 0, 9, argv[1], argv[3], argv[5], &cntr);
  return OK;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r, char *arg1, char *arg2, char *arg3, int *cntr)
{
  int i, var1, var2, var3, x;
   
  if (l == r)
  {
   //printf("%s\n", a);
    
    
    var1 = arg2int(arg1, a);
    var2 = arg2int(arg2, a);
    var3 = arg2int(arg3, a);
     
     /*
     //if (a[0] == 'O' && a[1] == 'M' && a[2] == 'Y' && a[5] == 'E' && a[6] == 'N' && a[7] == 'D' && a[8] == 'R' && a[9] == 'S')
     {
       putchar('\n');
       for (x = 0; x <= 9; x++)
       {
         if (a[x])
          printf("%c = %d, ", a[x], x);
       }
       printf("try = %d", *cntr);
     }
     */
       
     if (var1 + var2 == var3)     // If solution is found
     {
       for (x = 0; x <= 9; x++)
       {
         if (a[x])
          printf("%c = %d, ", a[x], x);
       }
       printf("try number = %d\n", (*cntr));
       printf ("%d + %d = %d\n\n", var1, var2, var3);
       return;
     }
     (*cntr)++;
     
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r, arg1, arg2, arg3, cntr);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

int arg2int(char *word, char *encoding)
{
  int i, result = 0;
  
  while (*word)
  {
    for (i = 0; i <= 9; i++)
    {
      if (*word == *(encoding + i))
      {
        result *= 10;
        result += i;
        break;
      }
      else if (i == 9)
      {
        printf("Oops!!! Something went wrong...\n");
        return -1;
      }
    }
    word++;
  }
  
  return result;
}

