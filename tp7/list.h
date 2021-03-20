#ifndef LIST_H
#define LIST_H

// structure list
typedef struct list_t
{
	cell_t* head;
}list_t;


list_t* list_create();


void list_delete(list_t* l);


int list_empty(list_t* l)


void list_push_front(list_t* l, cell_t* c);


void list_push_back(list_t* l, cell_t* c)

#endif
