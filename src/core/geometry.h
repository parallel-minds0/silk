#ifndef SILK_CORE_GEOMETRY_H
#define SILK_CORE_GEOMETRY_H

#include <stdint.h>

struct silk_point {
    int32_t x;
    int32_t y;
};

struct silk_rect {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
};
