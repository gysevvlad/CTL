#include "test.h"
#include "pair.h"
#include "point.h"

DECLARE_PAIR( int, point_t )

int init_test();
int create_test();
int factory_test();
int destroy_test();

int main() {
	test( init );
	test( create );
	test( factory );
	test( destroy );
}

int init_test() {
	pair_int_point_t pair, *pair_ptr = NULL;

	pair_init_int_point_t( &pair, 1, point_factory( 1, 2, 3) );
	if ( pair.key != 1 || pair.data.x != 1 ||
		pair.data.y != 2 || pair.data.z != 3)
		return 0;

	pair_init_int_point_t ( pair_ptr, 1, point_factory( 1, 2, 3) );

	pair_ptr = (pair_int_point_t*) malloc ( sizeof ( pair_int_point_t ) );
	pair_init_int_point_t ( pair_ptr, 1, point_factory( 1, 2, 3) );
	if ( pair_ptr-> key != 1 || pair_ptr-> data.x != 1 ||
		pair_ptr-> data.y != 2 || pair_ptr-> data.z != 3)
		return 0;
	free( pair_ptr );

	return 1;
}

int create_test() {
	pair_int_point_t *pair_ptr = NULL;

	pair_ptr = pair_create_int_point_t( 1, point_factory( 1, 2, 3) );
	checkNoNull( pair_ptr );
	if ( pair_ptr-> key != 1 || pair_ptr-> data.x != 1 ||
		pair_ptr-> data.y != 2 || pair_ptr-> data.z != 3)
		return 0;

	return 1;
}

int factory_test() {
	pair_int_point_t pair;

	pair = pair_factory_int_point_t( 1, point_factory( 1, 2, 3 ) );
	if ( pair.key != 1 || pair.data.x != 1 ||
		pair.data.y != 2 || pair.data.z != 3)
		return 0;

	return 1;
}

int destroy_test() {
	pair_int_point_t *pair_ptr = NULL;

	pair_destroy_int_point_t( NULL );

	pair_destroy_int_point_t( &pair_ptr );
	checkNull( pair_ptr );

	pair_ptr = (pair_int_point_t*) malloc( sizeof ( pair_int_point_t ) );
	pair_destroy_int_point_t( &pair_ptr );
	checkNull( pair_ptr );

	return 1;
}