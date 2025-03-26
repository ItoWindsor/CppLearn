#include "core/dataframe.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

DataFrame DataFrame::read_csv(const std::string& filename, char delimiter) {
    DataFrame df;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return df;
    }

    std::string line;
    bool is_header = true;
    std::vector<std::string> headers;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row_data;

        if (is_header) {
            while (std::getline(ss, cell, delimiter)) {
                headers.push_back(cell);
                df.column_names.push_back(cell);
                df.data[cell] = Column();
            }
            is_header = false;
        }
        else {
            size_t col_index = 0;
            while (std::getline(ss, cell, delimiter)) {
                try {
                    df.data[headers[col_index]].push_back(std::stod(cell));
                }
                catch (const std::invalid_argument&) {
                    df.data[headers[col_index]].push_back(cell);
                }
                col_index++;
            }
        }
    }
    file.close();
    return df;
}

void DataFrame::head(const int n) const {
    for (const std::string& name : column_names) {
        std::cout << name << " " ;
    }
    std::cout << "\n----------------------------------" << std::endl;

    const size_t display_num_rows = std::min(data.begin()->second.size(), static_cast<size_t>(n));

    for (size_t i = 0; i < display_num_rows; i++) {
        for (const std::string& name : column_names) {
            std::visit([](auto&& value) { std::cout << value << "\t"; }, data.at(name)[i]);
        }
        std::cout << "\n";
    }
}
