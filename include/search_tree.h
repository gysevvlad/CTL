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
	destroy search_tree_node
*/\
void search_tree_node_destroy_##key_t##_##data_t( \
	search_tree_node_##key_t##_##data_t *node ) { \
	free( node );\
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
/*_____________________________________________________________________________
	find <key_t, data_t> to search_tree
*/\
search_tree_node_##key_t##_##data_t*\
search_tree_node_find_##key_t##_##data_t( \
	search_tree_##key_t##_##data_t *tree,\
	key_t key) {\
	search_tree_node_##key_t##_##data_t *root = tree-> root;\
	int cmp;\
	if ( root == NULL ) return NULL;\
next:\
	cmp = tree-> cmp( &key, &root-> key );\
	if ( cmp == 0 ) \
		return root;\
	if ( cmp < 0 ) {\
		if ( root-> left == NULL ) {\
			return NULL;\
		} else {\
			root = root-> left;\
			goto next;\
		}\
	}\
	if ( cmp > 0 ) {\
		if ( root-> right == NULL ) {\
			return NULL;\
		} else {\
			root = root-> right;\
			goto next;\
		}\
	}\
}\
\
/*_____________________________________________________________________________
	support function for delete search_tree_node
*/\
search_tree_node_rightmost_##key_t##_##data_t( \
	search_tree_node_##key_t##_##data_t *root ) {\
	while (root-> right != NULL)\
		root = root-> right;\
	return root-> key;\
}\
\
/*_____________________________________________________________________________
	delete search_tree_node
*/\
search_tree_node_##key_t##_##data_t* \
search_tree_node_delete_##key_t##_##data_t( \
	search_tree_node_##key_t##_##data_t *root,\
	int (cmp) (key_t*, key_t*),\
	key_t key ) {\
	search_tree_node_##key_t##_##data_t *temp;\
	int compare;\
\
	if ( root == NULL ) return NULL;\
	compare = cmp( &key, &root-> key );\
	if ( compare == 0) {\
		if ( root-> left == NULL && root-> right == NULL ) {\
			search_tree_node_destroy_##key_t##_##data_t( root );\
			return NULL;\
		}\
		if ( root-> right == NULL && root-> left != NULL) {\
			temp = root-> left;\
			search_tree_node_destroy_##key_t##_##data_t( root );\
			return temp;\
		}\
		if ( root-> left == NULL && root->right != NULL ) {\
			temp = root-> right;\
			search_tree_node_destroy_##key_t##_##data_t( root );\
			return temp;\
		}\
		root-> key = search_tree_node_rightmost_##key_t##_##data_t( root-> left );\
		root-> left = search_tree_node_delete_##key_t##_##data_t( \
			root-> left, cmp, root-> key );\
		return root;\
	}\
	if ( compare < 0 ) {\
		root-> left = search_tree_node_delete_##key_t##_##data_t( root-> left, cmp, key );\
		return root;\
	}\
	if ( compare > 0 ) {\
		root-> right = search_tree_node_delete_##key_t##_##data_t( root-> right, cmp, key );\
		return root;\
	}\
	return root;\
}\
\
/*____________________________________________________________________________ 
	delete
*/\
void search_tree_delete_##key_t##_##data_t( \
	search_tree_##key_t##_##data_t *tree, key_t key ) {\
	tree-> root = search_tree_node_delete_##key_t##_##data_t( tree-> root, tree-> cmp, key );\
}\


#endif