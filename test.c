#include <stddef.h>
#include <stdio.h> 

#include "CTL_string.h"
#include "point.h"
#include "map.h"

typedef point_t point;

size_t hash_int( int *a ) { return 0; }

typedef char* char_ptr;

DECLARE_MAP( string, point )

void pair_printf( pair_string_point *p ) {
	printf("%s (%d, %d, %d)\n", p-> key.data, 
		p-> data.x + 1, p-> data.y + 1, p-> data.z + 1 );
}

int main() {
	string buff;
	point p;
	map_string_point map;

	map_init_string_point( &map );
	string_init( &buff , "");
	#define map_add map_add_string_point
	#define map_foreach map_foreach_pair_string_point

	size_t k = 0;
	scanf( "%d", &k );
	do {
		scanf( "%s (%d, %d, %d)", buff.data, &p.x, &p.y, &p.z );
		map_add( &map,  buff, p );
	} while ( --k );

	map_foreach( &map, pair_printf );
}
