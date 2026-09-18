#ifndef SILK_PLATFORM_PLATFORM_FRAME_H
#define SILK_PLATFORM_PLATFORM_FRAME_H

#include <stddef.h>
#include <stdint.h>

/*
 * Rows run from top to bottom.
 * Each pixel is four bytes in red, green, blue, alpha order.
 * Pixels are opaque: alpha must be 255.
 */

struct silk_platform_frame {
    const uint8_t *pixels;
    int32_t width;
    int32_t height;
    size_t stride;
};

#endif
