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
	- void push_front( data_t )
	- void front_new()
	- void new_back( linked_list* )
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
	Добавить в конец списка
*/\
void linked_list_push_back_##data_t(\
	linked_list_##data_t *list,\
	data_t data ) {\
	iterator_##data_t *node;\
	if (list-> last != NULL) {\
		node = iter_create_##data_t(\
			list-> last-> next,\
			list-> last,\
			data );\
		list-> last-> next = node;\
		list-> last = node;\
	}\
	else {\
		node = iter_create_##data_t( NULL, NULL, data );\
		list-> last = node;\
		list-> first = node;\
	}\
}\
/*_____________________________________________________________________________
	Перебор всех iterator'ов списка
*/\
void linked_list_iter_foreach_##data_t ( \
	linked_list_##data_t *list,\
	void(f)(iterator_##data_t**) ) {\
	iterator_##data_t *iter, *curr, *last;\
	if ( list == NULL ) return;\
	if ( list-> first == NULL) return;\
	last = list-> last-> next;\
	iter = list-> first;\
	while ( iter != last ) {\
		curr = iter;\
		iter = iter-> next;\
		f( &curr );\
	}\
}\
/*_____________________________________________________________________________
	Удалить все элементы в двусвязном списке
*/\
void linked_list_clear_##data_t( linked_list_##data_t *list ) {\
	linked_list_iter_foreach_##data_t ( list, iter_destroy_##data_t );\
	linked_list_init_##data_t( list );\
}\
/*_____________________________________________________________________________
	Деструктор.
*/\
void linked_list_destroy_##data_t( linked_list_##data_t **list ) {\
	if ( list == NULL ) return;\
	linked_list_clear_##data_t( *list );\
	free(*list);\
	*list = NULL;\
}\
/*_____________________________________________________________________________
	Добавить в конец новый iterator для заполнения.
*/\
void linked_list_new_back_##data_t( linked_list_##data_t *list ) { \
	iterator_##data_t* iter = iter_new_##data_t(); \
	iter_link_##data_t( iter, list-> last, NULL ); \
	list-> last = iter; \
}\
/*_____________________________________________________________________________
	Добавить новый iterator в конец списка.
*/\
void linked_list_iter_push_back_##data_t( linked_list_##data_t *list, \
	iterator_##data_t *iter ) {\
	if (list == NULL ) return;\
	if ( iter == NULL ) return;\
	if ( list-> first == NULL ) {\
		list-> first = list-> last = iter;\
		iter-> next = NULL;\
		iter-> prev = NULL;\
		return;\
	}\
	list-> last-> prev = iter;\
	iter-> next = list-> last;\
	list-> last = iter;\
}\
/*_____________________________________________________________________________
	Удалить iterator из списка
*/\
void linked_list_iter_delete_##data_t (\
	linked_list_##data_t *list,\
	iterator_##data_t *iter ) {\
	if ( list-> first == NULL ) return;\
	if ( list-> first == iter )\
		list-> first = list-> first-> next;\
	if ( list-> last == iter )\
		list-> last = list-> last-> prev;\
	iter_destroy_##data_t( &iter );\
}\
/*_____________________________________________________________________________
	Перебор всех элементов списка
*/\
void linked_list_foreach_##data_t ( \
	linked_list_##data_t *list,\
	void(f)(data_t*) ) {\
	iterator_##data_t *iter, *last;\
	if ( list-> first == NULL) return;\
	last = list-> last-> next;\
	iter = list-> first;\
	while ( iter != last ) {\
		f( &(iter-> data) );\
		iter = iter-> next;\
	}\
}\


#endif