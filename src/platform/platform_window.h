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

/*
 * Presents a complete frame matching the window's framebuffer size.
 *
 * Borrows frame and its pixels only for this call. The caller retains
 * ownership and may reuse the pixels after this function returns.
 *
 * Width and height must be positive. The pixel buffer must contain
 * at least height rows of stride bytes each.
 *
 * Returns INVALID_ARGUMENT for invalid frame metadata or dimensions.
 * Success means presentation was submitted, not necessarily displayed.
 */

enum silk_result
silk_platform_window_present(struct silk_platform_window *window,
    const struct silk_platform_frame *frame);

#endif
