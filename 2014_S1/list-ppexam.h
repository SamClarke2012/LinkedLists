
typedef struct _node *link;    // a link points ot a node

typedef struct _node {
	int value;
	link next;
} node;

// a list is represented by a pointer to a struct containing 
// a pointer to the first node in it
typedef struct _list {
    link head;
} *list;     

void orderedDelete (list l);
