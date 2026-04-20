/* Copyright © 2023-2024 Apple Inc. */

#include <cstring>

#include "mlx/c/device.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/c/stream.h"

int mlx_stream_tostring(mlx_string* str_, mlx_stream stream) {
  try {
    std::ostringstream os;
    os << mlx_stream_get_(stream);
    std::string str = os.str();
    mlx_string_set_(*str_, str);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}

extern "C" mlx_stream mlx_stream_new(void) {
  return mlx_stream_new_();
}

extern "C" mlx_stream mlx_stream_new_device(mlx_device dev) {
  try {
    return mlx_stream_new_(mlx::core::new_stream(mlx_device_get_(dev)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" int mlx_stream_set(mlx_stream* stream, const mlx_stream src) {
  try {
    mlx_stream_set_(*stream, mlx_stream_get_(src));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_stream_free(mlx_stream stream) {
  try {
    mlx_stream_free_(stream);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" bool mlx_stream_equal(mlx_stream lhs, mlx_stream rhs) {
  return mlx_stream_get_(lhs) == mlx_stream_get_(rhs);
}
extern "C" int mlx_stream_get_device(mlx_device* dev, mlx_stream stream) {
  try {
    mlx_device_set_(*dev, mlx_stream_get_(stream).device);
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}
extern "C" int mlx_stream_get_index(int* index, mlx_stream stream) {
  try {
    *index = mlx_stream_get_(stream).index;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_synchronize(mlx_stream stream) {
  try {
    mlx::core::synchronize(mlx_stream_get_(stream));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_get_default_stream(mlx_stream* stream, mlx_device dev) {
  try {
    mlx_stream_set_(*stream, mlx::core::default_stream(mlx_device_get_(dev)));
    return 0;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
}
extern "C" int mlx_set_default_stream(mlx_stream stream) {
  try {
    mlx::core::set_default_stream(mlx_stream_get_(stream));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" mlx_stream mlx_default_cpu_stream_new(void) {
  try {
    return mlx_stream_new_(
        mlx::core::default_stream(mlx::core::Device::DeviceType::cpu));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" mlx_stream mlx_default_gpu_stream_new(void) {
  try {
    return mlx_stream_new_(
        mlx::core::default_stream(mlx::core::Device::DeviceType::gpu));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return mlx_stream_new_();
  }
}
extern "C" int mlx_synchronize_all_gpu_streams(size_t* n_synced) {
  try {
    // Iterate every stream ever registered via `new_stream` (including
    // the secondary GPU streams used by MoE experts, fast primitives,
    // etc.) and drain each. Unlike `Stream.defaultStream.synchronize()`
    // which only drains the thread's current default, this reaches every
    // known sibling — the hook the decode-loop ICB orchestrator uses to
    // guarantee "no live GPU work anywhere" before begin_icb_recording.
    //
    // Uses the high-level `mlx::core::synchronize(Stream)` for each
    // entry, which routes through the backend's per-stream sync
    // (`metal::get_command_encoder(s).synchronize()` on Metal). No
    // iteration over internal thread_local encoder maps — so no
    // iterator-invalidation / thread-boundary hazards.
    size_t count = 0;
    for (const auto& s : mlx::core::get_streams()) {
      if (s.device == mlx::core::Device::gpu) {
        mlx::core::synchronize(s);
        ++count;
      }
    }
    if (n_synced) {
      *n_synced = count;
    }
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
