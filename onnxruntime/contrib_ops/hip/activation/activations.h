// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/providers/hip/hip_common.h"
#include "core/providers/hip/math/unary_elementwise_ops.h"
#include "core/providers/hip/math/binary_elementwise_ops.h"
#include "core/providers/hip/activation/activations.h"
#include "activations_impl.h"

using namespace onnxruntime::hip;

namespace onnxruntime {
namespace contrib {
namespace hip {

template <typename T>
class Affine final : public UnaryElementwise {
 public:
  Affine(const OpKernelInfo& info) : UnaryElementwise(info) {
    ORT_ENFORCE(info.GetAttr("alpha", &alpha_).IsOK());
    ORT_ENFORCE(info.GetAttr("beta", &beta_).IsOK());
  }

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_ALPHA_BETA()

  float alpha_;
  float beta_;
};

template <typename T>
class ParametricSoftplus final : public UnaryElementwise {
 public:
  ParametricSoftplus(const OpKernelInfo& info) : UnaryElementwise(info) {
    ORT_ENFORCE(info.GetAttr("alpha", &alpha_).IsOK());
    ORT_ENFORCE(info.GetAttr("beta", &beta_).IsOK());
  }

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_ALPHA_BETA()

  float alpha_;
  float beta_;
};

template <typename T>
class ScaledTanh final : public UnaryElementwise {
 public:
  ScaledTanh(const OpKernelInfo& info) : UnaryElementwise(info) {
    ORT_ENFORCE(info.GetAttr("alpha", &alpha_).IsOK());
    ORT_ENFORCE(info.GetAttr("beta", &beta_).IsOK());
  }

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_ALPHA_BETA()

  float alpha_;
  float beta_;
};

template <typename T>
class Gelu final : public UnaryElementwise {
 public:
  Gelu(const OpKernelInfo& info) : UnaryElementwise(info) {}

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_NULL()
};

}  // namespace hip
}  // namespace contrib
}  // namespace onnxruntime
