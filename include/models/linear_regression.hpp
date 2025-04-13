#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include "models/base_model.hpp"
#include <Eigen/Dense>

class LinearRegression : public BaseModel {

public:
  LinearRegression();
  void fit(const Eigen::MatrixXd &X, const Eigen::VectorXd &y,
           std::string fit_method = "analytical", float eps = 1e-5f , int n_iter = 100) override;
  Eigen::VectorXd predict(const Eigen::MatrixXd& X) const override;
  double score(const Eigen::MatrixXd& X,const Eigen::VectorXd& y) const override;
  void save_model(const std::string &filename) const override;
  void load_model(const std::string &filename) override;
  
  void print_parameters() const override;
private:
  Eigen::VectorXd weights;
  double bias;
};

#endif
