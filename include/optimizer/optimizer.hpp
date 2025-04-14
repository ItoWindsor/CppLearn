#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include <Eigen/Dense>
#include <functional>
#include <variant>

using ScalarFunc = std::function<float(float)>;
using VectorFunc = std::function<Eigen::VectorXd& (const Eigen::VectorXd&)>;
using MatrixFunc = std::function<Eigen::MatrixXd& (const Eigen::VectorXd&)>;

class Optimizer {

public:
  Optimizer(ScalarFunc obj_func);
  Optimizer(VectorFunc obj_func);
  
  virtual float compute_root(float x0, float eps, int n_iter) = 0; 
  virtual Eigen::VectorXd& compute_root(const Eigen::VectorXd& X0, float eps, int n_iter) const = 0; 
  
  const std::variant<ScalarFunc, VectorFunc>& get_objective_func() const;
    
  virtual ~Optimizer() = default;
private:
  std::variant<ScalarFunc,VectorFunc> objective_func;
};

#endif 

