#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include "optimizer/optimizer.hpp"

class GradientDescentOptimizer : public Optimizer {

public:
  GradientDescentOptimizer(ScalarFunc obj_func, ScalarFunc derivative_obj_func);
  GradientDescentOptimizer(MatrixFunc obj_func, MatrixFunc derivative_objective_func);
  Eigen::VectorXd& compute_root(const Eigen::MatrixXd& X0, float eps, int n_iter) const;

  const std::variant<ScalarFunc, VectorFunc, MatrixFunc>& get_derivative_objective_func() const;
private:
  std::variant<ScalarFunc, VectorFunc, MatrixFunc> derivative_objective_func;
};

#endif
