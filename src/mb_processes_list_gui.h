#ifndef MB_PROCESSES_LIST_GUI_H
#define MB_PROCESSES_LIST_GUI_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "MB_LinkedList.h"

struct mb_ProcessesListItem_t{
  char processName[256];
  HWND hWnd;
}typedef mb_ProcessesListItem;



struct mb_ProcessesListWindow_t{
  HWND hWnd;
  char *windowName;
  int x;
  int y;
  int width;
  int height;
  int borderSize;
  COLORREF bgColor;
  COLORREF borderColor;
  HRGN bgRgn;
  HBRUSH hBrush;
  RECT clientRect;

}typedef mb_ProcessesListWindow;

void mb_ProcessesListWindow_RegisterClass(HINSTANCE hInstance);

void mb_ProcessesListWindow_Init();

void mb_ProcessesListWindow_Render(HDC *hdc);

void mb_ProcessesListWindow_Show();
void mb_ProcessesListWindow_Hide();

void mb_ProcessesListWindowRepaint();

HWND mb_ProcessesListWindow_HWND();

void mb_ProcessesListWindow_InitProcessesList();


#endif // MB_PROCESSES_LIST_GUI_H
