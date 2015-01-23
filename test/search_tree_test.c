#include "search_tree.h"

int int_compare( int* a, int *b ) {
	if ( a < b ) return -1;
	if ( a = b ) return 0;
	return 1;	
}

int user_compare( int* a, int *b ) {
	return 1;
}

DECLARE_SEARCH_TREE( int, int )

main() {
	#define search_tree_t search_tree_int_int
	#define search_tree_init_user search_tree_init_user_int_int 
	#define search_tree_init_default search_tree_init_default_int_int 
	#define search_tree_node_t search_tree_node_int_int 
	#define search_tree_node_new search_tree_node_new_int_int

	search_tree_node_t *node_ptr;
	search_tree_t tree1, tree2;

	search_tree_init_default( &tree1 );
	search_tree_init_user( &tree2, user_compare );
	node_ptr = search_tree_node_new( );

}
