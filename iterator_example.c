#include <stddef.h>
#include <stdio.h>

#include "iterator.h"
#include "point.h"

DECLARE_ITERATOR( point_t )

void iter_printf( iterator_point_t*, size_t );

void main() {
	iterator_point_t *iter1, *iter2, *iter3, *temp;
	size_t k;

	#define iter_create iter_create_point_t
	#define iter_destroy iter_destroy_point_t

	iter1 = iter_create( NULL, NULL, point_factory( 1, 2, 3));
	iter2 = iter_create( iter1, NULL, point_factory( 4, 5, 6));
	iter3 = iter_create( iter2, NULL, point_factory( 7, 8, 9));

	temp = iter3, k = 1;
	while( temp != NULL ) {
		iter_printf( temp, k );
		k++, temp = temp-> next;
	}
	printf("\n\n-> DESTROY iter2\n" );
	iter_destroy( &iter2 );
	printf("iter2: %p\n\n", iter2 );

	temp = iter3, k = 1;
	while( temp != NULL ) {
		iter_printf( temp, k );
		k++, temp = temp-> next;
	}

	iter_destroy( &iter1 );
	iter_destroy( &iter2 );
}

void iter_printf( iterator_point_t* iter, size_t k) {
	printf("\n_______________________\n");
	printf("iter%d: %p\n", k, iter);
	printf("next: %p\n", iter-> next);
	printf("prev: %p\n", iter-> prev);
	printf("data: ", iter-> prev);
	point_printf( &iter-> data);
}