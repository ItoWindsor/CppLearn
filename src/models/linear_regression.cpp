#include <iostream>
#include <Eigen/Dense>
#include "models/linear_regression.hpp"

void LinearRegression::fit(const Eigen::MatrixXd& X, const Eigen::vectorXd& y, std::string method) {
    switch(method) {
        case "analytical":
            weights = (X.transpose() * X).inverse() * X.transpose() * y
            bias = y.mean() - (X.rowwise().mean() * weights).mean();
}