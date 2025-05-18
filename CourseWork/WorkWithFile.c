#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#include "LeftRectangleIntegral.h"


void InputOutput(double* a, double* b, double* n)
{
    double s;
    s = left_rectangle_integral(*a, *b, 1 / *n, f);
    printf_s("\n\n\t  ������ �������: %.2lf\n\t  ������� �������: %.2lf\n\t  �������� ��������������: %.8lf\n\t  �������� S = %.2lf\n\n\t  ", *a, *b, *n, s);
}
void WriteToFile(double* a, double* b, double* n)
{
    FILE* file;
    if ((file = fopen("C:\\Users\\Hardicine\\source\\repos\\CourseWorkC\\input.txt", "w")) == NULL)
    {
        perror("������ ������: ");
        system("pause");
        return;
    }
    else
    {
        fprintf(file, "%lf %lf %lf", *a, *b, *n);
        fclose(file);
    }
}
void ReadFromFile(double* a, double* b, double* n)
{
    FILE* file;
    if ((file = fopen("C:\\Users\\Hardicine\\source\\repos\\CourseWorkC\\input.txt", "r")) == NULL)
    {
        perror("������ ������: ");
        system("pause");
        return 1;
    }
    else
    {
        int counter = fscanf(file, "%lf %lf %lf", a, b, n);
        if (counter != 3)
        {
            printf_s("������, �������� ����������: %d", counter);
        }
        fclose(file);
    }
}
