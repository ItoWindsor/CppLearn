#ifndef BASE_MODEL_HPP
#define BASE_MODEL_HPP

#include <vector>
#include <Eigen/Dense>

class BaseModel {
    public:
        virtual ~BaseModel() = default;
        virtual void fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y, std::string method) = 0;
        Eigen::VectorXd predict(const Eigen::MatrixXd& X) const = 0;
        virtual double score(const std::vector<std::vector<double>>& X, const std::vector<double>& y) const = 0;

        virtual void save_model(const std::string& filename) const;
        virtual void load_model(const std::string& filename);

        virtual void print_parameters() const = 0;
    private:
};

#endif
