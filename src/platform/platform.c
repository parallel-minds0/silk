#include "platform/platform.h"

#include "core/memory.h"

#include <stdint.h>
#include <time.h>

struct silk_platform {
	void *backend;
};

struct silk_platform *
silk_platform_create(void)
{
	struct silk_platform *platform;

	platform = silk_calloc(1, sizeof(*platform));
	if (platform == NULL)
		return NULL;

	return platform;
}

void
silk_platform_destroy(struct silk_platform *platform)
{
    silk_free(platform);
}

bool
silk_platform_poll_event(struct silk_platform *platform,
	struct silk_platform_event *event)
{
	if (platform == NULL || event == NULL)
		return false;

	/*
	 * Phase 1 hsa no native event backend, Phase 2 will poll X11 here,
	 * translate an event into *event, and return true when one is ready.
	 */

	return false;
}

uint64_t
silk_platform_get_time_ns(void)
{
	struct timespec time;

	if (timespec_get(&time, TIME_UTC) != TIME_UTC)
		return 0;

	return (uint64_t) time.tv_sec * UINT64_C(1000000000) +
		(uint64_t) time.tv_nsec;
}
