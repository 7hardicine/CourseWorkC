#include <stdio.h>
#include <math.h>
#include <Windows.h>

double f1(double x) { return sin(x); }       // sin(x)
double f2(double x) { return x * x; }        // x^2
double f3(double x) { return exp(x); }       // e^x
double f4(double x) { return 1 / (1 + x); }  // 1 / (1 + x)
double f5(double x) { return log(x + 1); }   // ln(x + 1)
double left_rectangle_integral(double a, double b, double n, double (*f)(double))
{
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}
