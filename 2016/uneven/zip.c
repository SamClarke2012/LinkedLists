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
    zipped->head = listA->head;
    link p3 = zipped->head;
    if(listA->head != NULL){
        p1 = listA->head->next;
        p2 = listB->head;
        while(p1 != NULL || p2 != NULL){
            if(p2 != NULL){
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            if(p1 != NULL){
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }
        p3->next = NULL;
    }

}
