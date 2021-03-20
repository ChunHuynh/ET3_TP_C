#ifndef CELL_H
#define CELL_H

// structure cell
typedef struct cell
{
	double  val;
	struct cell* next;
}cell_t;


cell_t* cell_create(double x);


void cell_delete(cell_t* ptr);


void cell_link(cell_t* c1, cell_t* c2);


void cell_unlink(cell_t* c);

#endif
