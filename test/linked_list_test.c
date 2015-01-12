
#include "linked_list.h"
#include "point.h"

DECLARE_LINKED_LIST( point_t )

#define test( func ) if ( func##_test() != 1 ) { printf("Error: %s\n", #func); exit(-1); } else printf("OK: %s\n", #func)
#define checkNull( field ) if ( field != NULL ) return -1
#define checkNoNull( field ) if ( field == NULL ) return -1

int init_test();
int create_test();
int destroy_test();

int main() {
	test( init );
	test( create );
	test( destroy );
}

int destroy_test() {
	linked_list_point_t *list_ptr = NULL;

	linked_list_destroy_point_t( NULL );
	linked_list_destroy_point_t( &list_ptr );

	list_ptr = linked_list_create_point_t();
	checkNoNull( list_ptr );

	linked_list_destroy_point_t( &list_ptr );
	checkNull( list_ptr );

	return 1;
}

int init_test() {
	linked_list_point_t list;
	linked_list_point_t *list_ptr = NULL;

	linked_list_init_point_t( &list );
	linked_list_init_point_t( list_ptr );

	checkNull( list.first );
	checkNull( list.last );

	return 1;
}

int create_test() {
	linked_list_point_t *list_ptr;

	list_ptr = linked_list_create_point_t();

	checkNoNull( list_ptr );
	checkNull( list_ptr->first );
	checkNull( list_ptr->last );

	return 1;

}