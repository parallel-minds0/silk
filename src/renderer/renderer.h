#ifndef SILK_RENDERER_RENDERER_H
#define SILK_RENDERER_RENDERER_H

#include "core/geometry.h"
#include "core/result.h"

#include <stdint.h>

struct silk_platform_window;
struct silk_renderer;

struct silk_color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

/*
 * Borrows window, which must outlive the renderer.
 * On failure, leaves renderer_out unchanged.
 */

enum silk_result
silk_renderer_create(struct silk_platform_windw *window,
    struct silk_renderer **renderer_out);

/* Accepts NULL. Releases all renderer-owned resources. */

void
silk_renderer_destroy(struct silk_renderer *renderer);

/*
 * Updates the framebuffer dimensions.
 * Requires positive dimensions and no active frame.
 * On failure, preserves the previous framebuffer.
 */

enum silk_result
silk_renderer_resize(struct silk_renderer *renderer,
    int32_t width, int32_t height);

/* Starts a frame. Fails if a frame is already active. */

enum silk_result
silk_renderer_begin_frame(struct silk_renderer *renderer);

/*
 * Drawing requires an active frame.
 * Coordinates are framebuffer pixels; drawing clips to its bounds.
 * Colors use straight alpha. Clear replaces pixels; fill blends them.
 */

void
silk_renderer_clear(struct silk_renderer *renderer,
    struct silk_color color);

void
silk_renderer_fill_rect(struct silk_renderer *renderer,
    const struct silk_rect *rect,
    struct silk_color color)

/*
 * Presents the frame through the platform.
 * Ends the active frame even if presentation fails.
 */

enum silk_result
silk_renderer_end_frame(struct silk_renderer *renderer);

#endif
