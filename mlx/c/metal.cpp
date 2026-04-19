/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"
#include "mlx/backend/metal/device.h"
#include "mlx/backend/metal/icb.h"
#include "mlx/backend/metal/metal.h"
#include "mlx/c/error.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/mlx.h"

#include <tuple>
#include <vector>

namespace {

inline mlx::core::metal::IndirectCommandRecorder* unwrap_icb_recorder(
    mlx_metal_icb_recorder rec) {
  return static_cast<mlx::core::metal::IndirectCommandRecorder*>(rec.ctx);
}

inline mlx::core::Stream* unwrap_stream(mlx_stream s) {
  return static_cast<mlx::core::Stream*>(s.ctx);
}

} // namespace

extern "C" int mlx_metal_is_available(bool* res) {
  try {
    *res = mlx::core::metal::is_available();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_start_capture(const char* path) {
  try {
    mlx::core::metal::start_capture(std::string(path));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_metal_stop_capture(void) {
  try {
    mlx::core::metal::stop_capture();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_reset_dispatch_counter(void) {
  try {
    mlx::core::metal::reset_dispatch_counter();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_total_dispatches(uint64_t* res) {
  try {
    *res = mlx::core::metal::total_dispatches();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_start_kernel_log(void) {
  try {
    mlx::core::metal::start_kernel_log();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_stop_kernel_log(void) {
  try {
    mlx::core::metal::stop_kernel_log();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_kernel_log_size(size_t* res) {
  try {
    *res = mlx::core::metal::kernel_log_size();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_kernel_log_at(size_t i, const char** label_out) {
  try {
    *label_out = mlx::core::metal::kernel_log_at(i);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_is_supported(bool* res) {
  try {
    auto& d = mlx::core::metal::device(mlx::core::Device::gpu);
    *res = mlx::core::metal::IndirectCommandRecorder::is_supported(d);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_begin_recording(
    mlx_stream stream,
    size_t max_commands_per_segment,
    size_t bytes_arena_cap) {
  try {
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument("[mlx_metal_icb_begin_recording] null stream");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    enc.begin_icb_recording(max_commands_per_segment, bytes_arena_cap);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_end_recording(
    mlx_stream stream,
    mlx_metal_icb_recorder* out) {
  try {
    auto* s = unwrap_stream(stream);
    if (!s || !out) {
      throw std::invalid_argument("[mlx_metal_icb_end_recording] null stream/out");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    auto recorder = enc.end_icb_recording();
    out->ctx = recorder.release();  // transfer ownership to C caller
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_abort_recording(mlx_stream stream) {
  try {
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument("[mlx_metal_icb_abort_recording] null stream");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    enc.abort_icb_recording();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_replay(
    mlx_stream stream,
    mlx_metal_icb_recorder rec) {
  try {
    auto* s = unwrap_stream(stream);
    auto* r = unwrap_icb_recorder(rec);
    if (!s || !r) {
      throw std::invalid_argument("[mlx_metal_icb_replay] null stream/recorder");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    enc.replay_icb(*r);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_recorder_num_segments(
    mlx_metal_icb_recorder rec,
    size_t* res) {
  try {
    auto* r = unwrap_icb_recorder(rec);
    if (!r || !res) {
      throw std::invalid_argument("[mlx_metal_icb_recorder_num_segments] null arg");
    }
    *res = r->num_segments();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_recorder_size(
    mlx_metal_icb_recorder rec,
    size_t* res) {
  try {
    auto* r = unwrap_icb_recorder(rec);
    if (!r || !res) {
      throw std::invalid_argument("[mlx_metal_icb_recorder_size] null arg");
    }
    *res = r->size();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_recorder_free(mlx_metal_icb_recorder rec) {
  try {
    delete unwrap_icb_recorder(rec);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_tag_binding(
    mlx_stream stream,
    uint32_t name_id,
    const mlx_array array) {
  try {
    auto* s = unwrap_stream(stream);
    if (!s || !array.ctx) {
      throw std::invalid_argument(
          "[mlx_metal_icb_tag_binding] null stream/array");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    const auto& a = mlx_array_get_(array);
    enc.tag_binding(name_id, a);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_replay_with_overrides(
    mlx_stream stream,
    mlx_metal_icb_recorder rec,
    const uint32_t* names,
    const mlx_array* arrays,
    size_t n_overrides) {
  try {
    auto* s = unwrap_stream(stream);
    auto* r = unwrap_icb_recorder(rec);
    if (!s || !r) {
      throw std::invalid_argument(
          "[mlx_metal_icb_replay_with_overrides] null stream/recorder");
    }
    if (n_overrides > 0 && (!names || !arrays)) {
      throw std::invalid_argument(
          "[mlx_metal_icb_replay_with_overrides] null names/arrays with n_overrides > 0");
    }

    std::vector<std::tuple<uint32_t, const MTL::Buffer*, int64_t>> overrides;
    overrides.reserve(n_overrides);
    for (size_t i = 0; i < n_overrides; ++i) {
      if (!arrays[i].ctx) {
        throw std::invalid_argument(
            "[mlx_metal_icb_replay_with_overrides] null mlx_array in overrides");
      }
      const auto& a = mlx_array_get_(arrays[i]);
      const auto* buf =
          static_cast<const MTL::Buffer*>(a.buffer().ptr());
      overrides.emplace_back(names[i], buf, a.offset());
    }

    auto& enc = mlx::core::metal::get_command_encoder(*s);
    enc.replay_icb_with_overrides(*r, overrides);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
