/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/metal.h"
#include "mlx/backend/metal/argument_buffer.h"
#include "mlx/backend/metal/device.h"
#include "mlx/backend/metal/icb.h"
#include "mlx/backend/metal/metal.h"
#include "mlx/backend/metal/persistent_ab.h"
#include "mlx/c/error.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/mlx.h"
#include "mlx/pin_session.h"

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

// Heap-owned adapter that holds everything a build-only session
// produces so a raw `void*` can cross the C-API boundary. The Swift
// side treats this as opaque.
struct BuildOnlySessionImpl {
  mlx::core::metal::CommandEncoder::BuildOnlyResult result;
};

inline BuildOnlySessionImpl* unwrap_build_only_session(
    mlx_metal_icb_build_only_session s) {
  return static_cast<BuildOnlySessionImpl*>(s.ctx);
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

extern "C" int mlx_metal_icb_begin_build_only(mlx_stream stream) {
  try {
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument(
          "[mlx_metal_icb_begin_build_only] null stream");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    enc.begin_build_only();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_end_build_only(
    mlx_stream stream,
    mlx_metal_icb_build_only_session* out_session) {
  try {
    auto* s = unwrap_stream(stream);
    if (!s || !out_session) {
      throw std::invalid_argument(
          "[mlx_metal_icb_end_build_only] null stream/out");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    auto result = enc.end_build_only();
    auto* impl = new BuildOnlySessionImpl{std::move(result)};
    out_session->ctx = impl;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_replay_with_session(
    mlx_stream stream,
    mlx_metal_icb_recorder rec,
    mlx_metal_icb_build_only_session session) {
  try {
    auto* s = unwrap_stream(stream);
    auto* r = unwrap_icb_recorder(rec);
    auto* sess = unwrap_build_only_session(session);
    if (!s || !r || !sess) {
      throw std::invalid_argument(
          "[mlx_metal_icb_replay_with_session] null stream/recorder/session");
    }
    auto& enc = mlx::core::metal::get_command_encoder(*s);
    enc.replay_icb_with_overrides(*r, sess->result.ab_overrides);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_build_only_session_count(
    mlx_metal_icb_build_only_session session,
    size_t* res) {
  try {
    auto* sess = unwrap_build_only_session(session);
    if (!sess || !res) {
      throw std::invalid_argument(
          "[mlx_metal_icb_build_only_session_count] null session/res");
    }
    *res = sess->result.ab_overrides.size();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_icb_build_only_session_free(
    mlx_metal_icb_build_only_session session) {
  try {
    delete unwrap_build_only_session(session);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

// ── Pin session bindings ──────────────────────────────────────────
namespace {
inline mlx::core::detail::PinSession* unwrap_pin_session(mlx_pin_session s) {
  return static_cast<mlx::core::detail::PinSession*>(s.ctx);
}
} // namespace

extern "C" int mlx_pin_session_begin_record(mlx_pin_session* out) {
  try {
    if (!out) {
      throw std::invalid_argument(
          "[mlx_pin_session_begin_record] null out");
    }
    auto* sess = mlx::core::detail::begin_pin_record_session();
    out->ctx = sess;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_pin_session_end_record(
    mlx_pin_session session, size_t* slot_count) {
  try {
    auto* sess = unwrap_pin_session(session);
    if (!sess || !slot_count) {
      throw std::invalid_argument(
          "[mlx_pin_session_end_record] null session/slot_count");
    }
    *slot_count = mlx::core::detail::end_pin_record_session();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_pin_session_begin_replay(mlx_pin_session session) {
  try {
    auto* sess = unwrap_pin_session(session);
    if (!sess) {
      throw std::invalid_argument(
          "[mlx_pin_session_begin_replay] null session");
    }
    mlx::core::detail::begin_pin_replay(sess);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_pin_session_end_replay(size_t* consumed) {
  try {
    if (!consumed) {
      throw std::invalid_argument(
          "[mlx_pin_session_end_replay] null consumed");
    }
    *consumed = mlx::core::detail::end_pin_replay();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_pin_session_free(mlx_pin_session session) {
  try {
    mlx::core::detail::free_pin_session(unwrap_pin_session(session));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_pin_session_slot_count(
    mlx_pin_session session, size_t* res) {
  try {
    auto* sess = unwrap_pin_session(session);
    if (!res) {
      throw std::invalid_argument(
          "[mlx_pin_session_slot_count] null res");
    }
    *res = mlx::core::detail::pin_session_slot_count(sess);
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

// ---------------------------------------------------------------------------
// PersistentAb — caller-owned argument buffer for ICB-replay-friendly
// primitives. Currently RMSNorm-only in mlx-c; other primitive layouts
// will land as Option A rolls out (see design doc).
// ---------------------------------------------------------------------------

namespace {

inline mlx::core::metal::PersistentAb* unwrap_persistent_ab(
    mlx_metal_persistent_ab ab) {
  return static_cast<mlx::core::metal::PersistentAb*>(ab.ctx);
}

} // namespace

extern "C" int mlx_metal_persistent_ab_new_rmsnorm(
    mlx_metal_persistent_ab* out,
    mlx_stream stream) {
  try {
    if (!out) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_rmsnorm] null out");
    }
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_rmsnorm] null stream");
    }
    auto& d = mlx::core::metal::device(s->device);
    using Slot = mlx::core::metal::ArgumentBuffer::Slot;
    auto* ab = new mlx::core::metal::PersistentAb(
        d,
        std::vector<Slot>{
            {Slot::Kind::BufferPtrOffset, 0, "x"},
            {Slot::Kind::BufferPtrOffset, 0, "w"},
            {Slot::Kind::BufferPtrOffset, 0, "out"},
            {Slot::Kind::Float32, 0, "eps"},
            {Slot::Kind::Scalar32, 0, "axis_size"},
            {Slot::Kind::Scalar32, 0, "w_stride"},
        });
    out->ctx = ab;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_set_float32(
    mlx_metal_persistent_ab ab,
    int slot,
    float value) {
  try {
    auto* p = unwrap_persistent_ab(ab);
    if (!p) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_set_float32] null handle");
    }
    p->set_float32(slot, value);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_set_scalar32(
    mlx_metal_persistent_ab ab,
    int slot,
    uint32_t value) {
  try {
    auto* p = unwrap_persistent_ab(ab);
    if (!p) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_set_scalar32] null handle");
    }
    p->set_scalar32(slot, value);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_set_scalar64(
    mlx_metal_persistent_ab ab,
    int slot,
    uint64_t value) {
  try {
    auto* p = unwrap_persistent_ab(ab);
    if (!p) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_set_scalar64] null handle");
    }
    p->set_scalar64(slot, value);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_set_buffer_ptr(
    mlx_metal_persistent_ab ab,
    int slot,
    const mlx_array array) {
  try {
    auto* p = unwrap_persistent_ab(ab);
    if (!p || !array.ctx) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_set_buffer_ptr] null handle/array");
    }
    const auto& a = mlx_array_get_(array);
    const auto* buf = static_cast<const MTL::Buffer*>(a.buffer().ptr());
    p->set_buffer_ptr(slot, buf, a.offset());
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_free(mlx_metal_persistent_ab ab) {
  try {
    delete unwrap_persistent_ab(ab);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_new_sdpa(
    mlx_metal_persistent_ab* out,
    mlx_stream stream) {
  try {
    if (!out) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_sdpa] null out");
    }
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_sdpa] null stream");
    }
    auto& d = mlx::core::metal::device(s->device);
    using Slot = mlx::core::metal::ArgumentBuffer::Slot;
    auto* ab = new mlx::core::metal::PersistentAb(
        d,
        std::vector<Slot>{
            {Slot::Kind::BufferPtrOffset, 0, "queries"},
            {Slot::Kind::BufferPtrOffset, 0, "keys"},
            {Slot::Kind::BufferPtrOffset, 0, "values"},
            {Slot::Kind::BufferPtrOffset, 0, "out"},
            {Slot::Kind::BufferPtrOffset, 0, "mask"},
            {Slot::Kind::BufferPtrOffset, 0, "sinks"},
            {Slot::Kind::Scalar64, 0, "k_head_stride"},
            {Slot::Kind::Scalar64, 0, "k_seq_stride"},
            {Slot::Kind::Scalar64, 0, "v_head_stride"},
            {Slot::Kind::Scalar64, 0, "v_seq_stride"},
            {Slot::Kind::Float32, 0, "scale"},
            {Slot::Kind::Scalar32, 0, "gqa_factor"},
            {Slot::Kind::Scalar32, 0, "N"},
            {Slot::Kind::Scalar32, 0, "blocks"},
            {Slot::Kind::Scalar32, 0, "mask_kv_seq_stride"},
            {Slot::Kind::Scalar32, 0, "mask_q_seq_stride"},
            {Slot::Kind::Scalar32, 0, "mask_head_stride"},
            {Slot::Kind::Scalar32, 0, "num_q_heads"},
        });
    out->ctx = ab;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_new_rope(
    mlx_metal_persistent_ab* out,
    mlx_stream stream) {
  try {
    if (!out) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_rope] null out");
    }
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_rope] null stream");
    }
    auto& d = mlx::core::metal::device(s->device);
    using Slot = mlx::core::metal::ArgumentBuffer::Slot;
    auto* ab = new mlx::core::metal::PersistentAb(
        d,
        std::vector<Slot>{
            {Slot::Kind::BufferPtrOffset, 0, "in"},
            {Slot::Kind::BufferPtrOffset, 0, "out"},
            {Slot::Kind::BufferPtrOffset, 0, "offset"},
            {Slot::Kind::Float32, 0, "scale"},
            {Slot::Kind::Scalar64, 0, "stride"},
            {Slot::Kind::Float32, 0, "base"},
        });
    out->ctx = ab;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_new_rope_freqs(
    mlx_metal_persistent_ab* out,
    mlx_stream stream) {
  try {
    if (!out) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_rope_freqs] null out");
    }
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_rope_freqs] null stream");
    }
    auto& d = mlx::core::metal::device(s->device);
    using Slot = mlx::core::metal::ArgumentBuffer::Slot;
    auto* ab = new mlx::core::metal::PersistentAb(
        d,
        std::vector<Slot>{
            {Slot::Kind::BufferPtrOffset, 0, "in"},
            {Slot::Kind::BufferPtrOffset, 0, "out"},
            {Slot::Kind::BufferPtrOffset, 0, "offset"},
            {Slot::Kind::Float32, 0, "scale"},
            {Slot::Kind::Scalar64, 0, "stride"},
            {Slot::Kind::BufferPtrOffset, 0, "freqs"},
            {Slot::Kind::Scalar64, 0, "freq_stride"},
        });
    out->ctx = ab;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_persistent_ab_new_gather_front(
    mlx_metal_persistent_ab* out,
    mlx_stream stream) {
  try {
    if (!out) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_gather_front] null out");
    }
    auto* s = unwrap_stream(stream);
    if (!s) {
      throw std::invalid_argument(
          "[mlx_metal_persistent_ab_new_gather_front] null stream");
    }
    auto& d = mlx::core::metal::device(s->device);
    using Slot = mlx::core::metal::ArgumentBuffer::Slot;
    auto* ab = new mlx::core::metal::PersistentAb(
        d,
        std::vector<Slot>{
            {Slot::Kind::BufferPtrOffset, 0, "src"},
            {Slot::Kind::BufferPtrOffset, 0, "indices"},
            {Slot::Kind::BufferPtrOffset, 0, "out"},
            {Slot::Kind::Scalar64, 0, "stride"},
            {Slot::Kind::Scalar32, 0, "size"},
        });
    out->ctx = ab;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_push_next_gather_front_persistent_ab(
    mlx_metal_persistent_ab ab) {
  try {
    auto* h = unwrap_persistent_ab(ab);
    if (!h) {
      throw std::invalid_argument(
          "[mlx_metal_push_next_gather_front_persistent_ab] null ab");
    }
    mlx::core::push_next_gather_front_persistent_ab(h);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_metal_clear_next_gather_front_persistent_abs(void) {
  try {
    mlx::core::clear_next_gather_front_persistent_abs();
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
