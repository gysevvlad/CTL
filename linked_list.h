#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <malloc.h>

#include "iterator.h"

/*
	- create()
	- destroy( linked_list* )
	- clear( linked_list* )
	- iter_foreach( linked_list*, void(f)(iterator**) )
	- iter_delete( linked_list*, iterator* )
	- iter_find( linked_list*, int(f)(data) )
	- foreach( linked_list*, data )
	- push_back( linked_list*, data )
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
	Инициализация двусвязного списка в куче
*/\
linked_list_##data_t* linked_list_create_##data_t() {\
	linked_list_##data_t *node;\
	node = ( linked_list_##data_t* )malloc( sizeof( linked_list_##data_t ) );\
	node-> first = NULL;\
	node-> last = NULL;\
	return node;\
}\
/*_____________________________________________________________________________
	Перебор всех iterator'ов списка
*/\
void linked_list_iter_foreach_##data_t ( \
	linked_list_##data_t *list,\
	void(f)(iterator_##data_t**) ) {\
	iterator_##data_t *iter, *curr, *last;\
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
/*_____________________________________________________________________________
	Удалить все элементы в двусвязном списке
*/\
void linked_list_clear_##data_t( linked_list_##data_t *list ) {\
	linked_list_iter_foreach_##data_t ( list, iter_destroy_##data_t );\
	list-> first = NULL;\
	list-> last = NULL;\
}\
/*_____________________________________________________________________________
	Уничтожить двусвязный список в памяти
*/\
void linked_list_destroy_##data_t( linked_list_##data_t **list ) {\
	if (list == NULL) return;\
	linked_list_clear_##data_t( *list );\
	free(*list);\
	*list = NULL;\
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
	Поиск iterator'а с указанной data
*/\
iterator_##data_t* linked_list_iter_find_##data_t(\
	linked_list_##data_t *list,\
	int(f)(data_t) ) {\
	iterator_##data_t *iter, *last;\
	if ( list-> first == NULL) return NULL;\
	last = list-> last-> next;\
	iter = list-> first;\
	while ( iter != last )\
		if ( f( iter-> data ) ) return iter;\
		else iter = iter-> next;\
	return NULL;\
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

#endif