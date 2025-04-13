#include "optimizer/optimizer.hpp"

Optimizer::Optimizer(ScalarFunc obj_func)
    : objective_func(obj_func) {}

Optimizer::Optimizer(MatrixFunc obj_func)
    : objective_func(obj_func) {}

const std::variant<ScalarFunc, MatrixFunc>&  Optimizer::get_objective_func() const{
  return objective_func;
}

