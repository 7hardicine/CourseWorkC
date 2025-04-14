#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#include "Menu.h"

void itemOutput(int row_number, char* text, HANDLE handle, WORD color)
{
	COORD cursorPosition = { 10,row_number };
	SetConsoleTextAttribute(handle, color);
	SetConsoleCursorPosition(handle, cursorPosition);
	printf_s("%s", text);
}
void itemActivate(int row_number, char* text, HANDLE handle)
{
	itemOutput(row_number, text, handle, BACKGROUND_BLUE | FOREGROUND_RED);
}
void itemHide(int row_number, char* text, HANDLE handle)
{
	itemOutput(row_number, text, handle, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
	SetConsoleTextAttribute(handle, BACKGROUND_BLUE);
	bool run = true;
	while (run)
	{
		system("cls");
		showCursor(false, handle);
		for (int i = 0; i < itemCount; i++)
		{
			itemHide(i + 5, items[i].text, handle);
		}
		itemActivate(activeItem + 5, items[activeItem].text, handle);
		selectItem(&activeItem, items, itemCount, handle);
		SetConsoleTextAttribute(handle, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");
		showCursor(true, handle);
		items[activeItem].handler();
		system("pause");
		if (strcmp(items[activeItem].text, "Выход") == 0)
		{
			run = false;
		}
	}
}