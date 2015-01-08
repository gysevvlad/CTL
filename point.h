#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <malloc.h>

typedef struct {
	int x, y, z;
} point_t;

typedef point_t* point_ptr;

point_t* point_create(int x, int y, int z );

void point_init( point_t *point, int x, int y, int z );

void point_destroy( point_t **point );

void point_printf( point_t* point );

point_t point_factory( int x, int y, int z );

#endif