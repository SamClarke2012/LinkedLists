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


void zip (list listA, list listB, list zipped) {
    link p1;
    link p2;
    // Go ahead and point to the head of A
    zipped->head = listA->head;
    // Keep a pointer to it
    link p3 = zipped->head;
    // If there's work to be done
    if(listA->head != NULL){
        // Setup pointers
        p1 = listA->head->next;
        p2 = listB->head;
        // While there's stuff in either
        while(p1 != NULL || p2 != NULL){
            // We've already primed zipped
            // with listA, so start with listB
            if(p2 != NULL){
                // Append the node
                p3->next = p2;
                // Increment the pointers
                p2 = p2->next;
                p3 = p3->next;
            }
            // Then, same goes for listA
            if(p1 != NULL){
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }
        // Finish off the new list 
        // with a NULL pointer.
        p3->next = NULL;
    }

}
