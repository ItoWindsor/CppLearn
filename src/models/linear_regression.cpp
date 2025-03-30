#include "models/linear_regression.hpp"
#include <Eigen/Dense>
#include <iostream>

LinearRegression::LinearRegression()
  : bias(0.0){}

double LinearRegression::score(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) const {
    Eigen::VectorXd predictions = predict(X);

    double ss_total = (y.array() - y.mean()).square().sum();
    double ss_residual = (y - predictions).squaredNorm();

    return 1.0 - (ss_residual / ss_total);
};

void LinearRegression::fit(
  const Eigen::MatrixXd& X,
  const Eigen::MatrixXd& y,
  const std::string method) {
    if (method == "analytical") {
      weights = (X.transpose() * X).inverse() * X.transpose() * y;
      bias = y.mean() - X.colwise().mean().dot(weights);
      }
}

void LinearRegression::save_model(const std::string &filename) const {
  // Implement saving model parameters to a file
}

void LinearRegression::load_model(const std::string &filename) {
  // Implement loading model parameters from a file
}


Eigen::VectorXd LinearRegression::predict(const Eigen::MatrixXd &X) const {  
  Eigen::VectorXd predictions = Eigen::VectorXd::Zero(X.rows()); 
  for(int i = 0; i < X.rows(); ++i){
    predictions[i] = X.row(i).dot(weights) + bias; 
  }  
  return predictions;
}

void LinearRegression::print_parameters() const{
  std::cout << "w_0 = " << bias << std::endl;
  for(auto i = 0; i < weights.size(); ++i){
    std::cout << "w_" << i << " = " << weights[i] << std::endl;
  }
}
