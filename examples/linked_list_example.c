#include <stdio.h>

#include "linked_list.h"
#include "point.h"

DECLARE_LINKED_LIST( point_t )

main() {
	#define linked_list_t linked_list_point_t
	#define linked_list_init linked_list_init_point_t
	#define linked_list_new_back linked_list_new_back_point_t

	linked_list_t list;
	int n = 0;

	linked_list_init( &list );	

	scanf( "%d", &n );
	for(; n; n--) {
		linked_list_new_back( &list );
		scanf( "%d %d %d", &list.last-> data.x, 
			&list.last-> data.y, &list.last-> data.z );
	}

	printf( "(%d, %d, %d)", list.last-> data.x, 
		list.last-> data.y, list.last-> data.z );
}
