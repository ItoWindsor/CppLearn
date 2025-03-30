#include <iostream>
#include "core/dataframe.hpp"
#include <models/linear_regression.hpp>

int main() {
  
  DataFrame df = DataFrame::read_csv("data/linear_regression_data.csv"); 

  std::vector<std::string> features = {"Feature_1", "Feature_2", "Feature_3", "Feature_4", "Feature_5"};
  DataFrame sub_df = df[features];
  Eigen::MatrixXd mat_X = sub_df.get_values();
  Eigen::MatrixXd mat_y = df[{"Target"}].get_values();
  
  std::cout << "mat_X " << std::endl;
  std::cout << "number of rows : " << mat_X.rows() << std::endl;
  std::cout << "number of col : " << mat_X.cols() << std::endl;
  
  std::cout << "mat_y " << std::endl;
  std::cout << "number of rows : " << mat_y.rows() << std::endl;
  std::cout << "number of col : " << mat_y.cols() << std::endl;
  LinearRegression model;
  model.fit(mat_X,mat_y);
  model.print_parameters();
}


