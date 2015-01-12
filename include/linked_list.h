#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <malloc.h>

#include "iterator.h"

/*
	- void init( linked_list* )
	- linked_list* create()
	- void clear( linked_list* )
	- void destroy( linked_list** )
*/

#define DECLARE_LINKED_LIST( data_t )\
\
DECLARE_ITERATOR( data_t )\
\
/*_____________________________________________________________________________
	linked_list { first, last }
*/\
typedef struct {\
	iterator_##data_t *first, *last;\
} linked_list_##data_t;\
\
/*_____________________________________________________________________________
	Инициализация двусвязного списка на уже выделенной памяти.
*/\
void linked_list_init_##data_t( linked_list_##data_t *list ) {\
	if ( list == NULL ) return;\
	list-> first = NULL;\
	list-> last = NULL;\
}\
/*_____________________________________________________________________________
	Создание двусвязного списка в куче.
*/\
linked_list_##data_t* linked_list_create_##data_t() {\
	linked_list_##data_t *node;\
	node = ( linked_list_##data_t* )malloc( sizeof( linked_list_##data_t ) );\
	linked_list_init_##data_t( node );\
	return node;\
}\
/*_____________________________________________________________________________
	Отчистить список. НЕДОПИСАНО
*/\
void linked_list_clear_##data_t( linked_list_##data_t *list ) {\
	if ( list == NULL ) return;\
	list-> first = NULL;\
	list-> last = NULL;\
}\
/*_____________________________________________________________________________
	Деструктор.
*/\
void linked_list_destroy_##data_t( linked_list_##data_t **list ) {\
	if (list == NULL) return;\
	linked_list_clear_##data_t( *list );\
	free(*list);\
	*list = NULL;\
}\



#endif