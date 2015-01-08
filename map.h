#ifndef MAP_H
#define MAP_H

#include "linked_list.h"
#include "iterator.h"
#include "pair.h"

#define HASHMAP_SIZE 1000

/*
=> Функции
	- map* create()
	- void init( map* )
	- map* create()
	- void add ( map*, key_t, data_t )
	- void clear ( map* )
	- void destroy ( map* )
	- int contains ( map*, key_t )
	- iterator* iter_find ( map*, key_t )
	- void iter_delete ( map*, iterator* )
	- void foreach_pair ( map*, void(f)(pair*) )
*/

#define DECLARE_MAP( key_t, data_t )\
\
DECLARE_PAIR( key_t, data_t )\
\
DECLARE_LINKED_LIST( pair_##key_t##_##data_t )\
\
/* ____________________________________________________________________________
	Определение map'а.
*/\
typedef linked_list_pair_##key_t##_##data_t\
		map_##key_t##_##data_t[ HASHMAP_SIZE ];\
/* ____________________________________________________________________________
	Конструктор. Обнуляет массив на уже выделенной памяти.
*/\
void map_init_##key_t##_##data_t( map_##key_t##_##data_t *map ) {\
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	size_t i;\
	for( i = 0; i < HASHMAP_SIZE; i++ )\
		m[i]. first = m[i]. last = NULL;\
}\
/* ____________________________________________________________________________
	Инициализация в куче.
*/\
map_##key_t##_##data_t* map_create_##key_t##_##data_t() {\
	map_##key_t##_##data_t *map;\
	map = (map_##key_t##_##data_t*) malloc( sizeof( map_##key_t##_##data_t ));\
	map_init_##key_t##_##data_t( map );\
	return map;\
}\
/* ____________________________________________________________________________
	Добавить новую пару <ключ, значение> в map.
*/\
void map_add_##key_t##_##data_t( \
	map_##key_t##_##data_t *map, \
	key_t key , \
	data_t data ) { \
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	linked_list_push_back_pair_##key_t##_##data_t (\
		&m[ hash_##key_t( &key ) % HASHMAP_SIZE ],\
		pair_factory_##key_t##_##data_t( key, data ) ); \
}\
/* ____________________________________________________________________________
	Отчистить map.
*/\
void map_clear_##key_t##_##data_t( map_##key_t##_##data_t *map ) {\
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	size_t i = 0;\
	for ( i; i < HASHMAP_SIZE; i++ )\
		linked_list_clear_pair_##key_t##_##data_t( &m[i] );\
}\
/* ____________________________________________________________________________
	Деструктор.
*/\
void map_destroy_##key_t##_##data_t( map_##key_t##_##data_t **map ) {\
	map_clear_##key_t##_##data_t( *map );\
	free( *map );\
	*map = NULL;\
}\
/* ____________________________________________________________________________
	Cодержит ли map элемент c таким ключом.
*/\
int map_contains_##key_t##_##data_t( map_##key_t##_##data_t* map, key_t key) {\
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	iterator_pair_##key_t##_##data_t *it;\
	it = m[ hash_##key_t( &key ) % HASHMAP_SIZE ]. first;\
	while( it != NULL ) {\
		if ( key_t##_compare( &it-> data. key, &key) ) return 1;\
		it = it-> next;\
	}\
	return 0;\
}\
/* ____________________________________________________________________________
	Поиск итератора с указанным ключом.
iterator_pair_##key_t##_##data_t* map_iter_find_##key_t##_##data_t(\
	map_##key_t##_##data_t* map, key_t key ) {\
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	iterator_pair_##key_t##_##data_t *it;\
	it = m[ hash_##key_t( &key ) % HASHMAP_SIZE ]. first;\
	while( it != NULL ) {\
		if ( it-> data. key == key ) return it;\
		it = it-> next;\
	}\
	return NULL;\
}\
/* ____________________________________________________________________________
	Удаление итератора из map'а.
*/\
void map_iter_delete_##key_t##_##data_t( \
	map_##key_t##_##data_t* map, iterator_pair_##key_t##_##data_t *it ) {\
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	linked_list_iter_delete_pair_##key_t##_##data_t( \
		&m[ hash_##key_t( &it-> data. key ) % HASHMAP_SIZE ], it );\
}\
/* ____________________________________________________________________________
	Проход по всем парам <ключ, значение>
*/\
void map_foreach_pair_##key_t##_##data_t( map_##key_t##_##data_t* map,\
	void(f)(pair_##key_t##_##data_t*) ) {\
	linked_list_pair_##key_t##_##data_t *m =\
		(linked_list_pair_##key_t##_##data_t*)map;\
	size_t i = 0;\
	for( i; i < HASHMAP_SIZE; i++ )\
		linked_list_foreach_pair_##key_t##_##data_t( &m[ i ], f );\
}\

#endif