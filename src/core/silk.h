#ifndef SILK_CORE_SILK_H
#define SILK_CORE_SILK_H

#include <stdbool.h>

struct silk_runtime;
struct silk_runtime *silk_runtime_create(void);

void
silk_runtime_destroy(struct silk_runtime *runtime);

bool
silk_runtime_is_running(const struct silk_runtime *runtime);

void
silk_runtime_request_quit(struct silk_runtime *runtime);

#endif
