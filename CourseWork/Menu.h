#pragma once
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define KEY_ARROW_UP 72
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75
#define ENTER 13
#define ESC 27

typedef void (*Handler)();
struct MenuItem
{
	char* text;
	Handler handler;
};
void itemOutput(int row_number, char* text, HANDLE handle, WORD color);
void itemActivate(int row_number, char* text, HANDLE handle);
void itemHide(int row_number, char* text, HANDLE handle);
void showCursor(bool visible, HANDLE handle);
void selectItem(int* activeItem, struct MenuItem* items, int itemCount, HANDLE handle);
void mainMenu(struct MenuItem* items, int itemCount);
double InputOutput(double* a, double* b, double* n);
void MenuFuntionChoice();
void dataSaves(double* s);
void MenuInput();