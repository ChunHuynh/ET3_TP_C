#include <stdio.h>
#include "cell.h"
#include "list.h"

int main()
{
	// create a new cell c1
	cell_t* c1 = cell_create(1);
	
	printf("%f\n",c1->val);
	if(c1->next == NULL) printf("Created c1.\n");
	
	// create a new cell c2
	cell_t* c2 = cell_create(2);
	
	printf("%f\n",c2->val);
	if(c2->next == NULL) printf("Created c2.\n");
	
	
	// linking 2 cell
	cell_link(c1,c2);
	if(c1->next == c2) printf("Successfully linked.\n");
	
	
	
	// not forget to free
	cell_delete(c1);
	
	return 0;
}
