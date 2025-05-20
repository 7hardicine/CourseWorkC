#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#include "LeftRectangleIntegral.h"


double InputOutput(double* a, double* b, double* n)
{
    double s;
    s = left_rectangle_integral(*a, *b, 1 / *n, f);
    printf_s("\n\n\t  Нижняя граница: %.2lf\n\t  Верхняя граница: %.2lf\n\t  Точность интегрирования: %.8lf\n\t  Интеграл S = %.2lf\n\n\t  ", *a, *b, *n, s);
    return s;
}
void WriteToFile(double* s)
{
    FILE* file;
    if ((file = fopen("C:\\Users\\Hardicine\\source\\repos\\CourseWorkC\\output.txt", "w")) == NULL)
    {
        perror("Ошибка чтения: ");
        system("pause");
        return;
    }
    else
    {
        fprintf(file, "%lf", *s);
        fclose(file);
        puts("Запись в файл прошла успешно!");
    }
}
void ReadFromFile(double* a, double* b, double* n)
{
    FILE* file;
    if ((file = fopen("C:\\Users\\Hardicine\\source\\repos\\CourseWorkC\\input.txt", "r")) == NULL)
    {
        perror("Ошибка чтения: ");
        system("pause");
        return 1;
    }
    else
    {
        int counter = fscanf(file, "%lf %lf %lf", a, b, n);
        if (counter != 3)
        {
            printf_s("Ошибка, прочтено переменных: %d", counter);
        }
        fclose(file);
    }
}
