#include <iostream>
#include "optimizer/newton_raphson.hpp"
#include <Eigen/Dense>
#include <stdexcept>
#include "optimizer/optimizer.hpp"

NewtonRaphsonOptimizer::NewtonRaphsonOptimizer(ScalarFunc obj_func, ScalarFunc derivative_objc_func)
  : Optimizer(obj_func), derivative_objective_func(derivative_objc_func) {}

NewtonRaphsonOptimizer::NewtonRaphsonOptimizer(MatrixFunc obj_func, MatrixFunc derivative_obj_func)
  : Optimizer(obj_func), derivative_objective_func(derivative_obj_func) {}


const std::variant<ScalarFunc, MatrixFunc>&  NewtonRaphsonOptimizer::get_derivative_objective_func() const{
  return derivative_objective_func;
}

float NewtonRaphsonOptimizer::compute_root(float x0, float eps, int n_iter) {
    try {
        if (!std::holds_alternative<ScalarFunc>(get_objective_func())) {
            throw std::runtime_error("Objective function is not of type ScalarFunc.");
        }

        if (!std::holds_alternative<ScalarFunc>(get_derivative_objective_func())) {
            throw std::runtime_error("Derivative objective function is not of type ScalarFunc.");
        }

        const ScalarFunc& f = std::get<ScalarFunc>(get_objective_func());
        const ScalarFunc& f_prime = std::get<ScalarFunc>(get_derivative_objective_func());

        float xk = x0;
        int count = 0;

        while (std::abs(f(xk)) > eps && count < n_iter) {
            float fk = f(xk);
            float fk_p = f_prime(xk);

            if (fk_p == 0) {
                throw std::runtime_error("Derivative is zero at x = " + std::to_string(xk));
            }

            xk = xk - (fk / fk_p);
            count += 1;

        }

        return xk;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw std::runtime_error("Error in Newton-Raphson optimizer: " + std::string(e.what()));
    }
}


Eigen::MatrixXd NewtonRaphsonOptimizer::compute_root(Eigen::MatrixXd& X0, float eps, int n_iter) const{
  const MatrixFunc& f = std::get<MatrixFunc>(objective_func);
  const MatrixFunc& f_prime = std::get<MatrixFunc>(derivative_objective_func);
  
  Eigen::MatrixXd xk = X0;
  int count = 0;
  
  
  return xk;
}
