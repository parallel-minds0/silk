#include "platform/platform_window.h"

#include "core/memory.h"
#include "platform/platform.h"

#include "core/result.h"
#include "platform/platform_frame.h"

struct silk_platform_window {
	int32_t width;
	int32_t height;
	const char *title;
};

struct silk_platform_window *
silk_platform_window_create(struct silk_platform *platform,
	const struct silk_platform_window_config *config)
{
	struct silk_platform_window *window;

	if (platform == NULL || config == NULL)
		return NULL;

	if (config->width <= 0 || config->height <= 0)
		return NULL;

	window = silk_calloc(1, sizeof(*window));
	if (window == NULL)
		return NULL;

	window->width = config->width;
	window->height = config->height;
	window->title = config->title;

	return window;
}

void
silk_platform_window_destroy(struct silk_platform_window *window)
{
	silk_free(window);
}

int32_t
silk_platform_window_get_width(const struct silk_platform_window *window)
{
	if (window == NULL)
		return 0;

	return window->width;
}

int32_t
silk_platform_window_get_height(const struct silk_platform_window *window)
{
	if (window == NULL)
		return 0;

	return window->height;
}
