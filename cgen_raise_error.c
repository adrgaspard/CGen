#include "lib/cgen_generated.h"

int32_t __cgen_raise_error__(const char *file, const int line, const char *message)
{
	fprintf(stderr, "%s:%d > %s\n", file, line, message);
	exit(42);
	return -1;
}