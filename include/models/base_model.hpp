#ifndef BASE_MODEL_HPP
#define BASE_MODEL_HPP

#include <vector>

class BaseModel {
    public:
        virtual ~BaseModel() = default;
        virtual void fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y) = 0;
        virtual std::vector<double> predict(const std::vector<std::vector<double>>& X) const = 0;
        virtual double score(const std::vector<std::vector<double>>& X, const std::vector<double>& y) const = 0;
  private:
};

#endif
