/*
 *  zip.h
 *
 *  2013s1 Practice Prac Exam #3
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 */

typedef struct _list *list;
typedef struct _node *link;

typedef struct _node {
   int value;
   link next;
} node;

struct _list {
   link head;
} ;

//MODIFIED VERSION OF ZIP

// given two length list of nodes listA and listB,
// this function "zips" them together into a single
// list - which it returns.   The first node of listA is
// the first node of the output list, and the first node
// listB is the second node of the output list, and the
// second node of listA is the third node of the output
// list, and so on up ubtil the last node of listB which
// is the last node of the output list.
// So zipping A,B,C,D and a,b,c,d would give the list
// A,a,B,b,C,c,D,d
// note: You can NOT assume that the two input lists are of
// exactly the same length
// If one list is longer the extra nodes should be appended at the end
// of the new list.
// note: this function must not create new nodes or use malloc
// or change the value field of existing nodes.

void zip (list listA, list listB, list zipped);
