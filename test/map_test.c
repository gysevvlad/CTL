
#include "map.h"
#include "test.h"

DECLARE_MAP( int, int )

int pair_new_test();
int pair_destroy_test();
int init_test();
int pair_add_test();
int pair_find_test();
int pair_delete_test();

main() {
	test( pair_new );
	test( pair_destroy );
	test( init );
	test( pair_add );
	test( pair_find );
	test( pair_delete );
}

int pair_delete_test() {
	map_pair_int_int p1, *p2, p3, *p_ptr;
	map_int_int map;

	map_init_int_int( &map );
	p2 = map_pair_new_int_int();
	p1.key = p3.key = 0; p2-> key = 65537;
	p1.data = 1; p2-> data = 2; p3.data = 3;

	map_pair_add_int_int( &map, &p1 );	
	map_pair_add_int_int( &map, p2 );	
	map_pair_add_int_int( &map, &p3 );

	p_ptr = map_pair_find_int_int( &map, 65537 );
	checkEq( p_ptr-> next, &p1);
	checkEq( p_ptr-> prev, &p3);
	map_pair_delete_int_int ( p_ptr );
	checkEq( p3.next, &p1 );
	checkEq( p1.prev, &p3 );

	return 1;
}

int pair_find_test() {
	map_pair_int_int pair, pair2;
	map_int_int map;

	map_init_int_int( &map );
	pair.data = 23;
	pair.key = 0;
	pair2.data = 123;
	pair2.key = 65537;

	map_pair_add_int_int( &map, &pair );
	map_pair_add_int_int( &map, &pair2 );

	checkEq( map_pair_find_int_int( &map, 0 ), &pair );
	checkNull( map_pair_find_int_int( &map, 12) );

	return 1;
}

int pair_add_test() {
	map_pair_int_int pair, pair2;
	map_int_int map;

	map_init_int_int( &map );
	pair.data = 23;
	pair.key = 0;
	pair2.key = 65537;
	pair2.data = 123;

	map_pair_add_int_int( NULL, NULL );
	map_pair_add_int_int( &map, NULL );

	map_pair_add_int_int( &map, &pair );
	checkEq( map.list[0], &pair );
	checkNull( map.list[0]-> next );
	checkNull( map.list[0]-> prev );
	checkEq( map.list[0]-> data, 23 );
	checkEq( map.list[0]-> key, 0 );

	map_pair_add_int_int( &map, &pair2 );
	checkEq( map.list[0], &pair2 );
	checkEq( map.list[0]-> next, &pair );

	return 1;
}

int init_test() {
	char *p;
	size_t i;
	map_int_int map;
	map_init_int_int( &map );
	for( i = 0, p = (char*)&map; i < sizeof( map_int_int ); i++, p++)
		checkEq( *p, 0 );
	return 1;
}

int pair_destroy_test() {
	map_pair_int_int *pair_ptr = NULL;
	map_pair_destroy_int_int( NULL );
	pair_ptr = (map_pair_int_int*) malloc( sizeof( map_pair_int_int ) );
	map_pair_destroy_int_int( pair_ptr );
	return 1;
}

int pair_new_test() {
	map_pair_int_int *pair_ptr;
	pair_ptr = map_pair_new_int_int();
	checkNoNull( pair_ptr );
	free( pair_ptr );
	return 1;
}