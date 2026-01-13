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

// now write the code of your part here . then save it by cntrl s. // ========================= MAIN =========================

int main() {

    vector<TestFunction> funcs = {
        {"f(x) = sin(x)",
            [](double x) { return sin(x); },
            [](double x) { return cos(x); },
            [](double x) { return -sin(x); }
        },
        {"f(x) = e^x",
            [](double x) { return exp(x); },
            [](double x) { return exp(x); },
            [](double x) { return exp(x); }
        },
        {"f(x) = x^3",
            [](double x) { return x * x * x; },
            [](double x) { return 3 * x * x; },
            [](double x) { return 6 * x; }
        }
    };

    cout << "\n=============================================\n";
    cout << "          NUMERICAL DIFFERENTIATION           \n";
    cout << "=============================================\n\n";

    cout << "Choose function:\n";
    for (size_t i = 0; i < funcs.size(); i++) {
        cout << " " << i + 1 << ". " << funcs[i].name << "\n";
    }

    int choice;
    while (true) {
        cout << "\nEnter choice (1-" << funcs.size() << "): ";
        cin >> choice;
        if (choice >= 1 && choice <= (int)funcs.size()) break;
        cout << "Invalid choice! Please enter again.\n";
    }

    double x;
    cout << "Enter x: ";
    cin >> x;

    vector<double> hs = {0.1, 0.05, 0.01, 0.005, 0.001};
    auto t = funcs[choice - 1];

    string base = "function_" + to_string(choice);

    ofstream csv1(base + "_first.csv");
    ofstream csv2(base + "_second.csv");

    csv1 << "h,forward_error,backward_error,central_error\n";
    csv2 << "h,forward2_error,backward2_error,central2_error\n";

    cout << fixed << setprecision(8);

    // ================= First Derivative =================
    cout << "\n--------------- First Derivative ----------------\n";
    cout << left
         << setw(10) << "h"
         << setw(14) << "Forward"
         << setw(14) << "Backward"
         << setw(14) << "Central"
         << setw(14) << "Exact"
         << setw(14) << "|Err(F)|"
         << setw(14) << "|Err(B)|"
         << setw(14) << "|Err(C)|"
         << "\n";

    for (double h : hs) {
        double fwd = forward_diff(t.f, x, h);
        double bwd = backward_diff(t.f, x, h);
        double cen = central_diff(t.f, x, h);
        double exact = t.f1_exact(x);

        double errF = fabs(exact - fwd);
        double errB = fabs(exact - bwd);
        double errC = fabs(exact - cen);

        cout << setw(10) << setprecision(3) << fixed << h << setprecision(8)
             << setw(14) << fwd
             << setw(14) << bwd
             << setw(14) << cen
             << setw(14) << exact
             << setw(14) << errF
             << setw(14) << errB
             << setw(14) << errC
             << "\n";

        csv1 << h << "," << errF << "," << errB << "," << errC << "\n";
    }

    // ================= Second Derivative =================
    cout << "\n-------------- Second Derivative ---------------\n";
    cout << left
         << setw(10) << "h"
         << setw(14) << "Forward2"
         << setw(14) << "Backward2"
         << setw(14) << "Central2"
         << setw(14) << "Exact2"
         << setw(14) << "|Err(F2)|"
         << setw(14) << "|Err(B2)|"
         << setw(14) << "|Err(C2)|"
         << "\n";

    for (double h : hs) {
        double fwd = forward_diff2(t.f, x, h);
        double bwd = backward_diff2(t.f, x, h);
        double cen = central_diff2(t.f, x, h);
        double exact = t.f2_exact(x);

        double errF = fabs(exact - fwd);
        double errB = fabs(exact - bwd);
        double errC = fabs(exact - cen);

        cout << setw(10) << setprecision(3) << fixed << h << setprecision(8)
             << setw(14) << fwd
             << setw(14) << bwd
             << setw(14) << cen
             << setw(14) << exact
             << setw(14) << errF
             << setw(14) << errB
             << setw(14) << errC
             << "\n";

        csv2 << h << "," << errF << "," << errB << "," << errC << "\n";
    }

    csv1.close();
    csv2.close();

    cout << "\n[✓] CSV files generated successfully.\n";
    cout << "[✓] Program finished successfully.\n";

    return 0;
}