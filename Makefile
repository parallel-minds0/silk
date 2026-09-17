CC ?= cc

BUILD_DIR := build
OBJECT_DIR := $(BUILD_DIR)/obj
TEST_OBJECT_DIR := $(BUILD_DIR)/test-obj

CPPFLAGS := -Isrc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wstrict-prototypes -Wmissing-prototypes -g
LDFLAGS :=
LDLIBS :=

APP := $(BUILD_DIR)/silk
TEST_APP := $(BUILD_DIR)/silk-tests

CORE_SOURCES := src/core/memory.c src/core/silk.c \
	src/platform/platform.c \
	src/platform/platform_window.c
APP_SOURCES := src/main.c $(CORE_SOURCES)
TEST_SOURCES := tests/test_runtime.c $(CORE_SOURCES)

APP_OBJECTS := $(APP_SOURCES:src/%.c=$(OBJECT_DIR)/%.o)
TEST_OBJECTS := $(TEST_SOURCES:%.c=$(TEST_OBJECT_DIR)/%.o)
DEPENDENCIES := $(APP_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: all build run test clean

all: build

build: $(APP)

$(APP): $(APP_OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(TEST_APP): $(TEST_OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJECT_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c -o $@ $<

$(TEST_OBJECT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c -o $@ $<

run: $(APP)
	$(APP)

test: $(TEST_APP)
	$(TEST_APP)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPENDENCIES)
