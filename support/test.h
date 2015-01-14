#ifndef TEST_H
#define TEST_H

#define test( func ) fprintf(stderr, "Go %s\n", #func ); \
if ( func##_test() != 1 ) { printf("Error: %s\n", #func); exit(-1); } else printf("Complite %s\n\n", #func)

#define checkNull( field ) if ( field != NULL ) return -1

#define checkNoNull( field ) if ( field == NULL ) return -1

#define checkEq( field, value ) if ( field != value ) { \
	printf("Error: %s != %s\n", #field, #value ); \
	return -1; }

#endif
