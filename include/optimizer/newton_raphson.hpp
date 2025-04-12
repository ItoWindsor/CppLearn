#ifndef NEWTON_RAPHSON_HPP
#define NEWTON_RAPHSON_HPP

#include "optimizer/optimizer.hpp"

class NewtonRaphsonOptimizer : public Optimizer {

public:
  NewtonRaphsonOptimizer(ScalarFunc obj_func, ScalarFunc derivative_objc_func);
  NewtonRaphsonOptimizer(MatrixFunc obj_func, MatrixFunc derivative_objective_func);
  float compute_min(float x0, float eps, int n_iter);
  Eigen::MatrixXd compute_min(Eigen::MatrixXd& X0, float eps, int n_iter) const;

  const std::variant<ScalarFunc, MatrixFunc>& get_derivative_objective_func() const;

protected:
  std::variant<ScalarFunc,MatrixFunc> derivative_objective_func;
};

#endif 
