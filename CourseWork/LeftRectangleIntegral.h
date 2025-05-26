#pragma once
#include <stdio.h>
#include <math.h>
#include <Windows.h>

extern double (*f)(double x);
double f1(double x);  // sin(x)
double f2(double x);  // x^2
double f3(double x);  // e^x
double f4(double x);  // 1 / (1 + x)
double f5(double x);  // ln(x + 1)
double left_rectangle_integral(double a, double b, double n, double (*f)(double));
double InputOutput(double* a, double* b, double* n);
void InputSolution(double* a, double* b, double* n);
void WriteToFile(double* s);
void ReadFromFile(double* a, double* b, double* n);
