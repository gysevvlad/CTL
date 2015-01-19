#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <malloc.h>

#define print_adress( field ) printf("%s: %p\n", \
	#field, field );

#define print_size( type ) printf( "sizeof( %s ): \t%d\n", \
	#type, sizeof( type ) );

#define test( func ) fprintf(stderr, "Go %s\n", #func ); \
if ( func##_test() != 1 ) { printf("Error: %s\n", #func); exit(-1); } else printf("Complite %s\n\n", #func)

#define checkNull( field ) if ( field != NULL ) { \
	printf("Error: %s != NULL\n", #field ); \
	return -1; }

#define checkNoNull( field ) if ( field == NULL ) return -1

#define checkEq( field, value ) if ( field != value ) { \
	printf("Error: %s != %s\n", #field, #value ); \
	return -1; }

#define checkNoEq( field, value ) if ( field == value ) { \
	printf("Error: %s != %s\n", #field, #value ); \
	return -1; }

#endif
