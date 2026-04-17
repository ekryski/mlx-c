/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_METAL_H
#define MLX_METAL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "mlx/c/array.h"
#include "mlx/c/closure.h"
#include "mlx/c/distributed_group.h"
#include "mlx/c/io_types.h"
#include "mlx/c/map.h"
#include "mlx/c/stream.h"
#include "mlx/c/string.h"
#include "mlx/c/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup metal Metal specific operations
 */
/**@{*/

int mlx_metal_is_available(bool* res);
int mlx_metal_start_capture(const char* path);
int mlx_metal_stop_capture(void);

/**
 * Reset the cumulative dispatch counter on the default Metal command
 * encoder. Call before a region of interest, then `mlx_metal_total_dispatches`
 * after, to count the Metal kernel launches MLX issued for that region.
 * Useful for auditing per-token dispatch counts (e.g. for ICB feasibility
 * studies).
 */
int mlx_metal_reset_dispatch_counter(void);

/** Read the cumulative dispatch counter since the last reset. */
int mlx_metal_total_dispatches(uint64_t* res);

/**
 * Start recording Metal kernel pipeline-state labels on every dispatch.
 * Calling this clears any prior log. Enables the ICB dispatch-list
 * stability audit.
 */
int mlx_metal_start_kernel_log(void);

/** Stop recording kernel labels. */
int mlx_metal_stop_kernel_log(void);

/** Number of entries in the current kernel log. */
int mlx_metal_kernel_log_size(size_t* res);

/**
 * Write the kernel label at index i into `*label_out`. Returns nullptr
 * in `*label_out` if i is out of range. The C string is valid until the
 * next `mlx_metal_start_kernel_log()`.
 */
int mlx_metal_kernel_log_at(size_t i, const char** label_out);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
