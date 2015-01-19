#ifndef ITERATOR_H
#define ITERATOR_H

#include <malloc.h>
#include <stddef.h>

/*
	- iterator* create( iterator*, iterator*, data )
	- iterator* new()
	- void init( iterator*, iterator*, iterator*, data )
	- iterator factory( iterator*, iterator*, data )
	- void remove( iterator* )
	- void destroy( iterator** )
*/

#define DECLARE_ITERATOR( data_t )\
\
/*_____________________________________________________________________________
	iterator 
*/\
typedef struct iter_struct_##data_t {\
	struct iter_struct_##data_t *next, *prev;\
	data_t data;\
} iterator_##data_t;\
\
/*_____________________________________________________________________________
	Отчистить iterator.
*/\
void iter_remove_##data_t( iterator_##data_t *iter) {\
	if (iter == NULL) return;\
	if ( iter-> next != NULL )\
		iter-> next-> prev = iter-> prev;\
	if ( iter-> prev != NULL )\
		iter-> prev-> next = iter-> next;\
	memset( iter, 0, sizeof( iterator_##data_t ));\
}\
/*_____________________________________________________________________________
	Связать итератор с другими.
*/\
void iter_link_##data_t( iterator_##data_t *iter,\
	iterator_##data_t *next,\
	iterator_##data_t *prev ) {\
	if (iter == NULL) return; \
	iter-> next = next; \
	if ( next != NULL ) \
		next-> prev = iter; \
	iter-> prev = prev; \
	if ( prev != NULL ) \
		prev-> next = iter; \
} \
/*_____________________________________________________________________________
	Инициализация iterator'а на уже выделенной памяти.
*/\
void iter_init_##data_t( iterator_##data_t *iter,\
	iterator_##data_t *next,\
	iterator_##data_t *prev,\
	data_t data) {\
	if (iter == NULL) return;\
	iter_link_##data_t( iter, next, prev );\
	iter-> data = data;\
}\
/*_____________________________________________________________________________
	Выделить память под новый iterator.
*/\
iterator_##data_t* iter_new_##data_t() { \
	return (iterator_##data_t*) malloc( sizeof( iterator_##data_t ) );\
}\
/*_____________________________________________________________________________
	Инициализация iterator'а в куче.
*/\
iterator_##data_t* iter_create_##data_t(\
	iterator_##data_t *next,\
	iterator_##data_t *prev,\
	data_t data) {\
	iterator_##data_t *iter = iter_new_##data_t();\
	iter_init_##data_t( iter, next, prev, data );\
	return iter;\
}\
/*_____________________________________________________________________________
	Удалить iterator.
*/\
void iter_destroy_##data_t( iterator_##data_t **iter ) {\
	if ( iter == NULL ) return;\
	iter_remove_##data_t ( *iter );\
	free(*iter);\
	*iter = NULL;\
}\


#endif ITERATOR_H