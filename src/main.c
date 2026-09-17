#include "core/silk.h"

#include <stdlib.h>

int
main(void)
{
	struct silk_runtime *runtime = silk_runtime_create();

	if (runtime == NULL)
		return EXIT_FAILURE;

	silk_runtime_destroy(runtime);
	return EXIT_SUCCESS;
}
