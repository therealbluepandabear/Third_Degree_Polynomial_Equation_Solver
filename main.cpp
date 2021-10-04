#include <iostream>
#include <valarray>
#include <vector>
#include <iomanip>

using namespace std;

double solveEquation(double a, double b, double c, double d);

int main() {
    double a, b, c, d;


    cout << "Input a value for 'a': " << endl;
    cin >> a;

    cout << "Input a value for 'b': " << endl;
    cin >> b;

    cout << "Input a value for 'c': " << endl;
    cin >> c;

    cout << "Input a value for 'd': " << endl;
    cin >> d;

    double result = solveEquation(a, b, c, d);

    cout << "The approximation is " << result;

    return 0;
}

double solveEquation(double a, double b, double c, double d) {
    vector<double> frac_vector1{((pow(-b, 3)) / (27 * pow(a, 3))),
                               ((b * c) / (6 * pow(a, 2))),
                               -(d / (2 * a))};
    double frac_vector1_result = 0;
    for (double frac : frac_vector1) {
        frac_vector1_result += frac;
    }

    double frac_vector1_result_pow = pow(frac_vector1_result, 2);

    vector<double> frac_vector2 {(c/(3 * a)),
                                 -((pow(b, 2))/(9 * pow(2, a)))};

    double frac_vector2_result = 0;
    for (double frac : frac_vector2) {
        frac_vector2_result += frac;
    }

    double frac_vector2_result_pow3 = pow(frac_vector2_result, 3);

    double first_half = -pow(-(frac_vector1_result + sqrt(frac_vector1_result_pow + frac_vector2_result_pow3)), 1.0/3.0);
    double second_half = -pow(-(frac_vector1_result - sqrt(frac_vector1_result_pow + frac_vector2_result_pow3)), 1.0/3.0);
    double third_half = -(b/3 * a);

    double result = first_half + second_half + third_half;

    if (isnan(result)) {
        return 0;
    }
    else {
        return result;
    }
}

