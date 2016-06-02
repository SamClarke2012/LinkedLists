/*
 *  zip.c
 *  
 *  2013 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

// Complete this function and submit this file ONLY
// for the prac exam.  Do not change the other supplied
// as you will not be submitting them.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "zip.h"

list createList(void);
void addToEnd(list l, link n);

void zip (list listA, list listB, list zipped) {

    link currA = listA->head;
    link currB = listB->head;
      

    while(currA != NULL || currB != NULL){
        
      //move first node left in A
      if(currA != NULL){
	  listA->head = currA->next;   
     
          currA->next = NULL;
          addToEnd(zipped,currA);
          currA = listA->head;
      }
     
      //move first node left in B
         
      if(currB != NULL){ 
          listB->head = currB->next;   
       
          currB->next = NULL;
          addToEnd(zipped,currB);
          currB  = listB->head;
      }

    }
 }


void addToEnd(list l, link n){
   link curr;
   if(l->head == NULL){
       l->head = n;
   } else {
       curr = l->head;
       while(curr->next != NULL){
            curr = curr->next;
       }
       curr->next = n;
   }
}

