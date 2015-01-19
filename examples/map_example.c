#include <stddio.h>

#include "map.h"

DECLARE_MAP ( CTL_string, point_t )

main() {
	map_CTL_string_point_t map
	STL_string temp_string;
	point_t temp_point;
	int n;

	map_init_CTL_string_point_t( &map );

	scanf( "%d", &n );
	for( ; n; n--) {
		scanf( "%s (%d, %d, %d)", &temp, 
			temp_point.x, temp_point.y, temp_point.z );
		map_add_STL_string_point_t( temp_string, temp_point );
	}
}

/*
		Эффективный вариант.
	Запись данных произойдет сразу в структуру pair.
	Функция map_add_iter_ptr свяжет созданный 
	iterator_pair_##key_t##_##data_t c контейнером. 
	После этого указатель на него останется в 
	map'е. При отчистке map'а iterator так же будет
	уничтожен. Никаких действий производить не нужно.
*/
void try_on_stack() {
	iterator_pair_CTL_string_point_t *iter;
	map_CTL_string_point_t map;
	int n;

	map_init_CTL_string_point_t( &map );

	scanf( "%d", &n );
	for( ; n; n--) {
		iter = iter_new_pair_CTL_string_point_t();
		scanf( "%s (%d, %d, %d)", &iter-> pair.key.symbols, 
			&iter-> pair.data.x, &iter-> pair.data.y, &iter-> pair.data.z );
		map_pair_ptr_add_CTL_string_point_t( &map, iter );
	}

	map_clear_CTL_string_point_t( &map );
}

void try_on_heap() {
	#define iterator_t iterator_pair_CTL_string_point_t 
	#define map_create map_create_CTL_string_point_t
	#define map_t map_CTL_string_point_t
	#define iter_new iter_new_pair_CTL_string_point_t
	#define map_pair_ptr_add map_pair_ptr_add_CTL_string_point_t
	#define map_destroy map_destroy_CTL_string_point_t

	iterator_t *iter;
	map_t *map_ptr;
	int n;

	map = map_create();

	scanf( "%d", &n );
	for( ; n; n--) {
		iter = iter_new();
		scanf( "%s (%d, %d, %d)", pair-> key.symbols, 
			&pair-> data.x, &pair-> data.y, &pair-> data.z );
		map_pair_ptr_add( map_ptr, iter );
	}

	map_destroy( &map_ptr );	

	#undef map_destroy 
	#undef map_pair_ptr_add 
	#undef iter_new 
	#undef map_t 
	#undef map_create 
	#undef iterator_t  
}