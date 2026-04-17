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

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
