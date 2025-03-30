#include "core/dataframe.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <fstream>
#include <sstream>
#include <iostream>

DataFrame::DataFrame(const DataFrame& other)
    : data(other.data), column_names(other.column_names) {}

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
                df.data[cell] = Column();  // Initialize each column in the data map.
            }
            is_header = false;

            // Debug: Print loaded column names
            std::cout << "Loaded columns: ";
            for (const auto& name : headers) {
                std::cout << name << " ";
            }
            std::cout << std::endl;
        }
        else {
            size_t col_index = 0;
            while (std::getline(ss, cell, delimiter)) {
                if (col_index >= headers.size()) {
                    std::cerr << "Warning: More cells than headers on line: " << line << std::endl;
                    break;
                }

                const std::string& column_name = headers[col_index];

                try {
                    if (df.data.find(column_name) == df.data.end()) {
                        std::cerr << "Error: Column not found in data map: " << column_name << std::endl;
                        continue;
                    }

                    if (!cell.empty()) {
                        df.data.at(column_name).push_back(std::stod(cell));
                    } else {
                        std::cerr << "Warning: Missing data for column '" << column_name << "', treating as NaN." << std::endl;
                        df.data.at(column_name).push_back(std::nan(""));
                    }
                }
                catch (const std::invalid_argument&) {
                    df.data.at(column_name).push_back(cell);  // Store as a string if it cannot be converted to double.
                }
                catch (const std::out_of_range&) {
                    std::cerr << "Error: Column '" << column_name << "' not found in the DataFrame's data map." << std::endl;
                }

                col_index++;
            }

            if (col_index < headers.size()) {
                std::cerr << "Warning: Fewer cells than headers on line: " << line << std::endl;
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


Eigen::MatrixXd DataFrame::get_values() {
  size_t ncols = data.size();
  size_t nrows = data.begin()->second.size();
 
  if (ncols == 1) {  // Single column case, return a VectorXd
      Eigen::VectorXd vector(nrows);
      const std::string& col_name = column_names[0];
      const Column& col = data.at(col_name);
      for (size_t i = 0; i < nrows; ++i) {
          if (std::holds_alternative<double>(col[i])) {
              vector(i) = std::get<double>(col[i]);
          } else {
              throw std::runtime_error("Non-numeric data encountered in column " + col_name);
          }
      }
      return vector;
  }

  Eigen::MatrixXd matrix(nrows, ncols);
  
  for (size_t j = 0; j < ncols; ++j) {
    const std::string& col_name = column_names[j];

    const Column& col = data.at(col_name);

    for (size_t i = 0; i < nrows; ++i) {
        if (std::holds_alternative<double>(col[i])) {
            matrix(i, j) = std::get<double>(col[i]);
        } else {
            throw std::runtime_error("Non-numeric data encountered in column " + col_name);
        }
    }
      }

  return matrix;
}

DataFrame DataFrame::operator[](const std::vector<std::string>& column_names) const {
    DataFrame df;

    std::cout << "Available columns: ";
    for (const auto& pair : data) {
        std::cout << pair.first << " ";
    }
    std::cout << std::endl;

    for (const auto& name : column_names) {
        if (data.find(name) == data.end()) {
            throw std::out_of_range("Column not found: " + name);
        }
        df.data[name] = data.at(name);
        df.column_names.push_back(name);
    }

    return df;
}





