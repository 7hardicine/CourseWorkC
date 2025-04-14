#include <stdio.h>
#include "LeftRectangleIntegral.h"
#include "Menu.h"
#include <Windows.h>
#include <math.h>
#define MENU_ITEM_COUNT 6

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

void solution(double (*f)(double))
{
    double a, b;
    int n;
    double s;

    a = InputDouble("Введите нижнюю границу интегрирования:");
    b = InputDouble("Введите верхнюю границу интегрирования:");
    n = InputInt("Введите точность интегрирования:");

    s = left_rectangle_integral(a, b, n, f);
    printf_s("Интеграл S = %.2lf\n", s);
}

void choice1()
{
    double (*f)(double) = 0;
    f = f1;
    solution(f);
}
void choice2()
{
    double (*f)(double) = 0;
    f = f2;
    solution(f);
}
void choice3()
{
    double (*f)(double) = 0;
    f = f3;
    solution(f);
}
void choice4()
{
    double (*f)(double) = 0;
    f = f4;
    solution(f);
}
void choice5()
{
    double (*f)(double) = 0;
    f = f5;
    solution(f);
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleTitle(L"Интегралы");
    struct MenuItem menuItems[MENU_ITEM_COUNT] =
    {
        "sin(x)", choice1,
        "x^2", choice2,
        "e^x", choice3,
        "1 / (1 + x)", choice4,
        "ln(x + 1)", choice5,
        "Выход", exit
    };

    mainMenu(menuItems, MENU_ITEM_COUNT);

    return 0;
}