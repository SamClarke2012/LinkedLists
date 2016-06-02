/*
 *  reverseList.c
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "reverseList.h"

list reverse (list inputList) {
    // Pointer to input list
    list l1 = inputList;
    // Ponter to new list
    list l2 = NULL;
    // Temp pointer
    list t = l1;
    while(l1 != NULL ){
        // Point temp to input next
        t = l1->rest;
        // Point current l1 node to l2
        l1->rest = l2;
        // Point l2 to the new head
        l2 = l1;
        // Put l1 back to t
        l1 = t;
    }
    return l2;
}
