#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <variant>
#include <Eigen/Dense>

using Cell = std::variant<double, std::string>;
using Column = std::vector<Cell>;

class DataFrame {
    private:
        std::unordered_map<std::string, Column> data; // mapping column names to the column itself
        std::vector<std::string> column_names;
    public:
        DataFrame() = default;
        DataFrame(const DataFrame& other);
        static DataFrame read_csv(const std::string& filename, char delimiter = ',');
        Eigen::MatrixXd get_values(); 
        DataFrame operator[](const std::vector<std::string>& column_names) const;
        void head(const uint n) const;
        void tail(const uint n) const;
        void to_csv(const std::string& filename,char delimiter = ',') const;
};


#endif
