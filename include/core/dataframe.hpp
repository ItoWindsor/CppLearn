#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <variant>
#include <iostream>

using Cell = std::variant<double, std::string, int>;
using Column = std::vector<Cell>;

class DataFrame {
    private:
        std::unordered_map<std::string, Column> data; // mapping column names to the column itself
        std::vector<std::string> column_names;
    public:
        static DataFrame read_csv(const std::string& filename, char delimiter = ',');
        void head(int n) const;
};

#endif