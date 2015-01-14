#include <stddef.h>
#include <stdio.h>

#include "iterator.h"
#include "point.h"
#include "test.h"

DECLARE_ITERATOR( point_t )

int remove_test();
int init_test();
int create_test();
int destroy_test();

void main() {
	test( init );
	test( remove );
	test( create );
	test( destroy );
	printf("%s\n", "*** OK ***");
}

int init_test() {
	iterator_point_t it1, it2, it3, *it4_ptr = NULL;

	iter_init_point_t( &it1, NULL, NULL, point_factory( 1, 2, 3 ) );
	iter_init_point_t( &it2, &it1, NULL, point_factory( 4, 5, 6 ) );
	iter_init_point_t( &it3, &it2, NULL, point_factory( 7, 8, 9 ) );

	checkEq( it1.data.x, 1); checkEq( it1.data.y, 2); checkEq( it1.data.z, 3);
	checkEq( it1.prev, &it2 ); 
	checkEq( it2.next, &it1 );
	checkEq( it2.prev, &it3 );
	checkEq( it3.next, &it2 );

	iter_init_point_t( it4_ptr, NULL, NULL, point_factory( 0, 0, 0 ) );

	it4_ptr = (iterator_point_t*) malloc( sizeof( iterator_point_t ) );
	iter_init_point_t( it4_ptr, &it3, &it1, point_factory( 10, 11, 12 ) );
	checkEq( it1.next, it4_ptr );
	checkEq( it4_ptr-> next, &it3 );
	checkEq( it4_ptr-> prev, &it1 );
	free( it4_ptr );

	return 1;
}

int remove_test() {
	iterator_point_t it1, it2, it3;

	iter_init_point_t( &it1, NULL, NULL, point_factory( 1, 2, 3 ) );
	iter_init_point_t( &it2, &it1, NULL, point_factory( 4, 5, 6 ) );
	iter_init_point_t( &it3, &it2, NULL, point_factory( 7, 8, 9 ) );

	iter_remove_point_t( NULL );

	iter_remove_point_t( &it2 );
	checkEq( it2.next, NULL );
	checkEq( it2.prev, NULL );
	checkEq( it2.data.x, 0 );
	checkEq( it2.data.y, 0 );
	checkEq( it2.data.z, 0 );
	checkEq( it1.prev, &it3 );
	checkEq( it3.next, &it1 );

	return 1;
}

int create_test() {
	iterator_point_t it1, *it2_ptr = NULL, it3;

	iter_init_point_t( &it1, NULL, NULL, point_factory( 1, 2, 3 ) );
	it2_ptr = iter_create_point_t( &it1, NULL, point_factory ( 4, 5, 6 ) );
	iter_init_point_t( &it3, it2_ptr, NULL, point_factory( 7, 8, 9 ) );
	checkNoNull( it2_ptr );
	checkEq( it1.prev, it2_ptr );
	checkEq( it3.next, it2_ptr );
	checkEq( it2_ptr-> data.x, 4 ); 
	checkEq( it2_ptr-> data.y, 5 ); 
	checkEq( it2_ptr-> data.z, 6 );
	checkEq( it2_ptr-> next, &it1 );
	checkEq( it2_ptr-> prev, &it3 );
	free( it2_ptr );

	return 1;
}

int destroy_test() {
	iterator_point_t it1, *it2_ptr = NULL, it3;

	iter_destroy_point_t( NULL );
	iter_destroy_point_t( &it2_ptr );

	iter_init_point_t( &it1, NULL, NULL, point_factory( 1, 2, 3 ) );
	it2_ptr = (iterator_point_t*) malloc( sizeof( iterator_point_t ) );
	it2_ptr-> data = point_factory( 4, 5, 6 );
	it2_ptr-> next = &it1;
	iter_init_point_t( &it3, it2_ptr, NULL, point_factory( 7, 8, 9 ) );
	iter_destroy_point_t( &it2_ptr );
	checkNull( it2_ptr );
	checkEq( it1.prev, &it3 );
	checkEq( it3.next, &it1 );

	return 1;
}