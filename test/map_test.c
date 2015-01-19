#include <stddef.h>
#include <stdio.h> 

#include "CTL_string.h"
#include "point.h"
#include "map.h"

size_t hash_int( int *a ) { return 0; }

typedef char* char_ptr;

DECLARE_MAP( string, point_t )

void pair_printf( pair_string_point_t *p ) {
	printf("%s (%d, %d, %d)\n", p-> key.data, 
		p-> data.x + 1, p-> data.y + 1, p-> data.z + 1 );
}

int main() {
	try();

	/*
	string buff;
	point_t p;
	map_string_point_t map;

	map_init_string_point_t( &map );
	string_init( &buff , "");
	#define map_add map_add_string_point_t
	#define map_foreach map_foreach_pair_string_point_t

	size_t k = 0;
	scanf( "%d", &k );
	do {
		scanf( "%s (%d, %d, %d) ", buff.data, &p.x, &p.y, &p.z );
		map_add( &map,  buff, p );
	} while ( --k );

	map_foreach( &map, pair_printf );
	*/
}

int try() {
	map_string_point_t map;
	iterator_pair_string_point_t *iter;

	map_init_string_point_t( &map );

	iter = iter_new_pair_string_point_t();
	scanf( "%s %d %d %d", iter-> data.key.data, 
		&iter-> data.data.x, &iter-> data.data.y, &iter-> data.data.z );
	printf( "%s %d %d %d", iter-> data.key.data, 
		iter-> data.data.x, iter-> data.data.y, iter-> data.data.z );
	map_add_iter_string_point_t( &map,  iter );

	map_foreach_pair_string_point_t( &map, pair_printf );

	return 0;
}

