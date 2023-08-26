#include "main.h"

/**
 * free_pointers - Frees any number of pointers given.
 * @pt: The pointer to be freed.
 */
void free_pointers(void *pt, ...)
{
	void *ptr;

	va_list ptrs;

	va_start(ptrs, pt);

	ptr = pt;
	while (ptr != NULL)
	{
		free(ptr);
		ptr = va_arg(ptrs, void*);
	}
	va_end(ptrs);
}
