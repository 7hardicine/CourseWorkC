#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#include "LeftRectangleIntegral.h"


void WriteToFile(double* s)
{
    FILE* file;
    if ((file = fopen("D:\\output.txt", "w")) == NULL) 
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
    if ((file = fopen("D:\\input.txt", "r")) == NULL)
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
