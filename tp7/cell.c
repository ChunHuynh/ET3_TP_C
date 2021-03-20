#include <stdio.h>
#include "cell.h"
#include <stdlib.h>

cell_t* cell_create(double x)
{
	cell_t* cel = (cell_t*) malloc(sizeof(cell_t));
	
	cel->val  = x;
	cel->next = NULL;

	return cel;
}


void cell_delete(cell_t* ptr)
{
	if(ptr)
	{ 
		cell_delete(ptr->next);
		free(ptr);
		ptr = NULL;
	}
}


void cell_link(cell_t* c1, cell_t* c2)
{
	c1->next = c2;
}


void cell_unlink(cell_t* c)
{
	c->next = NULL;
}
