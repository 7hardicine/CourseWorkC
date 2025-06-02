#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LeftRectangleIntegral.h"
#include "Menu.h"
#include "WorkWithFile.h"
#include <Windows.h>
#include <locale.h>
#include <math.h>
#define MENU_ITEM_COUNT 3

double (*f)(double x) = NULL;

int InputInt(char mess[])
{
    int num;
    printf_s("%s ", mess);
    int ok = 1;
    while (ok)
    {
        if (scanf_s("%d", &num) == 1)
        {
            int clear;
            if ((clear = getchar()) != '\n' && clear != EOF)
            {
                ok = 1;
                printf_s("\t  Ошибка, повторите ввод: ");
                while (getchar() != '\n' && clear != EOF);
            }
            else
            {
                ok = 0;
            }
        }
        else
        {
            while (getchar() != '\n');
            printf_s("\t  Ошибка, повторите ввод: ");
        }
    }
    return num;
}
double InputDouble(char mess[]) {
    double num;
    printf_s("%s ", mess);
    int ok = 1;
    while (ok)
    {
        if (scanf_s("%lf", &num) == 1)
        {
            int clear;
            if ((clear = getchar()) != '\n' && clear != EOF)
            {
                ok = 1;
                printf_s("\t  Ошибка, повторите ввод: ");
                while (getchar() != '\n' && clear != EOF);
            }
            else
            { 
                ok = 0;
            }        
        }
        else
        {
            while (getchar() != '\n');
            printf_s("\t  Ошибка, повторите ввод: ");
        }
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
    while (*n <= 0)
    {
        puts("\t  Точность интегрирования не может быть отрицательной или равной 0 !");
        *n = InputDouble("\t  Введите точность интегрирования:");
    }
    puts("\n\t  ");
}

int main() 
{
    setlocale(LC_ALL, "russian");
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