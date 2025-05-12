#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LeftRectangleIntegral.h"
#include "Menu.h"
#include <Windows.h>
#include <math.h>
#define MENU_ITEM_COUNT 3

double (*f)(double x) = NULL;

int InputInt(char mess[])
{
    int num;
    printf_s("%s\n", mess);
    while (scanf_s("%d", &num) == 0)
    {
        while (getchar() != '\n');
        puts("Что-то пошло не так, повторите ввод:");
    }
    return num;
}
double InputDouble(char mess[])
{
    double num;
    printf_s("%s\n", mess);
    while (scanf_s("%lf", &num) == 0)
    {
        while (getchar() != '\n');
        puts("Что-то пошло не так, повторите ввод:");
    }
    return num;
}

void FunctionChoice()
{
    MenuFuntionChoice();
}

void Calculation()
{
    MenuInput();
}

void ReadFromFile(double* a, double* b, double* n)
{
    FILE* file;
    if (file = fopen("D:\\input.txt", "r") == NULL)
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

//void solution()
//{
//    double a, b, n;
//    double s;
//
//    a = InputDouble("Введите нижнюю границу интегрирования:");
//    b = InputDouble("Введите верхнюю границу интегрирования:");
//    n = InputDouble("Введите точность интегрирования:");
//
//   
//}
void InputSolution(double* a, double* b, double* n)
{
    *a = InputDouble("Введите нижнюю границу интегрирования:");
    *b = InputDouble("Введите верхнюю границу интегрирования:");
    *n = InputDouble("Введите точность интегрирования:");
}
void InputOutput(double* a, double* b, double* n)
{
    double s;
    s = left_rectangle_integral(*a, *b, 1 / *n, f);
    printf_s("Интеграл S = %.2lf\n", s);
}
//void InputFromKeyboard()
//{
//    solution();
//}

void WriteToFile(double* a, double* b, double* n)
{
    FILE* file;
    if ((file = fopen("C:\\Users\\Юрий\\source\\repos\\7hardicine\\CourseWorkC\\input.txt", "w"))== NULL)
    {
        perror("Ошибка чтения: ");
        system("pause");
        return;
    }
    else
    {
        fprintf(file, "%lf %lf %lf", *a, *b, *n);
        fclose(file);
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleTitle(L"Интегралы");
    struct MenuItem menuItems[MENU_ITEM_COUNT] =
    {
        "Выбор функции", FunctionChoice,
        "Вычисление", Calculation,
        "Выход", exit
    };

    mainMenu(menuItems, MENU_ITEM_COUNT);

    return 0;
}