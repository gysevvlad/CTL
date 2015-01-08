#include <string.h>
#include <stddef.h>

#include "CTL_string.h"

size_t hash_string( string *a ) { 
	char *c = a-> data;
	int p = 13;
	unsigned long long hash = 0;
	while (*c != '\0') {
		hash = (*c + hash) * p;
		c++;
	}
	return hash; 
}

int string_compare( string* a, string* b) {
	return strcmp(a-> data, b-> data);
}

size_t hash_char( char *c ) {
	int p = 13;
	unsigned long long hash = 0;
	while (*c != '\0') {
		hash = (*c + hash) * p;
		c++;
	}
	return hash; 	
}

string* string_create( char* str ) {
	string *s;
	s = (string*) calloc( 1, sizeof(string) );
	strcpy( s-> data, str );
	s-> data[255] = 0;
	return s;
}

void string_init( string *str, char *c ) {
	strcpy( str-> data, c );
}
