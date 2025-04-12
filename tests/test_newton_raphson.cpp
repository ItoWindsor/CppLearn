#include <gtest/gtest.h>
#include "optimizer/newton_raphson.hpp"
#include <cmath>

float quad(float x){
  return (x-3)*(x-3);
}

float quad_prime(float x){
  return 2*(x-3);
}

TEST(NewtonRaphsonTest, InitializationTest) {
    // Define simple quadratic function and its derivative
    auto f = [](float x) { return (x - 3) * (x - 3); };
    auto f_prime = [](float x) { return 2 * (x - 3); };

    // Create NewtonRaphsonOptimizer instance with these functions
    NewtonRaphsonOptimizer optimizer(f, f_prime);

    // Ensure objective function is correctly assigned and callable
    try {
        // Check that the objective function is callable with a test input
        float test_input = 0.0f;
        float objective_value = f(test_input);
        EXPECT_FLOAT_EQ(objective_value, f(test_input)) << "Objective function did not return expected result";

        // Check that the derivative function is callable with a test input
        float derivative_value = f_prime(test_input);
        EXPECT_FLOAT_EQ(derivative_value, f_prime(test_input)) << "Derivative function did not return expected result";

        // Ensure the optimizer stores the correct functions
        const ScalarFunc& stored_f = std::get<ScalarFunc>(optimizer.get_objective_func());
        const ScalarFunc& stored_f_prime = std::get<ScalarFunc>(optimizer.get_derivative_objective_func());

        // Check that the functions in the optimizer work as expected
        EXPECT_FLOAT_EQ(stored_f(test_input), f(test_input)) << "Stored objective function does not match expected result";
        EXPECT_FLOAT_EQ(stored_f_prime(test_input), f_prime(test_input)) << "Stored derivative function does not match expected result";

    } catch (const std::exception& e) {
        FAIL() << "Test failed with exception: " << e.what();
    }
}

TEST(NewtonRaphsonTest, QuadraticFunctionTemp) {
    NewtonRaphsonOptimizer optimizer(quad, quad_prime);
    float result = optimizer.compute_min(0.0f, 1e-4f, 100000);    
    std::cout << "Result: " << result << std::endl;
    EXPECT_NEAR(result, 3.0f, 0.01);
}


TEST(NewtonRaphsonTest, QuadraticFunction) {
    auto f = [](float x) { return (x - 3) * (x - 3); };
    auto f_prime = [](float x) { return 2 * (x - 3); };

    NewtonRaphsonOptimizer optimizer(f, f_prime);
    float result = optimizer.compute_min(0.0f, 1e-4f, 100);

    std::cout << "Result: " << result << std::endl;
    EXPECT_NEAR(result, 3.0f, 0.01);
}
