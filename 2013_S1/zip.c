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

#define TRUE  1
#define FALSE 0

list zip (list listA, list listB) {
    int first = TRUE;
    // List pointers
    list l1 = listA;
    list l2 = listB;
    list l3 = NULL;
    // Temp pointers
    list t1 = NULL;
    list t2 = NULL;
    list t3 = NULL;
    while(l1 != NULL){
        // Point temps to next
        t1 = l1->rest;
        t2 = l2->rest;
        // Point head of l1 to head of l2
        l1->rest = l2;
        if(first){   
            first = FALSE;
            // Point t3 to l2
            t3 = l2;
            // Terminate new list with NULL
            l2->rest = NULL;
            // Point l3 to new head
            l3 = l1;
        } else {
            // Append l3 with the two new nodes
            l2->rest = t3->rest;
            t3->rest = l1;
            t3 = l2;
        }
        l1 = t1;
        l2 = t2;
    }
    return l3;
}
