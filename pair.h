#ifndef PAIR_H
#define PAIR_H

#include <malloc.h>
#include <stddef.h>

/*	
=> Типы
	- pair
	- pair_ptr

=> Функции
	- pair* create( key, data )
	- pair factory( key, data )
	- void init( pair*, key, data )
	- void destroy( pair** )
*/

#define DECLARE_PAIR(key_t, data_t)\
\
/* ____________________________________________________________________________
	Тип, описывающий пару <ключ, значение>.
	pair <key_t, data_t>
*/\
typedef struct {\
	key_t key;\
	data_t data;\
} pair_##key_t##_##data_t;\
\
/* ____________________________________________________________________________
	Тип, описывающий указатель на пару <ключ, значение>. 
*/\
typedef pair_##key_t##_##data_t* pair_ptr_##key_t##_##data_t;\
\
/* ____________________________________________________________________________
	Инициализация новой пары <ключ, значение> в куче.
*/\
pair_##key_t##_##data_t* \
pair_create_##key_t##_##data_t (key_t key, data_t data) {\
	pair_##key_t##_##data_t *pair;\
	pair = (pair_##key_t##_##data_t*)malloc(\
				sizeof(pair_##key_t##_##data_t));\
	pair-> key = key;\
	pair-> data = data;\
	return pair;\
}\
/* ____________________________________________________________________________
	Инициализация новой пары <ключ, значение> на стеке по адресу.
*/\
void pair_init_##key_t##_##data_t( \
	pair_##key_t##_##data_t *pair, \
	key_t key, \
	data_t data ) { \
	pair-> key = key;\
	pair-> data = data;\
}\
/* ____________________________________________________________________________
	Генерация нового pair c возвратом на стек.	
*/\
pair_##key_t##_##data_t pair_factory_##key_t##_##data_t( \
	key_t key, \
	data_t data) {\
	pair_##key_t##_##data_t pair;\
	pair.data = data;\
	pair.key = key;\
	return pair;\
}\
/* ____________________________________________________________________________
	Деструктор.
*/\
void pair_destroy_##key_t##_##data_t(pair_##key_t##_##data_t **pair) {\
	free(*pair);\
	*pair = NULL;\
}\

#endif