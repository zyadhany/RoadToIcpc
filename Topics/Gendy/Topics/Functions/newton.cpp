// #include "Eigen/Dense" // uncomment this, and check the result

#include <functional>
#include <iostream>
#include <limits>
#include <cmath>

typedef std::function<double(double)> RealFunc;
typedef std::function<double(std::function<double(double)>, double)> RealFuncDerivative;

double FibonacciFunc(double x) {
    return pow(x, 3) + 2.0 * pow(x, 2) + 10.0 * x - 20.0;
}

double derivative(RealFunc f, double x) {
    double h = sqrt(std::numeric_limits<double>::epsilon());
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

double NewtonsMethod(RealFunc f, RealFuncDerivative d, double x0, double precision) {
    double x = x0;
    for (size_t i = 0;; i++) {
        x = x - (f(x) / d(f, x));

        if (abs(f(x)) < precision) {
            return x;
        }
    }
}

int main() {
    RealFunc f{FibonacciFunc};
    RealFuncDerivative d{derivative};

    std::cout << NewtonsMethod(f, d, 1.0, 10e-4) << "\n";
}






--------------



#include <iostream>
#include <cmath>

// Function representing the equation (replace with your actual function)
double f(double x) {
  return x * x - 2.0; // Example: x^2 - 2
}

// Derivative of the function (replace with the derivative of your function)
double df(double x) {
  return 2 * x; // Example: derivative of x^2 - 2 is 2x
}

// Function to implement Newton's method
double newtonRaphson(double initialGuess, double tolerance, int maxIterations) {
  double x = initialGuess;
  for (int i = 0; i < maxIterations; ++i) {
    double h = f(x) / df(x);
    if (std::abs(h) < tolerance) {
      return x;
    }
    x = x - h;
  }
  std::cerr << "Failed to converge within " << maxIterations << " iterations." << std::endl;
  return x; // Return last approximation in case of non-convergence
}

int main() {
  double initialGuess = 1.5; // Initial guess for the root
  double tolerance = 1e-6;    // Allowed error
  int maxIterations = 100;   // Maximum number of iterations

  double root = newtonRaphson(initialGuess, tolerance, maxIterations);
  std::cout << "Root of the equation: " << root << std::endl;

  return 0;
}
