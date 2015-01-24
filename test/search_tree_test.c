#include "search_tree.h"
#include "test.h"

int int_compare( int* a, int *b ) {
	int af = *a, bf = *b;
	if ( af < bf ) return -1;
	if ( af == bf ) return 0;
	return 1;	
}

DECLARE_SEARCH_TREE( int, double )

int add_test();

main() {
	test( add );
}

int add_test() {
	search_tree_int_double tree;

	search_tree_init_user_int_double( &tree, int_compare );

	search_tree_add_int_double( &tree, 12, 1.2 );
	checkNoNull( tree.root );
	checkNull( tree.root-> left );
	checkNull( tree.root-> right );
	checkEq( tree.root-> key, 12 );
	checkEq( tree.root-> data, 1.2 );

	search_tree_add_int_double( &tree, 8, 4.5 );
	checkNoNull( tree.root-> left );
	checkNull( tree.root-> right );
	checkNull( tree.root-> left-> left );
	checkNull( tree.root-> left-> right );
	checkEq( tree.root, tree.root-> left-> parent );
	checkEq( tree.root-> left-> key, 8 );

	search_tree_add_int_double( &tree, 6, 9.3 );
	checkEq( tree.root-> left-> left-> data, 9.3 );

	search_tree_add_int_double( &tree, 16, 10.3 );
	checkEq( tree.root-> right-> data, 10.3 );
	checkEq( tree.root-> right-> key, 16 );
	checkEq( tree.root-> right-> parent, tree.root );

	search_tree_add_int_double( &tree, 9, 9.3 );
	checkEq( tree.root-> left-> right-> key, 9 );

	return 1;
}
