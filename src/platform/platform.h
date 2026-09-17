#include <stdbool.h>
#include <stdint.h>

#ifndef SILK_PLATFORM_PLATFORM_H
#define SILK_PLATFORM_PLATFORM_H

struct silk_platform;

enum silk_platform_event_type {
	SILK_PLATFORM_EVENT_QUIT,
	SILK_PLATFORM_EVENT_WINDOW_RESIZE,
	SILK_PLATFORM_EVENT_POINTER_MOTION,
	SILK_PLATFORM_EVENT_POINTER_BUTTON,
	SILK_PLATFORM_EVENT_POINTER_SCROLL,
	SILK_PLATFORM_EVENT_KEY,
};

struct silk_platform_event {
	enum silk_platform_event_type type;
	uint64_t timestamp_ns;

	union {
		struct {
			int32_t width;
			int32_t height;
		} window_resize;

		struct {
			int32_t x;
			int32_t y;
		} pointer_motion;

		struct {
			uint32_t button;
			bool pressed;
		} pointer_button;

		struct {
			float x;
			float y;
		} pointer_scroll;

		struct {
			uint32_t keycode;
			bool pressed;
		} key;
	} data;
};

struct silk_platform
*silk_platform_create(void);

void
silk_platform_destroy(struct silk_platform *platform);

bool
silk_platform_poll_event(struct silk_platform *platform,
	struct silk_platform_event *event);

uint64_t
silk_platform_get_time_ns(void);

#endif
