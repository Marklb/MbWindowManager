#include "WorkspaceList.h"

void WorkspaceListWindow_Init(WorkspaceListWindow *wrkspListWin){
  wrkspListWin->windowName = "Workspace List";
  wrkspListWin->x = 600;
  wrkspListWin->y = 10;
  wrkspListWin->width = 300;
  wrkspListWin->height = 500;
  wrkspListWin->borderSize = 5;
  wrkspListWin->bgColor = RGB(0,0,0);
  wrkspListWin->borderColor = RGB(60,0,80);
  wrkspListWin->hWnd = CreateWindowEx(
    WS_EX_TOPMOST,
    "MbWmWindow",
    wrkspListWin->windowName,
    WS_POPUP,
    wrkspListWin->x,
    wrkspListWin->y,
    wrkspListWin->width,
    wrkspListWin->height,
    0,
    0,
    0,
    0);
}

void WorkspaceListWindow_Render(WorkspaceListWindow *wrkspListWin, HDC *hdc){
  // Draw the border
  GetClientRect(wrkspListWin->hWnd, &wrkspListWin->clientRect);
  wrkspListWin->bgRgn = CreateRectRgnIndirect(&wrkspListWin->clientRect);
  wrkspListWin->hBrush = CreateSolidBrush(wrkspListWin->borderColor);
  FillRgn(*hdc, wrkspListWin->bgRgn, wrkspListWin->hBrush);

  // Draw the background
  wrkspListWin->clientRect.left = wrkspListWin->clientRect.left + wrkspListWin->borderSize;
  wrkspListWin->clientRect.top = wrkspListWin->clientRect.top + wrkspListWin->borderSize;
  wrkspListWin->clientRect.right = wrkspListWin->clientRect.right - wrkspListWin->borderSize;
  wrkspListWin->clientRect.bottom = wrkspListWin->clientRect.bottom - wrkspListWin->borderSize;
  wrkspListWin->bgRgn = CreateRectRgnIndirect(&wrkspListWin->clientRect);
  wrkspListWin->hBrush = CreateSolidBrush(wrkspListWin->bgColor);
  FillRgn(*hdc, wrkspListWin->bgRgn, wrkspListWin->hBrush);

  // Draw the list items

}
