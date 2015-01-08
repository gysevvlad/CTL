#include "point.h"

point_t* point_create(int x, int y, int z) {
	point_t *p; 
	p = (point_t*) malloc( sizeof( point_t ) );
	p-> x = x;
	p-> y = y;
	p-> z = z;
	return p;
}

void point_init( point_t *p, int x, int y, int z ) {
	p-> x = x;
	p-> y = y;
	p-> z = z;
}

void point_destroy( point_t **point ) {
	free( *point );
	*point = NULL;
}

void point_printf( point_t *p ) {
	printf( "(%d, %d, %d) ", p-> x, p-> y, p-> z);
}

point_t point_factory( int x, int y, int z ) {
	point_t p;
	p. x = x;
	p. y = y;
	p. z = z;
	return p;
}