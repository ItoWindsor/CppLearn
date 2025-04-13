#ifndef BASE_MODEL_HPP
#define BASE_MODEL_HPP

#include <Eigen/Dense>
#include <Eigen/src/Core/Matrix.h>

class BaseModel {
    public:
        virtual ~BaseModel() = default;
        virtual void fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y, std::string method, float eps, int n_iter) = 0;
        virtual Eigen::VectorXd predict(const Eigen::MatrixXd& X) const = 0;
        virtual double score(const Eigen::MatrixXd& X,const Eigen::VectorXd& y) const = 0;

        virtual void save_model(const std::string& filename) const = 0;
        virtual void load_model(const std::string& filename) = 0;

        virtual void print_parameters() const = 0;
    private:
};

#endif
