#ifndef NEWTON_RAPHSON_HPP
#define NEWTON_RAPHSON_HPP

#include "optimizer/optimizer.hpp"

class NewtonRaphsonOptimizer : public Optimizer {

public:
  NewtonRaphsonOptimizer(ScalarFunc obj_func, ScalarFunc derivative_objc_func);
  NewtonRaphsonOptimizer(VectorFunc obj_func, MatrixFunc derivative_objective_func);
  float compute_root(float x0, float eps, int n_iter);
  Eigen::VectorXd& compute_root(const Eigen::VectorXd& X0, float eps, int n_iter) const;

  const std::variant<ScalarFunc, MatrixFunc>& get_derivative_objective_func() const;

private:
  std::variant<ScalarFunc,MatrixFunc> derivative_objective_func;
};

#endif 
