/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/fast.h"
#include "mlx/c/error.h"
#include "mlx/c/private/mlx.h"
#include "mlx/fast.h"

struct mlx_fast_cuda_kernel_config_cpp_ {
  std::vector<mlx::core::Shape> output_shapes;
  std::vector<mlx::core::Dtype> output_dtypes;
  std::tuple<int, int, int> grid;
  std::tuple<int, int, int> thread_group;
  std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>
      template_args;
  std::optional<float> init_value;
  bool verbose;
};

inline mlx_fast_cuda_kernel_config mlx_fast_cuda_kernel_config_new_() {
  return mlx_fast_cuda_kernel_config({new mlx_fast_cuda_kernel_config_cpp_()});
}

inline mlx_fast_cuda_kernel_config_cpp_& mlx_fast_cuda_kernel_config_get_(
    mlx_fast_cuda_kernel_config d) {
  if (!d.ctx) {
    throw std::runtime_error(
        "expected a non-empty mlx_fast_cuda_kernel_config");
  }
  return *static_cast<mlx_fast_cuda_kernel_config_cpp_*>(d.ctx);
}

inline void mlx_fast_cuda_kernel_config_free_(mlx_fast_cuda_kernel_config d) {
  if (d.ctx) {
    delete static_cast<mlx_fast_cuda_kernel_config_cpp_*>(d.ctx);
  }
}

