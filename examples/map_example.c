
#include "map.h"
#include "test.h"

DECLARE_MAP( int, int )

void map_pair_print_int_int( map_pair_int_int *pair ) {
	printf("%d %d\n", pair-> key, pair-> data );
}

main() {
	map_pair_int_int *pair = NULL;
	map_int_int map;
	size_t k;

	map_init_int_int( &map );
	scanf( "%d", &k );
	for(; k; k--) {
		pair = map_pair_new_int_int();
		scanf("%d %d", &pair-> key, &pair-> data);
		map_pair_add_int_int( &map, pair );
	}
	map_pair_foreach_int_int( &map, map_pair_print_int_int );
	map_clear_int_int( &map );
}