#include <iostream>
#include "core/dataframe.hpp"

int main() {
    std::cout << "Hello, World!\n";
    DataFrame df = DataFrame::read_csv("data/house-prices-advanced-regression-techniques/train.csv");
    df.head(10);
}
