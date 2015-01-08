#ifndef ITERATOR_H
#define ITERATOR_H

#include <malloc.h>
#include <stddef.h>

/*
	- iterator* create( iterator*, iterator*, data )
	- iterator factory( iterator*, iterator*, data )
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
	Инициализация iterator'а в куче.
*/\
iterator_##data_t* iter_create_##data_t(\
	iterator_##data_t *next,\
	iterator_##data_t *prev,\
	data_t data) {\
	iterator_##data_t *iter;\
	iter = malloc( sizeof( iterator_##data_t ) );\
	iter-> next = next;\
	iter-> prev = prev;\
	iter-> data = data;\
	return iter;\
}\
/*_____________________________________________________________________________
	Инициализация iterator'а с возвратом на стек.
*/\
iterator_##data_t iter_factory_##data_t(\
	iterator_##data_t *next,\
	iterator_##data_t *prev,\
	data_t data) {\
	iterator_##data_t iter;\
	iter. next = next;\
	iter. prev = prev;\
	iter. data = data;\
	return iter;\
}\
/*_____________________________________________________________________________
	Удалить iterator.
*/\
void iter_destroy_##data_t( iterator_##data_t **iter ) {\
	if ( *iter == NULL ) return;\
	if ( (*iter)-> next != NULL )\
		(*iter)-> next-> prev = (*iter)-> prev;\
	if ( (*iter)-> prev != NULL )\
		(*iter)-> prev-> next = (*iter)-> next;\
	free(*iter);\
	*iter = NULL;\
}\

#endif ITERATOR_H