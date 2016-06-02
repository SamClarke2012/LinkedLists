// partition.c
// gcc -Wall -Werror -std=c99 -O -o testPartition testPartition.c partition.c

//OR for gdb debugging use
// gcc -Wall -Werror -std=c99 -gdwarf-2 -o testPartition testPartition.c partition.c
     
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "list-partition.h"
     
// given a list of integers and an integer key, write a function which 
// finds all the integers in the list that are smaller than the firstInsert element 
// and moves them to the beginning of the list. 

// So if the original list is        10->55->66->4->X, 
// the list should be modified to be  4->10->55->66->X

// If the original list is 10->4->1->X
// the list should be modified to be 4->1->10->X

// If the original list is    10->55->3->9->10->89->1->11->X, 
// the modified list would be 3->9->1->10->55->10->89->11->X

// If the original list is empty it should remain unmodified

// Constraints:
// don't delete any nodes (i.e. do not call free())
// don't create any new structs (i.e. do not call malloc())
// the nodes that are smaller and moved to the front should remain in their original relative order
// the nodes that are greater than or equal should remain in their original relative order

#define TRUE 1
#define FALSE 0

void partition (list sourceList) {
    // First insert
    int firstInsert = TRUE;
    // If it's not an empty list
    if(sourceList->head != NULL){
        // Some pointers
        link prev = sourceList->head;
        link lastInsert = sourceList->head;
        link ptr  = sourceList->head->next;
        // Head value as trigger point
        int triggerVal = prev->value;
        while( ptr != NULL ){
            // If the value is less
            if( ptr->value < triggerVal ){
                // Point the prev node to the next node
                prev->next = ptr->next;
                // If this is the fist movement
                if( firstInsert ){
                    // Update flag
                    firstInsert = FALSE;
                    // Insert before head
                    ptr->next = lastInsert;
                    sourceList->head = ptr;
                    // Update lastInsert
                    lastInsert = ptr;
                    // Move ptr back and move on
                    ptr = prev->next;
                } else {
                    // Insert node after lastInsert
                    ptr->next = lastInsert->next;
                    lastInsert->next = ptr;
                    // Update lastInsert
                    lastInsert = lastInsert->next;
                    // Move ptr back and move on
                    ptr = prev->next;
                }
            } else {
                // Value is larger, step fwd
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
}
