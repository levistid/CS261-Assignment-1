/*
 * In this file, you should implement an application that compares the
 * performance of a dynamic array and a linked list, as described in the
 * README. Don't forget to include your name and @oregonstate.edu email
 * address below.
 *
 * Name: Levi Stidham
 * Email: stidhaml@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"
#include "list.h"
#include "time.h"

#define TEST_DATA_SIZE 1000000

/*
 * This function generates and an array of random integers of size n.
 */
int* generate_random_array(int n) {
  int* arr = malloc(n * sizeof(int));
  int i;

  for (i = 0; i < n; i++) {
    arr[i] = rand();
  }

  return arr;
}

int main(int argc, char const *argv[]) {
  int* test_data = generate_random_array(TEST_DATA_SIZE);
  
  
  
  struct dynarray* new_array=dynarray_create();
  struct list* new_list = list_create();

  clock_t timer_start_array = clock();
  double max_array_time = 0.0;
  for ( int i = 0; i < TEST_DATA_SIZE; i++)
  {
    clock_t timer_start = clock();
    dynarray_insert(new_array, &test_data[i]);
    clock_t timer_stop = clock();
    double aggregate_time = (timer_stop - timer_start) / CLOCKS_PER_SEC;
    max_array_time = aggregate_time;
  }
  clock_t stop_timer_array = clock();
  double total_time = (stop_timer_array - timer_start_array)/ CLOCKS_PER_SEC;

  printf("Total dynamic array time: %f sec \n", total_time);
  printf("Element insert dynamic array: %f sec \n", max_array_time);

  clock_t timer_list_start = clock();
  double max_list_time = 0.0;
  for (int i = 0; i < TEST_DATA_SIZE; i++)
  {
    clock_t timer_start = clock();
    list_insert(new_list, &test_data[i]);
    clock_t timer_stop = clock();
    double aggregate_time = (timer_stop - timer_start) / CLOCKS_PER_SEC;
    while(aggregate_time > max_list_time){
       max_list_time = aggregate_time;
       }
  }

  clock_t timer_list_stop = clock();
  double total_list_time = (timer_list_stop - timer_list_start)/ CLOCKS_PER_SEC;

  printf("Total linked list time: %f sec \n", total_list_time);
  printf("Element insert linked list: %f sec \n", max_list_time);
  
  
/*
   * You should write code here to insert the data in test_data into a
   * dynamic array using the dynamic array interface you implemented.  As
   * you're doing this, measure two things:
   *   1. The total amount of time it takes to insert all the data into the
   *      dynamic array.
   *   2. The maximum amount of time it takes to insert any single element into
   *      the dynamic array.
   * To help with this, you can use the C functions time() and difftime()
   * from time.h.  Don't forget to include time.h above!
   */
   /*
    * You should write code here to insert the data in test_data into a
    * linked list using the linked list interface you implemented.  As
    * you're doing this, measure two things:
    *   1. The total amount of time it takes to insert all the data into the
    *      linked list.
    *   2. The maximum amount of time it takes to insert any single element into
    *      the linked list.
    * Again, you can use the C functions time() and difftime() from time.h to
    * help with this.
    *
    * How do the times associated with the dynamic array compare to the times
    * associated with the linked list?  How does this change if you modify the
    * value of TEST_DATA_SIZE above?
    * 
    * answer: The linked list is faster for smaller sized data, but when working with 1 million
    * or more elements, the dynamic array times are faster
    */

   free(test_data);
   list_free(new_list);
   dynarray_free(new_array);
    

  return 0;
}