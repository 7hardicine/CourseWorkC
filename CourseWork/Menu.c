#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#include "Menu.h"
#include "WorkWithFile.h"
#include "LeftRectangleIntegral.h"
#define MENU_FUNCTIONS_COUNT 6
#define MENU_INPUT_COUNT 3

void itemOutput(int row_number, char* text, HANDLE handle, WORD color)
{
	COORD cursorPosition = { 10,row_number };
	SetConsoleTextAttribute(handle, color);
	SetConsoleCursorPosition(handle, cursorPosition);
	printf_s("%s", text);
}
void itemActivate(int row_number, char* text, HANDLE handle)
{
	itemOutput(row_number, text, handle, FOREGROUND_RED);
}
void itemHide(int row_number, char* text, HANDLE handle)
{
	itemOutput(row_number, text, handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void showCursor(bool visible, HANDLE handle)
{
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(handle, &ccInfo);
}
void selectItem(int* activeItem, struct MenuItem* items, int itemCount, HANDLE handle)
{
	int iKey = 67;
	while (iKey != ENTER)
	{
		if (_kbhit())
		{
			iKey = _getch();
			switch (iKey)
			{
			case KEY_ARROW_UP:
				if (*activeItem > 0)
				{
					itemHide(*activeItem + 5, items[*activeItem].text, handle);
					(*activeItem)--;
					itemActivate(*activeItem + 5, items[*activeItem].text, handle);

				}
				break;
			case KEY_ARROW_DOWN:
				if (*activeItem < itemCount - 1)
				{
					itemHide(*activeItem + 5, items[*activeItem].text, handle);
					(*activeItem)++;
					itemActivate(*activeItem + 5, items[*activeItem].text, handle);
				}
				break;
			case ESC:
				exit(0);
			}
		}
	}
}
void mainMenu(struct MenuItem* items, int itemCount)
{
	COORD cursorPosition;
	cursorPosition.X = 10;
	int activeItem = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, NULL);
	bool run = true;
	while (run)
	{
		system("cls");
		showCursor(false, handle);
		itemOutput(2, "ВЫЧИСЛЕНИЕ ОПРЕДЕЛЕННОГО ИНТЕГРАЛА МЕТОДОМ ЛЕВОСТОРОННИХ ПРЯМОУГОЛЬНИКОВ", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < itemCount; i++)
		{
			itemHide(i + 5, items[i].text, handle);
		}
		itemActivate(activeItem + 5, items[activeItem].text, handle);
		selectItem(&activeItem, items, itemCount, handle);
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");
		showCursor(true, handle);
		items[activeItem].handler();
		if (strcmp(items[activeItem].text, "Выход") == 0)
		{
			run = false;
		}
	}
}
void MenuFuntionChoice()
{
	int activeItem = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, NULL);
	bool run = true;
	struct MenuItem functions[MENU_FUNCTIONS_COUNT] =
	{
		"sin(x)", NULL,
		"x^2", NULL,
		"e^x", NULL,
		"1 / (1 + x)", NULL,
		"ln(x + 1)", NULL,
		"Выход", NULL
	};
	while (run)
	{
		system("cls");
		showCursor(false, handle);
		itemOutput(2, "ВЫБЕРИТЕ ФУНКЦИЮ", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < MENU_FUNCTIONS_COUNT; i++)
		{
			itemHide(i + 5, functions[i].text, handle);
		}
		itemActivate(activeItem + 5, functions[activeItem].text, handle);
		selectItem(&activeItem, functions, MENU_FUNCTIONS_COUNT, handle);
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");
		showCursor(true, handle);
		switch (activeItem)
		{
		case 0:
		{
			f = f1;
			run = false;
			break;
		}
		case 1:
		{
			f = f2;
			run = false;
			break;
		}
		case 2:
		{
			f = f3;
			run = false;
			break;
		}
		case 3:
		{
			f = f4;
			run = false;
			break;
		}
		case 4:
		{
			f = f5;
			run = false;
			break;
		}
		case 5:
		{
			run = false;
			break;
		}
		}
	}
}
void dataSaves(double* s)
{
	int activeItem = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, NULL);
	bool run = true;
	struct MenuItem input[2] =
	{
		"Сохранить данные", NULL,
		"Выход", NULL
	};
	while (run)
	{
		system("cls");
		showCursor(false, handle);
		itemOutput(2, "ЧТО ДАЛЬШЕ?", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < 2; i++)
		{
			itemHide(i + 5, input[i].text, handle);
		}
		itemActivate(activeItem + 5, input[activeItem].text, handle);
		selectItem(&activeItem, input, 2, handle);
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");
		showCursor(true, handle);
		switch(activeItem)
		{
		case 0:
		{
			WriteToFile(s);
			system("pause");
			run = false;
		}
		case 1:
		{
			run = false;
		}
		}
	}
}
void MenuInput()
{
	if (f == NULL)
	{
		puts("Вы ещё не выбрали фукнцию!");
		system("pause");
		return;
	}
	int activeItem = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, NULL);
	bool run = true;
	struct MenuItem input[MENU_INPUT_COUNT] =
	{
		"Ввод из файла", NULL,
		"Ввод с клавиатуры", NULL,
		"Выход", NULL
	};
	while (run)
	{
		system("cls");
		showCursor(false, handle);
		itemOutput(2, "СПОСОБ СЧИТЫВАНИЯ ДАННЫХ", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < MENU_INPUT_COUNT; i++)
		{
			itemHide(i + 5, input[i].text, handle);
		}
		itemActivate(activeItem + 5, input[activeItem].text, handle);
		selectItem(&activeItem, input, MENU_INPUT_COUNT, handle);
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");
		showCursor(true, handle);

		double a, b, n;

		switch (activeItem)
		{
		case 0:
		{
			ReadFromFile(&a, &b, &n);
			itemOutput(2, "ВЫВОД ДАННЫХ", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			double s = 0;
			s = InputOutput(&a, &b, &n);  
			system("pause");
			dataSaves(&s);
			run = false;
			break;
		}
		case 1:
		{
			itemOutput(2, "ВВОД ДАННЫХ", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			InputSolution(&a,&b,&n);
			itemOutput(8, "ВЫВОД ДАННЫХ", handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			double s = 0;
			s = InputOutput(&a,&b,&n);
			system("pause");
			dataSaves(&s);
			run = false;
			break;
		}
		case 2:
		{
			run = false;
			break;
		}
		}
	}
}