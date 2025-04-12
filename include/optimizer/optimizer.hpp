#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include <Eigen/Dense>
#include <functional>
#include <variant>

using ScalarFunc = std::function<float(float)>;
using MatrixFunc = std::function<float(const Eigen::MatrixXd&)>;

class Optimizer {

public:
  Optimizer(ScalarFunc obj_func);
  Optimizer(MatrixFunc obj_func);
  
  virtual float compute_min(float x0, float eps, int n_iter) = 0; 
  virtual Eigen::MatrixXd compute_min(Eigen::MatrixXd& X0, float eps, int n_iter) const = 0; 
  
  const std::variant<ScalarFunc, MatrixFunc>& get_objective_func() const;
    
  virtual ~Optimizer() = default;
protected:
  std::variant<ScalarFunc,MatrixFunc> objective_func;
};

#endif 

