#include <stdio.h>
#include <math.h>

//  двухточечная квадратуры Гаусса
double gauss2(double (*f)(double), double a, double b) {
    double sqrt3 = sqrt(3.0);
    double x1 = (a + b)/2 - (b - a)/(2 * sqrt3);
    double x2 = (a + b)/2 + (b - a)/(2 * sqrt3);
    return (b - a)/2 * (f(x1) + f(x2));
}

// Точные многочлены(возвращает интегралы)
double F0(double x) { return x; }              
double F1(double x) { return x*x / 2; }        
double F2(double x) { return x*x*x / 3; }      
double F3(double x) { return x*x*x*x / 4; }    
double F4(double x) { return x*x*x*x*x / 5; }  

// Многочлены
double f0(double x) { return 1; }
double f1(double x) { return x; }
double f2(double x) { return x*x; }
double f3(double x) { return x*x*x; }
double f4(double x) { return x*x*x*x; }

int main() {
    double a = 0.0, b = 1.0;

    double (*functions[])(double) = { f0, f1, f2, f3, f4 };
    double (*correct_functions[])(double) = { F0, F1, F2, F3, F4 };
    const char* labels[] = {
        "f(x) = 1",
        "f(x) = x",
        "f(x) = x^2",
        "f(x) = x^3",
        "f(x) = x^4"
    };

    int n = 5;
    for (int i = 0; i < n; ++i) {
        double result = gauss2(functions[i], a, b);
        double newton = correct_functions[i](b) - correct_functions[i](a);
        double error = fabs(result - newton);

        printf("%s:\n", labels[i]);
        printf("  Gauss = %.10f, newton = %.10f, Error = %.2e\n",result, newton, error);
    }

    return 0;
}
