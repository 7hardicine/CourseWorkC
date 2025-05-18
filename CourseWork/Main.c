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
    printf_s("%s ", mess);
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
    printf_s("%s ", mess);
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
void InputSolution(double* a, double* b, double* n)
{
    puts("");
    *a = InputDouble("\n\t  Введите нижнюю границу интегрирования:");
    *b = InputDouble("\t  Введите верхнюю границу интегрирования:");
    *n = InputDouble("\t  Введите точность интегрирования:");
    puts("\n\t  ");
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