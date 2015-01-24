#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include <malloc.h>
#include <stddef.h>

#define DECLARE_SEARCH_TREE( key_t, data_t )\
/*_____________________________________________________________________________
	typedef compare function ( args type:  void* )
*/\
typedef int( function_compare_void )( void*, void* );\
\
/*_____________________________________________________________________________
	typedef search_tree_node
*/\
typedef struct search_tree_node_st_##key_t##_##data_t {\
	struct search_tree_node_st_##key_t##_##data_t *parent, *left, *right;\
	key_t key;\
	data_t data;\
} search_tree_node_##key_t##_##data_t;\
\
/*_____________________________________________________________________________
	typedef search_tree
*/\
typedef struct {\
	search_tree_node_##key_t##_##data_t *root;\
	int(*cmp)(key_t*, key_t*);\
} search_tree_##key_t##_##data_t;\
\
/*_____________________________________________________________________________
	init default search_tree
*/\
void search_tree_init_default_##key_t##_##data_t (\
	search_tree_##key_t##_##data_t *tree ) {\
	tree-> root = NULL;\
	tree-> cmp = key_t##_compare;\
}\
\
/*_____________________________________________________________________________
	init user search_tree
*/\
void search_tree_init_user_##key_t##_##data_t (\
	search_tree_##key_t##_##data_t *tree,\
	int(*cmp)(key_t*, key_t*) ) {\
	tree-> root = NULL;\
	tree-> cmp = cmp;\
}\
\
/*_____________________________________________________________________________
	allocate search_tree_node
*/\
search_tree_node_##key_t##_##data_t* \
search_tree_node_new_##key_t##_##data_t( ){\
	return (search_tree_node_##key_t##_##data_t*) malloc ( \
		sizeof( search_tree_node_##key_t##_##data_t ) );\
}\
/*_____________________________________________________________________________
	init search_tree_node
*/\
void search_tree_node_init_##key_t##_##data_t(\
	search_tree_node_##key_t##_##data_t *tree, \
	key_t key, data_t data, \
	search_tree_node_##key_t##_##data_t* parent ) {\
	tree-> key = key;\
	tree-> data = data;\
	tree-> parent = parent;\
	tree-> left = NULL;\
	tree-> right = NULL;\
}\
\
/*_____________________________________________________________________________
	init search_tree_node
*/\
search_tree_node_##key_t##_##data_t* \
search_tree_node_create_##key_t##_##data_t( key_t key, data_t data, \
	search_tree_node_##key_t##_##data_t* parent ) {\
	search_tree_node_##key_t##_##data_t* tree;\
	tree = search_tree_node_new_##key_t##_##data_t( );\
	search_tree_node_init_##key_t##_##data_t( tree, key, data, parent );\
	return tree;\
}\
\
/*_____________________________________________________________________________
	add <key_t, data_t> to search_tree
*/\
void search_tree_add_##key_t##_##data_t( search_tree_##key_t##_##data_t *tree,\
	key_t key, data_t data ) {\
	search_tree_node_##key_t##_##data_t *root = tree-> root;\
	int cmp;\
	if ( root == NULL ) {\
		tree-> root = search_tree_node_create_##key_t##_##data_t(\
			key, data, NULL );\
		return;\
	} \
next:\
	cmp = tree-> cmp( &key, &root-> key );\
	if ( cmp < 0 ) {\
		if ( root-> left == NULL ) {\
			root-> left = search_tree_node_create_##key_t##_##data_t(\
				key, data, root );\
			return;\
		} else {\
			root = root-> left;\
			goto next;\
		}\
	}\
	if ( cmp > 0 ) {\
		if ( root-> right == NULL ) {\
			root-> right = search_tree_node_create_##key_t##_##data_t( \
				key, data, root );\
			return;\
		} else {\
			root = root-> right;\
			goto next;\
		}\
	}\
	if ( cmp == 0 ) {\
		root-> data = data;\
		root-> key = key;\
		return;\
	}\
}\
\


#endif