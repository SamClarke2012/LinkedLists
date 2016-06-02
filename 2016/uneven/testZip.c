/*
 *  testZip.h
 *  
 *  2013 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 *  this program runs a simple test for interleaving
 *  "zipping" two lists of equal length into a single
 *  combined list, by changing pointers.
 *  The original lists should be 0 sized and their heads should 
 *  point to NULL by the end of the zip function. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "zip.h"

#define FIRST_A  0
#define SECOND_A 1
#define THIRD_A  2
#define FIRST_B  3
#define SECOND_B 4
#define THIRD_B  5

#define BIG_TEST_SIZE 10

void testZipNull (void);
void testZipSingletons (void);
void testZipTwo (void);
void testZip10 (void);
void testZipUneven (void);


list createList(void);

int main (int argc, char *argv[]) {
   printf ("Running unit tests on zip()...\n");
   testZipNull ();
   testZipSingletons ();
   testZipTwo ();
   testZip10 ();
   testZipUneven();
   printf ("All PRAC EXAM tests passed! You are AWESOME!\n");
   
   return EXIT_SUCCESS;
}


void testZipNull (void) {
   
   printf ("TEST 1 (Null): testing zip on two empty lists...\n");
   
   list zipped = createList();
   zip (createList(), createList(),zipped);
   assert (zipped->head == NULL);
   printf ("TEST 1 (null) passed!\n");
   
}

void testZipSingletons (void) {

   printf ("TEST 2 (singletons): testing zip on two single elt lists...\n");
   node nodeA0 = {FIRST_A, NULL};
   node nodeB0 = {FIRST_B, NULL};
   list listA = createList();
   listA->head = &nodeA0;
   list listB = createList();
   listB->head =  &nodeB0;
   

   list zipped = createList();
   zip (listA, listB,zipped);
   assert (zipped != NULL);
   assert (zipped->head != NULL);
   assert (zipped->head == &nodeA0);
   assert (zipped->head->value == FIRST_A);
   
   assert (zipped->head->next == &nodeB0);
   assert (zipped->head->next->value == FIRST_B);

   assert (zipped->head->next->next == NULL);
   printf ("TEST 2 (singletons) passed!\n");
   
}

void testZipTwo (void) {
   
   printf ("TEST 3 (twos): testing zip on two 2-element lists...\n");
   node nodeA1 = {SECOND_A, NULL};
   node nodeB1 = {SECOND_B, NULL};
   node nodeA0 = {FIRST_A, &nodeA1};
   node nodeB0 = {FIRST_B, &nodeB1};
   
   list listA = createList();
   listA->head = &nodeA0;
   list listB = createList();
   listB->head = &nodeB0;
   
   list zipped = createList();
   zip (listA, listB,zipped);
   assert (zipped != NULL);
   assert (zipped->head == &nodeA0);
   assert (zipped->head->value == FIRST_A);
   
   assert (zipped->head->next == &nodeB0);
   assert (zipped->head->next->value == FIRST_B);
   
   assert (zipped->head->next->next == &nodeA1);
   assert (zipped->head->next->next->value == SECOND_A);
   
   assert (zipped->head->next->next->next == &nodeB1);
   assert (zipped->head->next->next->next->value == SECOND_B);
   
   assert (zipped->head->next->next->next->next == NULL);
   printf ("TEST 3 (twos) passed!\n");
   
}

void testZip10 (void) {
   printf ("TEST 4 (10s): testing zip on two 10-element lists...\n");
   printf (" ... create the nodes\n");
   
   node nodes[BIG_TEST_SIZE*2];  // enough nodes for two lists
   
   // connect and put values 'A'..'J' in the first list
   // (first list is stored in even numbered nodes)   
   int place = 0;
   while (place<BIG_TEST_SIZE) {
      int location = place*2;
      nodes[location].value = place;
      if (place == (BIG_TEST_SIZE-1)) {
         // the final node has a null next pointer
         nodes[location].next = NULL;
      } else {
         // otherwise points to the node two places on
         // (as the list is of the even numbered nodes
         // so only contains every second node)
         nodes[location].next = &nodes[location+2];
      }
      place++;
   }
   
   // connect and put values 'a'..'j' in the second list
   // (second list is stored in odd numbered nodes)
   place = 0;
   while (place<BIG_TEST_SIZE) {
      int location = place*2 + 1;  //+1 for odd numbers
      nodes[location].value = place;
      if (place == (BIG_TEST_SIZE-1)) {
         // the final node has a null next pointer
         nodes[location].next = NULL;
      } else {
         // otherwise points to the node two places on
         // (as the list is of the even numbered nodes
         // so only contains every second node)
         nodes[location].next = &nodes[location+2];
      }
      place++;
   }
   
   
   printf (" ... call zip()\n");
   list listA = createList();
   listA->head = &nodes[0];
   list listB = createList();
   listB->head = &nodes[1];
    
   list zipped = createList();
   zip(listA, listB,zipped);
   printf (" ... test links are correct\n");
   assert (zipped->head == &nodes[0]);
   
   // all nodes should point to the next node
   int i = 0;
   while (i < (BIG_TEST_SIZE*2 - 1)) {
      assert (nodes[i].next == &nodes[i+1]);
      i++;
   }
   // final node terminated by NULL
   assert (nodes[BIG_TEST_SIZE*2 - 1].next == NULL);
   
   
   printf (" ... check that values have not been changed\n");
   printf ("Should be 00112233445566778899\n");
   printf ("        yours are \"");   
   i=0;
   while (i < BIG_TEST_SIZE*2) {
      printf ("%d", nodes[i].value);
      if ((i%2) == 0) {
         assert (nodes[i].value == (i/2));
      } else {
         assert (nodes[i].value == (i/2));
      }
      i++;
   }
   printf ("\"\n");
   printf ("TEST 4 (10s): passed!\n");
}

void testZipUneven (void) {
   
   printf ("TEST 5  testing zip on lists of different sizes...\n");
   
   node nodeB2 = {THIRD_B,NULL};
   node nodeB1 = {SECOND_B, &nodeB2};
   node nodeA0 = {FIRST_A, NULL};
   node nodeB0 = {FIRST_B, &nodeB1};
   
   list listA = createList();
   listA->head = &nodeA0;
   list listB = createList();
   listB->head = &nodeB0;
      
   list zipped = createList();
   zip (listA, listB,zipped);
   assert (zipped != NULL);
   assert (zipped->head == &nodeA0);
   assert (zipped->head->value == FIRST_A);
   
   assert (zipped->head->next == &nodeB0);
   assert (zipped->head->next->value == FIRST_B);
   
   assert (zipped->head->next->next == &nodeB1);
   assert (zipped->head->next->next->value == SECOND_B);
   
   assert (zipped->head->next->next->next == &nodeB2);
    
   assert (zipped->head->next->next->next->value == THIRD_B);
   assert (zipped->head->next->next->next->next == NULL);
   printf ("TEST 5 (unevens) passed!\n");
   
}

list createList(void){
    list newList = malloc(sizeof(struct _list));
    newList->head = NULL;
    return newList;
}
