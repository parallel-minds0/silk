#include "core/silk.h"

#include "core/memory.h"

#include "platform/platform_window.h"

struct silk_runtime
{
	bool is_running;
};

struct silk_runtime *
silk_runtime_create(void)
{
	struct silk_runtime *runtime = silk_malloc(sizeof(*runtime));

	if (runtime == NULL)
		return NULL;

	runtime->is_running = true;
	return runtime;
}

void
silk_runtime_destroy(struct silk_runtime *runtime)
{
	silk_free(runtime);
}

bool
silk_runtime_is_running(const struct silk_runtime *runtime)
{
	return runtime != NULL && runtime->is_running;
}

void
silk_runtime_request_quit(struct silk_runtime *runtime)
{
	if (runtime != NULL)
		runtime->is_running = false;
}
