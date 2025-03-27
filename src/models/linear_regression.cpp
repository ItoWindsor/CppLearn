#include <iostream>
#include <Eigen/Dense>
#include "models/linear_regression.hpp"

void LinearRegression::fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y, std::string method) {
    if (method == "analytical") {
        weights = (X.transpose() * X).inverse() * X.transpose() * y;
        bias = y.mean() - (X.rowwise().mean() * weights).mean();
    }
}

void LinearRegression::save_model(const std::string& filename) const {
    // Implement saving model parameters to a file
}

void LinearRegression::load_model(const std::string& filename) {
    // Implement loading model parameters from a file
}

double score(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
  return 0.0;
}

Eigen::VectorXd LinearRegression::predict(const Eigen::MatrixXd& X) const {
    // Implement a proper prediction function
    return Eigen::VectorXd::Zero(X.rows());  // Placeholder
}