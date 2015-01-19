#ifndef MAP_H
#define MAP_H

#include <malloc.h>
#include <string.h>

size_t hash_int( int* key ) { return (size_t) *key; }

int int_compare( int* a, int* b ) { 
	if ( *a == *b ) return 0;
	else return 1; }

#define HASHMAPSIZE 65537

#define DECLARE_MAP( key_t, data_t )\
/*_____________________________________________________________________________
	pair for map
*/\
typedef struct str_map_pair_##key_t##_##data_t {\
	struct str_map_pair_##key_t##_##data_t *next, *prev;\
	key_t key;\
	data_t data;\
} map_pair_##key_t##_##data_t;\
\
/*_____________________________________________________________________________
	definition map
*/\
typedef struct {\
	map_pair_##key_t##_##data_t* list[ HASHMAPSIZE ];\
} map_##key_t##_##data_t;\
\
/*_____________________________________________________________________________
	new allocating memory for pair 
*/\
map_pair_##key_t##_##data_t* map_pair_new_##key_t##_##data_t() {\
	return (map_pair_##key_t##_##data_t*) malloc (\
		sizeof ( map_pair_##key_t##_##data_t ) );\
}\
/*_____________________________________________________________________________
	destructor for pair
*/\
void map_pair_destroy_##key_t##_##data_t(map_pair_##key_t##_##data_t *pair){\
	free( pair );\
}\
/*_____________________________________________________________________________
	map initialize an allocated memory
*/\
void map_init_##key_t##_##data_t( map_##key_t##_##data_t *map ) {\
	memset( map, 0, sizeof( map_##key_t##_##data_t ) );\
}\
/*_____________________________________________________________________________
	add pair in map
*/\
void map_pair_add_##key_t##_##data_t( map_##key_t##_##data_t *map,\
	map_pair_##key_t##_##data_t *pair) {\
	if ( map == NULL ) return;\
	if ( pair == NULL ) return;\
	size_t k = hash_##key_t( &pair-> key ) % HASHMAPSIZE;\
	if ( map-> list[k] == NULL ) {\
		map-> list[k] = pair;\
		pair-> next = pair-> prev = NULL;\
	}\
	else {\
		pair-> prev = NULL;\
		pair-> next = map-> list[k];\
		map-> list[k]-> prev = pair;\
		map-> list[k] = pair;\
	}\
}\
/*_____________________________________________________________________________
	search by key
*/\
map_pair_##key_t##_##data_t* map_pair_find_##key_t##_##data_t(\
	map_##key_t##_##data_t *map, key_t key ) {\
	size_t k = hash_##key_t( &key ) % HASHMAPSIZE;\
	map_pair_##key_t##_##data_t *pair = map-> list[ k ];\
	while ( pair && key_t##_compare( &pair-> key, &key ) != 0 )\
		pair = pair-> next;\
	return pair;\
}\
/*_____________________________________________________________________________
	delete pair
*/\
void map_pair_delete_##key_t##_##data_t(\
	map_pair_##key_t##_##data_t *pair) {\
	if ( pair == NULL ) return;\
	if ( pair-> next )\
		pair-> next-> prev = pair-> prev;\
	if ( pair-> prev )\
		pair-> prev-> next = pair-> next;\
	map_pair_destroy_##key_t##_##data_t( pair );\
}\
/*_____________________________________________________________________________
	pair_foreach
*/\
void map_pair_foreach_##key_t##_##data_t( \
	map_##key_t##_##data_t *map,\
	void(f)( map_pair_##key_t##_##data_t* ) ) {\
	map_pair_##key_t##_##data_t *pair, *temp;\
	size_t i;\
	for( i = 0; i < HASHMAPSIZE; i++ ) {\
		pair = map-> list[i];\
		while( pair ) {\
			temp = pair-> next;\
			f( pair );\
			pair = temp;\
		}\
	}\
}\
/*_____________________________________________________________________________
	clear
*/\
void map_clear_##key_t##_##data_t( map_##key_t##_##data_t *map ) {\
	map_pair_foreach_##key_t##_##data_t( map, \
		map_pair_delete_##key_t##_##data_t );\
}\

#endif