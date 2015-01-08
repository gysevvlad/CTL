#include <stddef.h>
#include <stdio.h>

#include "iterator.h"
#include "point.h"

DECLARE_ITERATOR( point_t )

DECLARE_ITERATOR( point_ptr )

void test_iter_point_t(); 
void test_iter_point_ptr();

void main() {
	test_iter_point_t();
	test_iter_point_ptr();
	printf("***   OK!   ***\n");
}

void test_iter_point_ptr() {
	iterator_point_ptr *iter1 = NULL,  *iter2 = NULL, *iter3 = NULL,
					it, it1, it2, it3;

	#define iter_create_p iter_create_point_ptr
	#define iter_destroy_p iter_destroy_point_ptr
	#define iter_factory_p iter_factory_point_ptr
	#define iter_init_p iter_init_point_ptr
	#define iter_remove_p iter_remove_point_ptr

	iter1 = iter_create_p( NULL, NULL, point_create( 1, 2, 3));
	iter2 = iter_create_p( iter1, NULL, point_create( 4, 5, 6));
	iter3 = iter_create_p( iter2, NULL, point_create( 7, 8, 9));

	if ( iter1 == NULL || iter1-> data-> x != 1 ||
		iter1-> data-> y != 2 || iter1-> data-> z != 3 ||
		iter2-> next != iter1 ||
		iter2-> prev != iter3 ||
		iter1-> prev != iter2 ||
		iter3-> next != iter2) {
		printf ( "Error: iter_create.\n" );
		exit(-1);		
	}

	point_destroy( &iter2-> data );
	iter_destroy_p( &iter2 );

	if ( iter2 != NULL || 
		iter1-> prev != iter3 || iter3-> next != iter1 ) {
		printf ( "Error: iter_destroy.\n" );
		exit(-1);			
	}

	it = iter_factory_p( NULL, NULL, point_create( 1, 2, 3));

	if (it.data-> x != 1 || it.data-> y != 2 || it.data-> z != 3) {
		printf ( "Error: iter_factory.\n" );
		exit(-1);
	}

	iter_init_p( &it1, NULL, NULL, point_create( 1, 2, 3 ));
	iter_init_p( &it2, &it1, NULL, point_create( 1, 2, 3 ));
	iter_init_p( &it3, &it2, NULL, point_create( 1, 2, 3 ));

	if ( it1.data-> x != 1 || it1.data-> y != 2 || it1.data-> z != 3 ||
		it2.next != &it1 ||
		it2.prev != &it3 ||
		it1.prev != &it2 ||
		it3.next != &it2) {
		printf ( "Error: iter_init.\n" );
		exit(-1);	
	}

	point_destroy( &it2.data );
	iter_remove_p( &it2 );

	if ( it3.next != &it1 || it1.prev != &it3 ) {
		printf ( "Error: iter_remove.\n" );
		exit(-1);		
	}

	point_destroy( &iter1-> data );
	point_destroy( &iter3-> data );
	point_destroy( &it1.data );
	point_destroy( &it3.data );
	iter_destroy_p( &iter1 );
	iter_destroy_p( &iter3 );
}

void test_iter_point_t() {
	iterator_point_t *iter1 = NULL,  *iter2 = NULL, *iter3 = NULL,
					it, it1, it2, it3;

	#define iter_create iter_create_point_t
	#define iter_destroy iter_destroy_point_t
	#define iter_factory iter_factory_point_t
	#define iter_init iter_init_point_t
	#define iter_remove iter_remove_point_t

	iter1 = iter_create( NULL, NULL, point_factory( 1, 2, 3));
	iter2 = iter_create( iter1, NULL, point_factory( 4, 5, 6));
	iter3 = iter_create( iter2, NULL, point_factory( 7, 8, 9));

	if ( iter1 == NULL || iter1-> data.x != 1 ||
		iter1-> data.y != 2 || iter1-> data.z != 3 ||
		iter2-> next != iter1 ||
		iter2-> prev != iter3 ||
		iter1-> prev != iter2 ||
		iter3-> next != iter2) {
		printf ( "Error: iter_create.\n" );
		exit(-1);		
	}
	
	iter_destroy( &iter2 );

	if ( iter2 != NULL || 
		iter1-> prev != iter3 || iter3-> next != iter1 ) {
		printf ( "Error: iter_destroy.\n" );
		exit(-1);			
	}

	it = iter_factory( NULL, NULL, point_factory( 1, 2, 3));

	if (it.data.x != 1 || it.data.y != 2 || it.data.z != 3) {
		printf ( "Error: iter_factory.\n" );
		exit(-1);
	}

	iter_init( &it1, NULL, NULL, point_factory( 1, 2, 3));
	iter_init( &it2, &it1, NULL, point_factory( 1, 2, 3));
	iter_init( &it3, &it2, NULL, point_factory( 1, 2, 3));

	if ( it1.data.x != 1 || it1.data.y != 2 || it1.data.z != 3 ||
		it2.next != &it1 ||
		it2.prev != &it3 ||
		it1.prev != &it2 ||
		it3.next != &it2) {
		printf ( "Error: iter_init.\n" );
		exit(-1);	
	}

	iter_remove( &it2 );

	if ( it3.next != &it1 || it1.prev != &it3 ) {
		printf ( "Error: iter_remove.\n" );
		exit(-1);		
	}

	iter_destroy( &iter1 );
	iter_destroy( &iter3 );
}

