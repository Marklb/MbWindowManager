#ifndef WORKSPACE_LIST
#define WORKSPACE_LIST

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


struct WorkspaceListItem_t{
  char *name;
}typedef WorkspaceListItem;



struct WorkspaceListWindow_t{
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


}typedef WorkspaceListWindow;

void WorkspaceListWindow_Init(WorkspaceListWindow *wrkspListWin);

void WorkspaceListWindow_Render(WorkspaceListWindow *wrkspListWin, HDC *hdc);

#endif // WORKSPACE_LIST
