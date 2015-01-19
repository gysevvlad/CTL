
#include "linked_list.h"
#include "point.h"
#include "test.h"

DECLARE_LINKED_LIST( point_t )

int init_test();
int create_test();
int destroy_test();
int push_back_test();
int iter_foreach_test();
int clear_test();

int main() {
	test( init ); 			/*   ok   */
	test( create );			/*   ok   */
	test( destroy );		/*   no   */
	test( iter_foreach );	/*   no   */
	test( push_back );		/*   no   */
	test( iter_push_back ); 

}

/*____________________________________________________________________________*/

int iter_push_back_test() {
	linked_list_point_t list;
	iterator_point_t *it1, *it2;


	linked_list_init_point_t( &list );
	it1 = iter_new_point_t();
	it1-> data.x = 1;
	it1-> data.y = 2;
	it1-> data.z = 3;

	it2 = iter_new_point_t();

	linked_list_iter_push_back_point_t( NULL, it1 );

	linked_list_iter_push_back_point_t( &list, NULL );

	linked_list_iter_push_back_point_t( &list, it1 );
	checkEq( list.first, list.last );
	checkEq( list.first-> data.x, 1 );
	checkEq( list.first-> data.y, 2 );
	checkEq( list.first-> data.z, 3 );
	checkNoNull( list.first );
	checkNull( it1-> next );

	linked_list_iter_push_back_point_t( &list, it2 );
	checkEq( list.first, it1 );
	checkEq( list.last, it2 );
	checkEq( it1, list.last-> next );
	checkEq( it2, list.first-> prev);


	return 1;
}

/*____________________________________________________________________________*/

int push_back_test() {
	linked_list_point_t list;

	linked_list_init_point_t( &list );

	linked_list_push_back_point_t( &list, point_factory( 1, 2, 3 ) );
	checkEq( list.first, list.last );
	checkEq( list.first-> data.x, 1 );
	checkEq( list.first-> data.y, 2 );
	checkEq( list.first-> data.z, 3 );

	linked_list_push_back_point_t( &list, point_factory( 2, 3, 4 ) );
	checkNoEq( list.first, list.last );
	checkEq( list.first-> data.x, 1 );
	checkEq( list.first-> data.y, 2 );
	checkEq( list.first-> data.z, 3 );
	checkEq( list.last-> data.x, 2 );
	checkEq( list.last-> data.y, 3 );
	checkEq( list.last-> data.z, 4 );

	linked_list_clear_point_t( &list );

	return 1;
}

/*___________________________________________________________________________*/


static int gl_iter_foreach_test_k;

void iter_foreach_test_supp1( iterator_point_t **iter ) { gl_iter_foreach_test_k++;	}

int iter_foreach_test() {
	linked_list_point_t list;

	linked_list_init_point_t( &list );

	gl_iter_foreach_test_k = 0;
	linked_list_iter_foreach_point_t( &list, iter_foreach_test_supp1 );
	checkEq( gl_iter_foreach_test_k, 0 );

	gl_iter_foreach_test_k = 0;
	linked_list_push_back_point_t( &list, point_factory( 1, 2, 3 ) );
	linked_list_iter_foreach_point_t( &list, iter_foreach_test_supp1 );
	checkEq( gl_iter_foreach_test_k, 1 );

	gl_iter_foreach_test_k = 0;
	linked_list_push_back_point_t( &list, point_factory( 4, 5, 6 ) );
	linked_list_push_back_point_t( &list, point_factory( 7, 8, 9 ) );
	linked_list_iter_foreach_point_t( &list, iter_foreach_test_supp1 );
	checkEq( gl_iter_foreach_test_k, 3 );

	linked_list_clear_point_t( &list );
	return 1;

}

/*___________________________________________________________________________*/

int destroy_test() {
	linked_list_point_t *list_ptr = NULL;

	linked_list_destroy_point_t( NULL );
	linked_list_destroy_point_t( &list_ptr );

	list_ptr = linked_list_create_point_t();
	checkNoNull( list_ptr );

	linked_list_destroy_point_t( &list_ptr );
	checkNull( list_ptr );

	return 1;
}

/*___________________________________________________________________________*/

int create_test() {
	linked_list_point_t *list_ptr;

	list_ptr = linked_list_create_point_t();

	checkNoNull( list_ptr );
	checkNull( list_ptr->first );
	checkNull( list_ptr->last );

	return 1;

}

/*___________________________________________________________________________*/

int init_test() {
	linked_list_point_t list;
	linked_list_point_t *list_ptr = NULL;

	linked_list_init_point_t( list_ptr );

	linked_list_init_point_t( &list );
	checkNull( list.first );
	checkNull( list.last );

	return 1;
}

/*___________________________________________________________________________*/