extern "C" mlx_fast_cuda_kernel_config mlx_fast_cuda_kernel_config_new(void) {
  try {
    return mlx_fast_cuda_kernel_config_new_();
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return {nullptr};
}

extern "C" void mlx_fast_cuda_kernel_config_free(
    mlx_fast_cuda_kernel_config cls) {
  mlx_fast_cuda_kernel_config_free_(cls);
}

extern "C" int mlx_fast_cuda_kernel_config_add_output_arg(
    mlx_fast_cuda_kernel_config cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).output_shapes.push_back(
        mlx::core::Shape(shape, shape + size));
    mlx_fast_cuda_kernel_config_get_(cls).output_dtypes.push_back(
        mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_set_grid(
    mlx_fast_cuda_kernel_config cls,
    int grid1,
    int grid2,
    int grid3) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).grid =
        std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_set_thread_group(
    mlx_fast_cuda_kernel_config cls,
    int thread1,
    int thread2,
    int thread3) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).thread_group =
        std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_set_init_value(
    mlx_fast_cuda_kernel_config cls,
    float value) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_set_verbose(
    mlx_fast_cuda_kernel_config cls,
    bool verbose) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_add_template_arg_dtype(
    mlx_fast_cuda_kernel_config cls,
    const char* name,
    mlx_dtype dtype) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_add_template_arg_int(
    mlx_fast_cuda_kernel_config cls,
    const char* name,
    int value) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_cuda_kernel_config_add_template_arg_bool(
    mlx_fast_cuda_kernel_config cls,
    const char* name,
    bool value) {
  try {
    mlx_fast_cuda_kernel_config_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

struct mlx_fast_cuda_kernel_cpp_ {
  mlx::core::fast::CustomKernelFunction mkf;
  mlx_fast_cuda_kernel_cpp_(mlx::core::fast::CustomKernelFunction mkf)
      : mkf(mkf) {};
};

inline mlx_fast_cuda_kernel mlx_fast_cuda_kernel_new_(
    const std::string& name,
    const std::vector<std::string>& input_names,
    const std::vector<std::string>& output_names,
    const std::string& source,
    const std::string& header,
    bool ensure_row_contiguous,
    int shared_memory) {
  return mlx_fast_cuda_kernel({new mlx_fast_cuda_kernel_cpp_(
      mlx::core::fast::cuda_kernel(
          name,
          input_names,
          output_names,
          source,
          header,
          ensure_row_contiguous,
          shared_memory))});
}

extern "C" mlx_fast_cuda_kernel mlx_fast_cuda_kernel_new(
    const char* name,
    const mlx_vector_string input_names,
    const mlx_vector_string output_names,
    const char* source,
    const char* header,
    bool ensure_row_contiguous,
    int shared_memory) {
  try {
    return mlx_fast_cuda_kernel_new_(
        name,
        mlx_vector_string_get_(input_names),
        mlx_vector_string_get_(output_names),
        source,
        header,
        ensure_row_contiguous,
        shared_memory);
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return {nullptr};
}

inline mlx::core::fast::CustomKernelFunction& mlx_fast_cuda_kernel_get_(
    mlx_fast_cuda_kernel d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty mlx_fast_cuda_kernel");
  }
  return static_cast<mlx_fast_cuda_kernel_cpp_*>(d.ctx)->mkf;
}

inline void mlx_fast_cuda_kernel_free_(mlx_fast_cuda_kernel d) {
  if (d.ctx) {
    delete static_cast<mlx_fast_cuda_kernel_cpp_*>(d.ctx);
  }
}

extern "C" void mlx_fast_cuda_kernel_free(mlx_fast_cuda_kernel cls) {
  mlx_fast_cuda_kernel_free_(cls);
}

extern "C" int mlx_fast_cuda_kernel_apply(
    mlx_vector_array* outputs,
    mlx_fast_cuda_kernel cls,
    const mlx_vector_array inputs,
    const mlx_fast_cuda_kernel_config config,
    const mlx_stream stream) {
  try {
    auto config_ctx = mlx_fast_cuda_kernel_config_get_(config);
    mlx_vector_array_set_(
        *outputs,
        mlx_fast_cuda_kernel_get_(cls)(
            mlx_vector_array_get_(inputs),
            config_ctx.output_shapes,
            config_ctx.output_dtypes,
            config_ctx.grid,
            config_ctx.thread_group,
            config_ctx.template_args,
            config_ctx.init_value,
            config_ctx.verbose,
            mlx_stream_get_(stream)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_layer_norm(
    mlx_array* res,
    const mlx_array x,
    const mlx_array weight /* may be null */,
    const mlx_array bias /* may be null */,
    float eps,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::layer_norm(
            mlx_array_get_(x),
            (weight.ctx ? std::make_optional(mlx_array_get_(weight))
                        : std::nullopt),
            (bias.ctx ? std::make_optional(mlx_array_get_(bias))
                      : std::nullopt),
            eps,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

struct mlx_fast_metal_kernel_config_cpp_ {
  std::vector<mlx::core::Shape> output_shapes;
  std::vector<mlx::core::Dtype> output_dtypes;
  std::tuple<int, int, int> grid;
  std::tuple<int, int, int> thread_group;
  std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>
      template_args;
  std::optional<float> init_value;
  bool verbose;
};

inline mlx_fast_metal_kernel_config mlx_fast_metal_kernel_config_new_() {
  return mlx_fast_metal_kernel_config(
      {new mlx_fast_metal_kernel_config_cpp_()});
}

inline mlx_fast_metal_kernel_config_cpp_& mlx_fast_metal_kernel_config_get_(
    mlx_fast_metal_kernel_config d) {
  if (!d.ctx) {
    throw std::runtime_error(
        "expected a non-empty mlx_fast_metal_kernel_config");
  }
  return *static_cast<mlx_fast_metal_kernel_config_cpp_*>(d.ctx);
}

inline void mlx_fast_metal_kernel_config_free_(mlx_fast_metal_kernel_config d) {
  if (d.ctx) {
    delete static_cast<mlx_fast_metal_kernel_config_cpp_*>(d.ctx);
  }
}

extern "C" mlx_fast_metal_kernel_config mlx_fast_metal_kernel_config_new(void) {
  try {
    return mlx_fast_metal_kernel_config_new_();
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return {nullptr};
}

extern "C" void mlx_fast_metal_kernel_config_free(
    mlx_fast_metal_kernel_config cls) {
  mlx_fast_metal_kernel_config_free_(cls);
}

extern "C" int mlx_fast_metal_kernel_config_add_output_arg(
    mlx_fast_metal_kernel_config cls,
    const int* shape,
    size_t size,
    mlx_dtype dtype) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).output_shapes.push_back(
        mlx::core::Shape(shape, shape + size));
    mlx_fast_metal_kernel_config_get_(cls).output_dtypes.push_back(
        mlx_dtype_to_cpp(dtype));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_set_grid(
    mlx_fast_metal_kernel_config cls,
    int grid1,
    int grid2,
    int grid3) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).grid =
        std::make_tuple(grid1, grid2, grid3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_set_thread_group(
    mlx_fast_metal_kernel_config cls,
    int thread1,
    int thread2,
    int thread3) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).thread_group =
        std::make_tuple(thread1, thread2, thread3);
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_set_init_value(
    mlx_fast_metal_kernel_config cls,
    float value) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).init_value = value;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_set_verbose(
    mlx_fast_metal_kernel_config cls,
    bool verbose) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).verbose = verbose;
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_add_template_arg_dtype(
    mlx_fast_metal_kernel_config cls,
    const char* name,
    mlx_dtype dtype) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), mlx_dtype_to_cpp(dtype)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_add_template_arg_int(
    mlx_fast_metal_kernel_config cls,
    const char* name,
    int value) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_metal_kernel_config_add_template_arg_bool(
    mlx_fast_metal_kernel_config cls,
    const char* name,
    bool value) {
  try {
    mlx_fast_metal_kernel_config_get_(cls).template_args.push_back(
        std::make_pair(std::string(name), value));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

struct mlx_fast_metal_kernel_cpp_ {
  mlx::core::fast::CustomKernelFunction mkf;
  mlx_fast_metal_kernel_cpp_(mlx::core::fast::CustomKernelFunction mkf)
      : mkf(mkf) {};
};

inline mlx_fast_metal_kernel mlx_fast_metal_kernel_new_(
    const std::string& name,
    const std::vector<std::string>& input_names,
    const std::vector<std::string>& output_names,
    const std::string& source,
    const std::string& header,
    bool ensure_row_contiguous,
    bool atomic_outputs) {
  return mlx_fast_metal_kernel({new mlx_fast_metal_kernel_cpp_(
      mlx::core::fast::metal_kernel(
          name,
          input_names,
          output_names,
          source,
          header,
          ensure_row_contiguous,
          atomic_outputs))});
}

extern "C" mlx_fast_metal_kernel mlx_fast_metal_kernel_new(
    const char* name,
    const mlx_vector_string input_names,
    const mlx_vector_string output_names,
    const char* source,
    const char* header,
    bool ensure_row_contiguous,
    bool atomic_outputs) {
  try {
    return mlx_fast_metal_kernel_new_(
        name,
        mlx_vector_string_get_(input_names),
        mlx_vector_string_get_(output_names),
        source,
        header,
        ensure_row_contiguous,
        atomic_outputs);
  } catch (std::exception& e) {
    mlx_error(e.what());
  }
  return {nullptr};
}

inline mlx::core::fast::CustomKernelFunction& mlx_fast_metal_kernel_get_(
    mlx_fast_metal_kernel d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty mlx_fast_metal_kernel");
  }
  return static_cast<mlx_fast_metal_kernel_cpp_*>(d.ctx)->mkf;
}

inline void mlx_fast_metal_kernel_free_(mlx_fast_metal_kernel d) {
  if (d.ctx) {
    delete static_cast<mlx_fast_metal_kernel_cpp_*>(d.ctx);
  }
}

extern "C" void mlx_fast_metal_kernel_free(mlx_fast_metal_kernel cls) {
  mlx_fast_metal_kernel_free_(cls);
}

extern "C" int mlx_fast_metal_kernel_apply(
    mlx_vector_array* outputs,
    mlx_fast_metal_kernel cls,
    const mlx_vector_array inputs,
    const mlx_fast_metal_kernel_config config,
    const mlx_stream stream) {
  try {
    auto config_ctx = mlx_fast_metal_kernel_config_get_(config);
    mlx_vector_array_set_(
        *outputs,
        mlx_fast_metal_kernel_get_(cls)(
            mlx_vector_array_get_(inputs),
            config_ctx.output_shapes,
            config_ctx.output_dtypes,
            config_ctx.grid,
            config_ctx.thread_group,
            config_ctx.template_args,
            config_ctx.init_value,
            config_ctx.verbose,
            mlx_stream_get_(stream)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_rms_norm(
    mlx_array* res,
    const mlx_array x,
    const mlx_array weight /* may be null */,
    float eps,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rms_norm(
            mlx_array_get_(x),
            (weight.ctx ? std::make_optional(mlx_array_get_(weight))
                        : std::nullopt),
            eps,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_rms_norm_residual(
    mlx_array* res,
    const mlx_array x,
    const mlx_array residual,
    const mlx_array weight,
    float eps,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rms_norm_residual(
            mlx_array_get_(x),
            mlx_array_get_(residual),
            mlx_array_get_(weight),
            eps,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_fused_gate_activation(
    mlx_array* res,
    const mlx_array gate_up,
    int hidden_dims,
    int activation_type,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::fused_gate_activation(
            mlx_array_get_(gate_up),
            hidden_dims,
            activation_type,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_rms_norm_rope(
    mlx_array* res,
    const mlx_array x,
    const mlx_array weight,
    const mlx_array inv_freqs,
    float eps,
    int offset,
    int n_heads,
    int seq_len,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rms_norm_rope(
            mlx_array_get_(x),
            mlx_array_get_(weight),
            mlx_array_get_(inv_freqs),
            eps,
            offset,
            n_heads,
            seq_len,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_rms_norm_qgemv(
    mlx_array* res,
    const mlx_array x,
    const mlx_array norm_weight,
    const mlx_array w,
    const mlx_array scales,
    const mlx_array biases,
    float eps,
    int group_size,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rms_norm_qgemv(
            mlx_array_get_(x),
            mlx_array_get_(norm_weight),
            mlx_array_get_(w),
            mlx_array_get_(scales),
            mlx_array_get_(biases),
            eps,
            group_size,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_batched_qkv_qgemv(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w_q, const mlx_array scales_q, const mlx_array biases_q,
    const mlx_array w_k, const mlx_array scales_k, const mlx_array biases_k,
    const mlx_array w_v, const mlx_array scales_v, const mlx_array biases_v,
    int group_size,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::batched_qkv_qgemv(
            mlx_array_get_(x),
            mlx_array_get_(w_q), mlx_array_get_(scales_q), mlx_array_get_(biases_q),
            mlx_array_get_(w_k), mlx_array_get_(scales_k), mlx_array_get_(biases_k),
            mlx_array_get_(w_v), mlx_array_get_(scales_v), mlx_array_get_(biases_v),
            group_size,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_warp_moe_gate_up(
    mlx_array* res,
    const mlx_array x,
    const mlx_array w, const mlx_array scales, const mlx_array biases,
    const mlx_array indices,
    int group_size, int hidden_dims, int activation_type,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::warp_moe_gate_up(
            mlx_array_get_(x),
            mlx_array_get_(w), mlx_array_get_(scales), mlx_array_get_(biases),
            mlx_array_get_(indices),
            group_size, hidden_dims, activation_type,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_warp_moe_down(
    mlx_array* res,
    const mlx_array activated,
    const mlx_array w, const mlx_array scales, const mlx_array biases,
    const mlx_array indices, const mlx_array scores,
    int group_size, int hidden_dims, int out_dims,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::warp_moe_down(
            mlx_array_get_(activated),
            mlx_array_get_(w), mlx_array_get_(scales), mlx_array_get_(biases),
            mlx_array_get_(indices), mlx_array_get_(scores),
            group_size, hidden_dims, out_dims,
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_rope(
    mlx_array* res,
    const mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    int offset,
    const mlx_array freqs /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rope(
            mlx_array_get_(x),
            dims,
            traditional,
            (base.has_value ? std::make_optional<float>(base.value)
                            : std::nullopt),
            scale,
            offset,
            (freqs.ctx ? std::make_optional(mlx_array_get_(freqs))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_rope_dynamic(
    mlx_array* res,
    const mlx_array x,
    int dims,
    bool traditional,
    mlx_optional_float base,
    float scale,
    const mlx_array offset,
    const mlx_array freqs /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::rope(
            mlx_array_get_(x),
            dims,
            traditional,
            (base.has_value ? std::make_optional<float>(base.value)
                            : std::nullopt),
            scale,
            mlx_array_get_(offset),
            (freqs.ctx ? std::make_optional(mlx_array_get_(freqs))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}
extern "C" int mlx_fast_scaled_dot_product_attention(
    mlx_array* res,
    const mlx_array queries,
    const mlx_array keys,
    const mlx_array values,
    float scale,
    const char* mask_mode,
    const mlx_array mask_arr /* may be null */,
    const mlx_array sinks /* may be null */,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::scaled_dot_product_attention(
            mlx_array_get_(queries),
            mlx_array_get_(keys),
            mlx_array_get_(values),
            scale,
            std::string(mask_mode),
            (mask_arr.ctx ? std::make_optional(mlx_array_get_(mask_arr))
                          : std::nullopt),
            (sinks.ctx ? std::make_optional(mlx_array_get_(sinks))
                       : std::nullopt),
            mlx_stream_get_(s)));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

extern "C" int mlx_fast_scaled_dot_product_attention_sliding(
    mlx_array* res,
    const mlx_array queries,
    const mlx_array keys,
    const mlx_array values,
    float scale,
    const char* mask_mode,
    const mlx_array mask_arr /* may be null */,
    const mlx_array sinks /* may be null */,
    int window_size,
    const mlx_stream s) {
  try {
    mlx_array_set_(
        *res,
        mlx::core::fast::scaled_dot_product_attention(
            mlx_array_get_(queries),
            mlx_array_get_(keys),
            mlx_array_get_(values),
            scale,
            std::string(mask_mode),
            (mask_arr.ctx ? std::make_optional(mlx_array_get_(mask_arr))
                          : std::nullopt),
            (sinks.ctx ? std::make_optional(mlx_array_get_(sinks))
                       : std::nullopt),
            mlx_stream_get_(s),
            window_size));
  } catch (std::exception& e) {
    mlx_error(e.what());
    return 1;
  }
  return 0;
}

// ============================================================================
// TurboQuant C bridge
// ============================================================================

extern "C" int mlx_fast_turbo_score(
    mlx_array* res,
    const mlx_array q_rot, const mlx_array packed,
    const mlx_array norms, const mlx_array codebook,
    int token_count, int repeat_count, int bits, int dim,
    const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::fast::turbo_score(
        mlx_array_get_(q_rot), mlx_array_get_(packed),
        mlx_array_get_(norms), mlx_array_get_(codebook),
        token_count, repeat_count, bits, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_encode(
    mlx_vector_array* res,
    const mlx_array input, const mlx_array rotation,
    const mlx_array boundaries, const mlx_array codebook,
    int bits, int dim, const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::turbo_encode(
        mlx_array_get_(input), mlx_array_get_(rotation),
        mlx_array_get_(boundaries), mlx_array_get_(codebook),
        bits, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_encode_wht(
    mlx_vector_array* res,
    const mlx_array input, const mlx_array wht_signs,
    const mlx_array boundaries,
    int bits, int dim, const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::turbo_encode_wht(
        mlx_array_get_(input), mlx_array_get_(wht_signs),
        mlx_array_get_(boundaries),
        bits, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_flash_pass1(
    mlx_vector_array* res,
    const mlx_array q_rot,
    const mlx_array key_packed, const mlx_array key_norms, const mlx_array key_codebook,
    const mlx_array val_packed, const mlx_array val_norms, const mlx_array val_codebook,
    int token_count, int repeat_count, int num_blocks, int block_size,
    int key_bits, int value_bits, int dim, const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::turbo_flash_pass1(
        mlx_array_get_(q_rot),
        mlx_array_get_(key_packed), mlx_array_get_(key_norms), mlx_array_get_(key_codebook),
        mlx_array_get_(val_packed), mlx_array_get_(val_norms), mlx_array_get_(val_codebook),
        token_count, repeat_count, num_blocks, block_size,
        key_bits, value_bits, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_flash_pass1_causal(
    mlx_vector_array* res,
    const mlx_array q_rot,
    const mlx_array key_packed, const mlx_array key_norms, const mlx_array key_codebook,
    const mlx_array val_packed, const mlx_array val_norms, const mlx_array val_codebook,
    int token_count, int repeat_count, int num_blocks, int block_size,
    int L, int q_offset,
    int key_bits, int value_bits, int dim, const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::turbo_flash_pass1_causal(
        mlx_array_get_(q_rot),
        mlx_array_get_(key_packed), mlx_array_get_(key_norms), mlx_array_get_(key_codebook),
        mlx_array_get_(val_packed), mlx_array_get_(val_norms), mlx_array_get_(val_codebook),
        token_count, repeat_count, num_blocks, block_size,
        L, q_offset,
        key_bits, value_bits, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_flash_pass1_nr0(
    mlx_vector_array* res,
    const mlx_array q_rot,
    const mlx_array key_packed, const mlx_array key_norms, const mlx_array key_codebook,
    const mlx_array val_packed, const mlx_array val_norms, const mlx_array val_codebook,
    int token_count, int repeat_count, int num_blocks, int block_size,
    int key_bits, int value_bits, int dim, int nr0, const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::turbo_flash_pass1_nr0(
        mlx_array_get_(q_rot),
        mlx_array_get_(key_packed), mlx_array_get_(key_norms), mlx_array_get_(key_codebook),
        mlx_array_get_(val_packed), mlx_array_get_(val_norms), mlx_array_get_(val_codebook),
        token_count, repeat_count, num_blocks, block_size,
        key_bits, value_bits, dim, nr0, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_flash_pass1_nr0_causal(
    mlx_vector_array* res,
    const mlx_array q_rot,
    const mlx_array key_packed, const mlx_array key_norms, const mlx_array key_codebook,
    const mlx_array val_packed, const mlx_array val_norms, const mlx_array val_codebook,
    int token_count, int repeat_count, int num_blocks, int block_size,
    int L, int q_offset,
    int key_bits, int value_bits, int dim, int nr0, const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::turbo_flash_pass1_nr0_causal(
        mlx_array_get_(q_rot),
        mlx_array_get_(key_packed), mlx_array_get_(key_norms), mlx_array_get_(key_codebook),
        mlx_array_get_(val_packed), mlx_array_get_(val_norms), mlx_array_get_(val_codebook),
        token_count, repeat_count, num_blocks, block_size,
        L, q_offset,
        key_bits, value_bits, dim, nr0, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_flash_pass2(
    mlx_array* res,
    const mlx_array o_partials, const mlx_array m_partials, const mlx_array l_partials,
    int num_blocks, int dim, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::fast::turbo_flash_pass2(
        mlx_array_get_(o_partials), mlx_array_get_(m_partials), mlx_array_get_(l_partials),
        num_blocks, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_flash_pass2_fused(
    mlx_array* res,
    const mlx_array o_partials, const mlx_array m_partials, const mlx_array l_partials,
    const mlx_array val_rotation,
    int num_blocks, int dim, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::fast::turbo_flash_pass2_fused(
        mlx_array_get_(o_partials), mlx_array_get_(m_partials), mlx_array_get_(l_partials),
        mlx_array_get_(val_rotation),
        num_blocks, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_value(
    mlx_array* res,
    const mlx_array weights, const mlx_array packed,
    const mlx_array norms, const mlx_array codebook,
    int token_count, int repeat_count, float sparse_threshold,
    int bits, int dim, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::fast::turbo_value(
        mlx_array_get_(weights), mlx_array_get_(packed),
        mlx_array_get_(norms), mlx_array_get_(codebook),
        token_count, repeat_count, sparse_threshold,
        bits, dim, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_turbo_bulk_dequant_rotated(
    mlx_array* res,
    const mlx_array packed, const mlx_array norms, const mlx_array codebook,
    int bits, int dim, mlx_dtype output_dtype, const mlx_stream s) {
  try {
    mlx_array_set_(*res, mlx::core::fast::turbo_bulk_dequant_rotated(
        mlx_array_get_(packed), mlx_array_get_(norms),
        mlx_array_get_(codebook),
        bits, dim, mlx_dtype_to_cpp(output_dtype), mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

// ============================================================================
// GatedDelta C bridge
// ============================================================================

extern "C" int mlx_fast_gated_delta_step(
    mlx_vector_array* res,
    const mlx_array q, const mlx_array k, const mlx_array v,
    const mlx_array g, const mlx_array beta, const mlx_array state,
    const mlx_array mask /* may be null */,
    int T, bool fused,
    int Dk, int Dv, int Hk, int Hv,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::gated_delta_step(
        mlx_array_get_(q), mlx_array_get_(k), mlx_array_get_(v),
        mlx_array_get_(g), mlx_array_get_(beta), mlx_array_get_(state),
        (mask.ctx ? std::make_optional(mlx_array_get_(mask)) : std::nullopt),
        T, fused, Dk, Dv, Hk, Hv, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_gated_delta_step_fused(
    mlx_vector_array* res,
    const mlx_array q_raw, const mlx_array k_raw, const mlx_array v,
    const mlx_array a, const mlx_array b_input,
    const mlx_array a_log, const mlx_array dt_bias,
    const mlx_array state, const mlx_array mask /* may be null */,
    int T, int Dk, int Dv, int Hk, int Hv,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::gated_delta_step_fused(
        mlx_array_get_(q_raw), mlx_array_get_(k_raw), mlx_array_get_(v),
        mlx_array_get_(a), mlx_array_get_(b_input),
        mlx_array_get_(a_log), mlx_array_get_(dt_bias),
        mlx_array_get_(state),
        (mask.ctx ? std::make_optional(mlx_array_get_(mask)) : std::nullopt),
        T, Dk, Dv, Hk, Hv, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_gated_delta_step_record(
    mlx_vector_array* res,
    const mlx_array q, const mlx_array k, const mlx_array v,
    const mlx_array g, const mlx_array beta, const mlx_array state,
    const mlx_array mask /* may be null */,
    int T, int Dk, int Dv, int Hk, int Hv,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::gated_delta_step_record(
        mlx_array_get_(q), mlx_array_get_(k), mlx_array_get_(v),
        mlx_array_get_(g), mlx_array_get_(beta), mlx_array_get_(state),
        (mask.ctx ? std::make_optional(mlx_array_get_(mask)) : std::nullopt),
        T, Dk, Dv, Hk, Hv, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

extern "C" int mlx_fast_state_replay(
    mlx_vector_array* res,
    const mlx_array delta_log, const mlx_array k_tape, const mlx_array g_tape,
    const mlx_array state,
    const mlx_array mask /* may be null */,
    int T_log, int accepted,
    int Dk, int Dv, int Hk, int Hv,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::state_replay(
        mlx_array_get_(delta_log), mlx_array_get_(k_tape),
        mlx_array_get_(g_tape), mlx_array_get_(state),
        (mask.ctx ? std::make_optional(mlx_array_get_(mask)) : std::nullopt),
        T_log, accepted, Dk, Dv, Hk, Hv, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}

// ============================================================================
// SSM C bridge
// ============================================================================

extern "C" int mlx_fast_ssm_step(
    mlx_vector_array* res,
    const mlx_array X, const mlx_array A_log, const mlx_array B,
    const mlx_array C, const mlx_array D, const mlx_array dt,
    const mlx_array state,
    int Dh, int Ds, int H, int G,
    const mlx_stream s) {
  try {
    mlx_vector_array_set_(*res, mlx::core::fast::ssm_step(
        mlx_array_get_(X), mlx_array_get_(A_log), mlx_array_get_(B),
        mlx_array_get_(C), mlx_array_get_(D), mlx_array_get_(dt),
        mlx_array_get_(state),
        Dh, Ds, H, G, mlx_stream_get_(s)));
  } catch (std::exception& e) { mlx_error(e.what()); return 1; }
  return 0;
}
