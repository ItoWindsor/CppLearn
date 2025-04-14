# Cpp Learn
![C++](https://img.shields.io/badge/-C++-2C41CB?style=for-the-badge&logo=C%2B%2B&logoColor=white)

# Description
Inspired by [Scikit-Learn](https://scikit-learn.org/), the goal of this project is to build a minimal yet functional machine learning library from scratch in C++, providing a hands-on way to explore:

- Modern C++ practices and idioms  
- Core concepts behind popular ML algorithms  
- Design patterns and clean architecture for C++ libraries  
- Efficient numerical computing with libraries like Eigen  

This project is purely educational and intended to help me (and maybe others!) gain a deeper understanding of C++ by re-implementing well-known ML tools in a low-level, performance-oriented language.

## 🚀 Features (Planned & Implemented)

- ✅ Custom `DataFrame` class with CSV loading and matrix extraction  
- ✅ Linear Regression (fit & predict)  
- 🟨 Logistic Regression  
- 🟨 Train/Test splitting  
- 🟨 Evaluation metrics (MSE, Accuracy, etc.)  
- 🟨 Support for model serialization  
- 🟨 CLI interface for training and predicting  

## 🔧 Tech Stack

- **C++21 or later**  
- [Eigen](https://eigen.tuxfamily.org/) for linear algebra  
- [Conan](https://conan.io/) for dependency management  
- CMake for build configuration  

## 🧠 Goals

- Learn C++ by building something non-trivial  
- Understand the internals of machine learning algorithms  
- Get comfortable with CMake, Conan, and numerical programming in C++  
- Have fun and build a small usable library! 

1. Clone the repo:
   ```bash
   git clone https://github.com/ItoWindsor/CppLearn.git
   cd CppLearn
   ./build.sh
