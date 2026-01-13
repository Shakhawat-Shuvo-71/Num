#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


using Func = function<double(double)>;


struct TestFunction {
   string name;
   Func f;
   Func f1_exact;
   Func f2_exact;
};
//hello there! 
// ================= Numerical Formulas =================

// First derivative
double forward_diff(Func f, double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double backward_diff(Func f, double x, double h) {
    return (f(x) - f(x - h)) / h;
}

double central_diff(Func f, double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Second derivative
double forward_diff2(Func f, double x, double h) {
    return (f(x + 2 * h) - 2 * f(x + h) + f(x)) / (h * h);
}

double backward_diff2(Func f, double x, double h) {
    return (f(x) - 2 * f(x - h) + f(x - 2 * h)) / (h * h);
}

double central_diff2(Func f, double x, double h) {
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}