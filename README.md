
# Numerical Differentiation using Finite Difference Methods
Project Title

Numerical Differentiation – Forward, Backward & Central Difference Methods

Project Overview

This project is developed as part of the Numerical Methods (CSE261) course.
It implements numerical differentiation techniques using Forward Difference, Backward Difference and Central Difference methods to approximate the first and second derivatives of functions.

Numerical differentiation is essential when analytical differentiation is difficult or when function values are only available at discrete points.

Objectives

The objectives of this project are:

To implement Forward, Backward and Central Difference methods in C++

To compute first and second derivatives numerically

To compare numerical results with exact analytical derivatives

To analyze how step size (h) affects accuracy

To study truncation and numerical errors

Test Functions

The following functions are used for testing:

Function	First Derivative	Second Derivative
sin(x)	cos(x)	−sin(x)
e^x	e^x	e^x
x³	3x²	6x

These analytical derivatives are used as the reference for error calculation.

Finite Difference Formulas
First Derivative

Forward Difference
f′(x) ≈ ( f(x + h) − f(x) ) / h

Backward Difference
f′(x) ≈ ( f(x) − f(x − h) ) / h

Central Difference
f′(x) ≈ ( f(x + h) − f(x − h) ) / (2h)

Forward and Backward methods have an error of order O(h),
while Central Difference has error of order O(h²), making it more accurate.

Second Derivative

Forward Difference
f″(x) ≈ ( f(x + 2h) − 2f(x + h) + f(x) ) / h²

Backward Difference
f″(x) ≈ ( f(x) − 2f(x − h) + f(x − 2h) ) / h²

Central Difference
f″(x) ≈ ( f(x + h) − 2f(x) + f(x − h) ) / h²

Step Sizes Used

The following step sizes are used in the experiment:

h = 0.1, 0.05, 0.01, 0.005, 0.001

These values help analyze how the numerical error changes as h decreases.

Error Calculation

For each method, the absolute error is computed as:

Error = | Exact Value − Numerical Value |

Errors are calculated separately for:

Forward Difference

Backward Difference

Central Difference

Sample Numerical Result

Example for f(x) = sin(x) at x = 1

h	Forward Error	Backward Error	Central Error
0.1	0.04294	0.04114	0.00090
0.05	0.02126	0.02081	0.00023
0.01	0.00422	0.00420	0.00001

This table shows that the Central Difference method gives much smaller error.

Data Description

The program generates CSV files containing:

h, forward_error, backward_error, central_error

These data files are used to draw Error vs Step Size (h) graphs for all methods.

Graph Interpretation

From the Error vs h (log–log) graphs:

Forward and Backward methods show linear decrease in error

Central Difference shows much faster decrease

Central Difference is the most accurate method

Conclusion

Finite difference methods provide an effective way to approximate derivatives when analytical solutions are not available.

Among the three methods, the Central Difference Method gives the best accuracy for both first and second derivatives because of its higher order of convergence.

This project successfully demonstrates how numerical differentiation accuracy depends on step size and method selection.
