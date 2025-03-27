#include <iostream>
#include "core/dataframe.hpp"
#include <filesystem>

int main() {
    std::cout << "Hello, World!\n";
    DataFrame df = DataFrame::read_csv("data/house-prices-advanced-regression-techniques/train.csv");
    df.head(10);
    std::cout << "tail" << std::endl;
    df.tail(10);
}