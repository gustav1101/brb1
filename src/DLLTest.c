#include "DLLTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLL.h"

int main(int argc, char ** argv)
{
  int* numbers;
  int i;
  DLL* list;
  
  if( 1 == argc )
  {
    printf("Please enter integer arguments.\n");
    return 0;
  }

  numbers = parseInput(argc, argv);

  if (numbers == NULL)
  {
      return 1;
  }

  //printResults(numbers, argc-1);
  list = malloc(sizeof(DLL));
  
  for(i = 0; i<argc-1; i++)
  {
      add(numbers[i], list);
  }


  prev(list);
  add(5,list);
  free(numbers);

  printList(list);
  
  
  clearList(list);
  
  return 0;
}


int* parseInput(int argc, char**argv)
{
  int i;
  int* ret;
  int *val;

  ret = (int*) malloc( (argc-1) * sizeof(int));
  val = ret;
  
  for (i = 1; i < argc; i++)
  {
      if (sscanf(argv[i], "%d", val) == EOF)
      {
	  fprintf(stderr, "Incorrect value for parsing");
	  return NULL;
      }
      if(i+1<argc)
      {
	  val++;
      }
  }

  
  return ret;
}

void printResults(int* numbers, int limit)
{
  int i;
  int* iterator;

  iterator = numbers;
  printf("Result is");
  for(i = 0; i < limit; i++)
  {
    printf(" %d",iterator[i]);
  }
  printf(".\n");

  return;
}


int debug(int lim, char* str)
{
    return 0;
}
