#include <iostream>
#include <valarray>
#include <iomanip>

using namespace std;

class PolynomialSolver final {
public:
    static double SolveEquation(const double a, const double b, const double c, const double d) {
        array<const double, 3> frac_vector1{((pow(-b, 3.0)) / (27.0 * pow(a, 3.0))),
                                    ((b * c) / (6.0 * pow(a, 2))),
                                    -(d / (2.0 * a))};
        double frac_vector1_result = 0.0;
        for (double frac : frac_vector1) {
            frac_vector1_result += frac;
        }

        double frac_vector1_result_pow = pow(frac_vector1_result, 2.0);

        array<const double, 2> frac_vector2 {(c/(3.0 * a)),
                                     -((pow(b, 2.0))/(9.0 * pow(2.0, a)))};

        double frac_vector2_result = 0.0;
        for (double frac : frac_vector2) {
            frac_vector2_result += frac;
        }

        double frac_vector2_result_pow3 = pow(frac_vector2_result, 3.0);

        double first_half = std::cbrt(frac_vector1_result + sqrt(frac_vector1_result_pow + frac_vector2_result_pow3));
        double second_half = std::cbrt(frac_vector1_result - sqrt(frac_vector1_result_pow + frac_vector2_result_pow3));
        double third_half = -(b/3.0 * a);

        double result = first_half + second_half + third_half;

        if (isnan(result)) {
            return 0.0;
        }
        else {
            return result;
        }
    }

    static std::pair<double, double> SolveEquation(const double a, const double b, const double c) {
        double positiveRoot = (-b + sqrt(pow(b, 2.0) - 4.0 * a * c))/(2.0 * a);
        double negativeRoot = (-b - sqrt(pow(b, 2.0) - 4.0 * a * c))/(2.0 * a);

        if (isnan(positiveRoot) || isnan(negativeRoot)) {
            return std::make_pair(0.0, 0.0);
        } else {
            return std::make_pair(positiveRoot, negativeRoot);
        }
    }
};

int main() {
    double a, b, c, d;
    string option;

    cout << "CHOOSE OPTION: \n\n" << "QUADRATIC (a) \n" << "CUBIC (b) \n" << endl;
    cin >> option;

    string as_lower;
    std::locale loc;
    for (auto elem : option) {
        as_lower += std::tolower(elem, loc);
    }

    if (as_lower == "a") {
        cout << "Input a value for 'a': " << endl;
        cin >> a;

        cout << "Input a value for 'b': " << endl;
        cin >> b;

        cout << "Input a value for 'c': " << endl;
        cin >> c;

        std::pair<double, double> result = PolynomialSolver::SolveEquation(a, b, c);
        cout << "The approximation is " << result.first << ", " << result.second << endl;
    } else {
        cout << "Input a value for 'a': " << endl;
        cin >> a;

        cout << "Input a value for 'b': " << endl;
        cin >> b;

        cout << "Input a value for 'c': " << endl;
        cin >> c;

        cout << "Input a value for 'd': " << endl;
        cin >> d;

        double result = PolynomialSolver::SolveEquation(a, b, c, d);
        cout << "The approximation is (may be off by 0.1 to 0.3 decimals) " << result << endl;
    }

    return 0;
}


