#ifndef SILK_PLATFORM_PLATFORM_WINDOW_H
#define SILK_PLATFORM_PLATFORM_WINDOW_H

#include <stdint.h>

struct silk_platform;
struct silk_platform_window;

struct silk_platform_window_config {
	int32_t width;
	int32_t height;
	const char *title;
};

struct silk_platform_window *
silk_platform_window_create(struct silk_platform *platform,
	const struct silk_platform_window_config *config);

void
silk_platform_window_destroy(struct silk_platform_window *window);

int32_t
silk_platform_window_get_width(const struct silk_platform_window *window);

int32_t
silk_platform_window_get_height(const struct silk_platform_window *window);

#endif
