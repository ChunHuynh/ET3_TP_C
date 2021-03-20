#include <stdio.h>
#include "list.h"
#include <stdlib.h>

list_t* list_create()
{
	list_t* list = (list_t*) malloc(sizeof(list_t));
	list->head = NULL;
	
	return list;
}


void list_delete(list_t* l)
{
	if(l)
	{
		free(l);
		l = NULL;
	}
}


int list_empty(list_t* l)
{
	if(l->head == NULL) return 1;
	else return 0;
}


void list_push_front(list_t* l, cell_t* c)
{
	if(list_empty(l) == 1)
		l->head = c;
	else
	{
		c->next = l->head;
		l->head = c;
	}
}


void list_push_back(list_t* l, cell_t* c)
{
	if(l){
		if(!list_empty(l))
		{
			cell_t* curr = l->head;
			while(curr && curr->next)
				curr = curr->next;
			cell_link(curr,c);
		}
	else
		l->head = c;
	}
}
