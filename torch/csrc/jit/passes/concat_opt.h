#pragma once

#include <torch/csrc/jit/ir/ir.h>

namespace torch {
namespace jit {

// Eliminates common inputs among `aten::cat` ops.
TORCH_API bool EliminateConcatCommonInputs(const std::shared_ptr<Graph>& graph);

// Expands `aten::cat` ops into `aten::copy` ops and eliminates redudancies
// in the buffers used for concatenation if possible.
TORCH_API void ExpandConcatAndEliminateRedundancy(
    const std::shared_ptr<Graph>& graph);

// Replaces the `aten::cat` ops in the given graph with variadic cat ops.
// Returns true if the graph is modified.
TORCH_API bool UseVariadicCat(const std::shared_ptr<Graph>& graph);

TORCH_API bool RemoveListMutationAndUseVariadicCat(
    const std::shared_ptr<Graph>& graph);

} // namespace jit
} // namespace torch
