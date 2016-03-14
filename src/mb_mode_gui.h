#ifndef MB_MODE_GUI_H
#define MB_MODE_GUI_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "mb_mode.h"

#define MB_CONTROL_CURRENT_MODE_WINDOW_LABEL 1

struct mb_CurrentModeWindow_t{
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
}typedef mb_CurrentModeWindow;

void mb_CurrentModeWindow_RegisterClass(HINSTANCE hInstance);

void mb_CurrentModeWindow_Init();

void mb_CurrentModeWindow_Render(HDC *hdc);

void mb_CurrentModeWindow_Show();
void mb_CurrentModeWindow_Hide();

void mb_CurrentModeWindowRepaint();

HWND mb_CurrentModeWindow_HWND();

///////////////////////////////////////////////////////////////////////////////

struct mb_CurrentModeSelectionWindow_t{
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
}typedef mb_CurrentModeSelectionWindow;

void mb_CurrentModeSelectionWindow_RegisterClass(HINSTANCE hInstance);

void mb_CurrentModeSelectionWindow_Init();

void mb_CurrentModeSelectionWindow_Render(HDC *hdc);

void mb_CurrentModeSelectionWindow_Show();
void mb_CurrentModeSelectionWindow_Hide();


#endif // MB_MODE_GUI_H
