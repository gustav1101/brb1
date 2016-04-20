#include "DLLTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mergesort.h"


int main(int argc, char ** argv)
{
  int* numbers;
  int i;
  DLL* list;
//  DLL* sublist1, sublist2;
  
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

  list = malloc(sizeof(DLL));
  
  for(i = 0; i<argc-1; i++)
  {
      add(numbers[i], list);
  }


  free(numbers);


  
  divide(list);

  printf("\nAfter sorting:\n");
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


void testList(DLL* list)
{
    

  printList(list);

  reset(list);

  printf("Starting Value is %d\n",peek(list) );
  if (prev(list))
  {
      printf("Hier lief was falsch");
  }
  printf("Should still be at %d\n",peek(list));
  //clearList(list);

  next(list);
  printf("At next element we have %d\n", peek(list));

  prev(list);
  printf("Here we should have again the starting element: %d\n", peek(list));

  while(next(list));

  printf("Last element should be %d\n", peek(list));

  printf("The list contains %d Elements. True? I don't know!\n",list->size);

  prev(list);
  prev(list);
  add(55,list);

  printf("Now let's add something in the middle and see if that works.\n");
  printList(list);

  printf("And what about the first element?\n");
  reset(list);
  add(42,list);
  printList(list);

}
