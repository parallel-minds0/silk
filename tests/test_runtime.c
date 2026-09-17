#include "core/silk.h"
#include "platform/platform.h"
#include "platform/platform_window.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST_ASSERT(condition) \
	do { \
		if (!(condition)) { \
			fprintf(stderr, "%s:%d: assertion failed: %s\\n", \
				__FILE__, __LINE__, #condition); \
			return EXIT_FAILURE; \
		} \
	} while (false)

int
main(void)
{
	struct silk_platform *platform;
	struct silk_platform_window *window;
	struct silk_platform_window_config config = {
		.width = 1280,
		.height = 720,
		.title = "Silk test window",
	};
	struct silk_platform_window_config invalid_config = {
		.width = 0,
		.height = 720,
		.title = "Invalid window",
	};

	struct silk_runtime *runtime = silk_runtime_create();

	TEST_ASSERT(runtime != NULL);
	TEST_ASSERT(silk_runtime_is_running(runtime));

	platform = silk_platform_create();
	TEST_ASSERT(platform != NULL);

	window = silk_platform_window_create(platform, &config);
	TEST_ASSERT(window != NULL);
	TEST_ASSERT(silk_platform_window_get_width(window) == 1280);
	TEST_ASSERT(silk_platform_window_get_height(window) == 720);

	silk_platform_window_destroy(window);

	window = silk_platform_window_create(platform, &invalid_config);
	TEST_ASSERT(window == NULL);

	silk_platform_destroy(platform);

	silk_runtime_request_quit(runtime);
	TEST_ASSERT(!silk_runtime_is_running(runtime));

	silk_runtime_destroy(runtime);
	return EXIT_SUCCESS;
}
