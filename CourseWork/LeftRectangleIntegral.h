#pragma once
#include <stdio.h>
#include <math.h>
#include <Windows.h>

double f1(double x);  // sin(x)
double f2(double x);  // x^2
double f3(double x);  // e^x
double f4(double x);  // 1 / (1 + x)
double f5(double x);  // ln(x + 1)
double left_rectangle_integral(double a, double b, int n, double (*f)(double));

