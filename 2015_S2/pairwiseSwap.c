// pairwiseSwap.c
// 
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list-ppexam.h"
 
// given a list of nodes, write a function to swap nodes pairwise.
// For example, if the linked list is 1->2->3->4->5->6->7->X then
// the function should change it to 2->1->4->3->6->5->7->X and
// if the linked list is 1->2->3->4->5->6->X then the function 
// should change it to 2->1->4->3->6->5->X
//
// Constraints:
// don't malloc any new nodes
// don't change the "value" field of any node, just change links
// don't delete any nodes (i.e. do not call free())
// 
// More Examples:
// Original list 1->X, after swap remains 1->X
// Original list 1->4->X, after swap 4->1->X
// Original list 3->6->7->X, after swap 6->3->7->X
// Original list 5->3->6->2->X, after swap 3->5->2->6->X 


// HINTS: 
// 1) Traverse the list and swap two nodes at a time,
// then proceed to the next pair. 
// 2) You may need to maintain pointers to three nodes during each 
// swap operation - the two nodes that are being swapped and the node 
// preeceding the pair (i.e. previous, current and next).

//function to determine length of a linked list

void pairwiseSwap (list l) {
    link t;
    link p1 = l->head;
    link p2 = l->head;
    link p3 = l->head;
    int counter = 0;
    // Through the list
    while(p1 != NULL){
        // If we have moved an odd amount
        if(counter%2 != 0){
            // Swap p1 and p2
            p2->next = p1->next;
            p1->next = p2;
            // If it's the first
            if(counter == 1){
                // Adjust the head
                l->head  = p1;
            } else {
                // Adjust the one before last
                p3->next = p1;
            }
            // Swap pointer back
            t = p2;
            p2 = p1;
            p1 = t;
            p3 = p2;
        }
        // Increment along list
        p3 = p2;
        p2 = p1;
        p1 = p1->next;
        counter++;
    }
}