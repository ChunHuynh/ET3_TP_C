#include "utils.h"

void out_of_memory(const void* ptr, const char * message){
	if (ptr == NULL)
	{
		printf("Cannot allocate more memory : %s\n", message);
		exit(EXIT_FAILURE);
	}

}

int is_null(const void* str, const char* loc){
	if (str == NULL)
	{	
		printf("%s: NULL pointer\n", loc);
		return 1;
	}
	return 0;
}

// Simple utility function to print readable boolean values
void print_bool(const int b){
	if (b)
		printf("True\n");
	else
		printf("False\n");
}

