# Silk

## A Simple Infinite-Canvas Desktop Prototype

Silk is a self-contained, minimal desktop prototype that uses an infinite 2D
plane as its primary navigation space. It is written in C and will ship with a
small interpreted-C environment for styles.

The workflow draws inspiration from macOS and GNOME.

## Current scope

The first vertical slice owns one native X11 host window and renders the Silk
desktop canvas inside it. Its visible test windows are Silk-managed model and
renderer objects, not arbitrary external X11 clients.

Before backend work begins, the project completes its backend-neutral runtime,
platform-window, event, renderer-surface, geometry, and frame-loop interfaces.
Those contracts keep X11 details out of core and desktop code and make model
behavior testable without a display server.

## Build targets and output

Build output uses `build/<os>-<arch>/`, with lowercase OS and architecture
names separated by a hyphen. Use `amd64` for x86-64 and `arm64` for AArch64.
For example, `linux-amd64` and `netbsd-arm64` follow the naming convention.
Only `linux-amd64` is currently supported; other targets are future work.

```sh
make                         # Build linux-amd64 (the default)
make TARGET=linux-amd64      # Select the target explicitly
make test                   # Build and run the target's tests
make run                    # Build and run the target's application
make clean                  # Remove only the selected target's output
```

Each target has its own binaries, objects, and dependency files:

```text
build/
  linux-amd64/
    silk
    silk-tests
    obj/
    test-obj/
```

`TARGET` selects the output namespace and supported build target. It does not
install or select a cross-compiler: use a compiler targeting Linux amd64 for
this initial target. `run` and `test` execute binaries on the local machine.
Future targets require compiler and backend support before they are enabled.

The older `build/obj/`, `build/test-obj/`, `build/silk`, and `build/silk-tests`
paths are no longer used. Target-specific cleaning leaves these legacy paths
alone.

Work in progress.
