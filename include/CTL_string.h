typedef struct {
	char data[256];
} string;

size_t hash_string( string *a );

int string_compare( string* a, string* b );

size_t hash_char( char *c );

string* string_create( char* str );

void string_init( string* a, char* c );3