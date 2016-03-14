#ifndef MB_WINDOW_ORGANIZATION_MODE_GUI_H
#define MB_WINDOW_ORGANIZATION_MODE_GUI_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "mb_window_organization_mode.h"

#define MB_CONTROL_WINDOW_ORGANIZATION_MODE_WINDOW_LABEL 1

struct mb_WindowOrganizationModeWindow_t{
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
}typedef mb_WindowOrganizationModeWindow;

void mb_WindowOrganizationModeWindow_RegisterClass(HINSTANCE hInstance);

void mb_WindowOrganizationModeWindow_Init();

void mb_WindowOrganizationModeWindow_Render(HDC *hdc);

void mb_WindowOrganizationModeWindow_Show();
void mb_WindowOrganizationModeWindow_Hide();

void mb_WindowOrganizationModeWindowRepaint();

HWND mb_WindowOrganizationModeWindow_HWND();


#endif // MB_WINDOW_ORGANIZATION_MODE_GUI_H
