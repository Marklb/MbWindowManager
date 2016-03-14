#include "mb_mode_gui.h"

mb_CurrentModeWindow currModeWin;



LRESULT CALLBACK mb_CurrentModeWindow_WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hdc;
  RECT clientRect;
  RECT rectInner;
  HRGN bgRgn;
  HBRUSH hBrush;

	switch (Message)
	{
	case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);

    mb_CurrentModeWindow_Render(&hdc);

    EndPaint(hWnd, &ps);
		break;

	case WM_CREATE:
    CreateWindow(TEXT("button"), TEXT(""),
      WS_VISIBLE | WS_CHILD | BS_FLAT | BS_OWNERDRAW,
      currModeWin.borderSize,
      currModeWin.borderSize,
      currModeWin.width-(currModeWin.borderSize*2),
      currModeWin.height-(currModeWin.borderSize*2),
      hWnd,
      (HMENU)MB_CONTROL_CURRENT_MODE_WINDOW_LABEL,
      NULL, NULL);
    break;

  case WM_DRAWITEM:
  {
    LPDRAWITEMSTRUCT item = (LPDRAWITEMSTRUCT)lParam;
    if(item->CtlID == 1){
      SetBkColor(item->hDC, currModeWin.bgColor);
      SetDCBrushColor(item->hDC, currModeWin.bgColor);
      SetTextColor(item->hDC, RGB(80,0,100));
      bgRgn = CreateRectRgnIndirect(&item->rcItem);
      hBrush = CreateSolidBrush(currModeWin.bgColor);
      FillRgn(item->hDC, bgRgn, hBrush);

      mb_Mode *mode;
      mode = mb_GetCurrentMode();
      DrawText(item->hDC, mode->name, strlen(mode->name), &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
    }
  }
  break;

  case WM_COMMAND:
  {
    switch (wParam)
    {
          case 1:
          {
            // MoveWindow(hWnd, 100, 100, 500, 800, TRUE);
            break;
          }
    }
    break;
  }

	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void mb_CurrentModeWindow_RegisterClass(HINSTANCE hInstance){
  WNDCLASSEX wClass;
	wClass.cbClsExtra = 0;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = 0;
  wClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	wClass.hCursor = LoadCursor(0, IDC_ARROW);
	wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = mb_CurrentModeWindow_WinProc;
	wClass.lpszClassName = "MbCurentModeWindow";
	wClass.lpszMenuName = "MbCurentModeWindow";
	wClass.style = CS_VREDRAW | CS_HREDRAW;

	if(!RegisterClassEx(&wClass))
		exit(1);
}

void mb_CurrentModeWindow_Init(){
  currModeWin.windowName = "Current Mode";
  currModeWin.x = 10;
  currModeWin.y = 10;
  currModeWin.width = 200;
  currModeWin.height = 50;
  currModeWin.borderSize = 5;
  currModeWin.bgColor = RGB(0,0,0);
  currModeWin.borderColor = RGB(60,0,80);
  currModeWin.hWnd = CreateWindowEx(
    WS_EX_TOPMOST,
    "MbCurentModeWindow",
    currModeWin.windowName,
    WS_POPUP,
    currModeWin.x,
    currModeWin.y,
    currModeWin.width,
    currModeWin.height,
    0,
    0,
    0,
    0);
}

void mb_CurrentModeWindow_Render(HDC *hdc){
  // Draw the border
  GetClientRect(currModeWin.hWnd, &currModeWin.clientRect);
  currModeWin.bgRgn = CreateRectRgnIndirect(&currModeWin.clientRect);
  currModeWin.hBrush = CreateSolidBrush(currModeWin.borderColor);
  FillRgn(*hdc, currModeWin.bgRgn, currModeWin.hBrush);

  // Draw the background
  currModeWin.clientRect.left = currModeWin.clientRect.left + currModeWin.borderSize;
  currModeWin.clientRect.top = currModeWin.clientRect.top + currModeWin.borderSize;
  currModeWin.clientRect.right = currModeWin.clientRect.right - currModeWin.borderSize;
  currModeWin.clientRect.bottom = currModeWin.clientRect.bottom - currModeWin.borderSize;
  currModeWin.bgRgn = CreateRectRgnIndirect(&currModeWin.clientRect);
  currModeWin.hBrush = CreateSolidBrush(currModeWin.bgColor);
  FillRgn(*hdc, currModeWin.bgRgn, currModeWin.hBrush);
}

void mb_CurrentModeWindow_Show(){
  ShowWindow(currModeWin.hWnd, SW_SHOW);
}

void mb_CurrentModeWindow_Hide(){
  ShowWindow(currModeWin.hWnd, SW_HIDE);
}

void mb_CurrentModeWindowRepaint(){
  InvalidateRect(currModeWin.hWnd, NULL, true);
}

HWND mb_CurrentModeWindow_HWND(){
  return currModeWin.hWnd;
}

///////////////////////////////////////////////////////////////////////////////
mb_CurrentModeWindow currModeSelectionWin;

LRESULT CALLBACK mb_CurrentModeSelectionWindow_WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hdc;
  RECT clientRect;
  RECT rectInner;
  HRGN bgRgn;
  HBRUSH hBrush;

	switch (Message)
	{
	case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);

    mb_CurrentModeSelectionWindow_Render(&hdc);

    EndPaint(hWnd, &ps);
		break;

	case WM_CREATE:
    CreateWindow(TEXT("button"), TEXT(""),
      WS_VISIBLE | WS_CHILD | BS_FLAT | BS_OWNERDRAW,
      currModeSelectionWin.borderSize,
      currModeSelectionWin.borderSize,
      currModeSelectionWin.width-(currModeSelectionWin.borderSize*2),
      currModeSelectionWin.height-(currModeSelectionWin.borderSize*2),
      hWnd,
      (HMENU)MB_CONTROL_CURRENT_MODE_WINDOW_LABEL,
      NULL, NULL);
    break;

  case WM_DRAWITEM:
  {
    LPDRAWITEMSTRUCT item = (LPDRAWITEMSTRUCT)lParam;
    if(item->CtlID == MB_CONTROL_CURRENT_MODE_WINDOW_LABEL){
      SetBkColor(item->hDC, currModeSelectionWin.bgColor);
      SetDCBrushColor(item->hDC, currModeSelectionWin.bgColor);
      SetTextColor(item->hDC, RGB(80,0,100));
      bgRgn = CreateRectRgnIndirect(&item->rcItem);
      hBrush = CreateSolidBrush(currModeSelectionWin.bgColor);
      FillRgn(item->hDC, bgRgn, hBrush);

      mb_Mode *mode;
      mode = mb_GetCurrentMode();
      DrawText(item->hDC, mode->name, strlen(mode->name), &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
    }
  }
  break;

  case WM_COMMAND:
  {
    switch (wParam)
    {
          case MB_CONTROL_CURRENT_MODE_WINDOW_LABEL:
          {
            // MoveWindow(hWnd, 100, 100, 500, 800, TRUE);
            break;
          }
    }
    break;
  }

	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void mb_CurrentModeSelectionWindow_RegisterClass(HINSTANCE hInstance){
  WNDCLASSEX wClass;
	wClass.cbClsExtra = 0;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = 0;
  wClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	wClass.hCursor = LoadCursor(0, IDC_ARROW);
	wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = mb_CurrentModeSelectionWindow_WinProc;
	wClass.lpszClassName = "MbCurentModeSelectionWindow";
	wClass.lpszMenuName = "MbCurentModeSelectionWindow";
	wClass.style = CS_VREDRAW | CS_HREDRAW;

	if(!RegisterClassEx(&wClass))
		exit(1);
}

void mb_CurrentModeSelectionWindow_Init(){
  currModeSelectionWin.windowName = "Current Mode";
  currModeSelectionWin.x = 220;
  currModeSelectionWin.y = 10;
  currModeSelectionWin.width = 200;
  currModeSelectionWin.height = 50;
  currModeSelectionWin.borderSize = 5;
  currModeSelectionWin.bgColor = RGB(0,0,0);
  currModeSelectionWin.borderColor = RGB(60,0,80);
  currModeSelectionWin.hWnd = CreateWindowEx(
    WS_EX_TOPMOST,
    "MbCurentModeWindow",
    currModeSelectionWin.windowName,
    WS_POPUP,
    currModeSelectionWin.x,
    currModeSelectionWin.y,
    currModeSelectionWin.width,
    currModeSelectionWin.height,
    0,
    0,
    0,
    0);
}

void mb_CurrentModeSelectionWindow_Render(HDC *hdc){
  // Draw the border
  GetClientRect(currModeSelectionWin.hWnd, &currModeSelectionWin.clientRect);
  currModeSelectionWin.bgRgn = CreateRectRgnIndirect(&currModeSelectionWin.clientRect);
  currModeSelectionWin.hBrush = CreateSolidBrush(currModeSelectionWin.borderColor);
  FillRgn(*hdc, currModeSelectionWin.bgRgn, currModeSelectionWin.hBrush);

  // Draw the background
  currModeSelectionWin.clientRect.left = currModeSelectionWin.clientRect.left + currModeSelectionWin.borderSize;
  currModeSelectionWin.clientRect.top = currModeSelectionWin.clientRect.top + currModeSelectionWin.borderSize;
  currModeSelectionWin.clientRect.right = currModeSelectionWin.clientRect.right - currModeSelectionWin.borderSize;
  currModeSelectionWin.clientRect.bottom = currModeSelectionWin.clientRect.bottom - currModeSelectionWin.borderSize;
  currModeSelectionWin.bgRgn = CreateRectRgnIndirect(&currModeSelectionWin.clientRect);
  currModeSelectionWin.hBrush = CreateSolidBrush(currModeSelectionWin.bgColor);
  FillRgn(*hdc, currModeSelectionWin.bgRgn, currModeSelectionWin.hBrush);
}

void mb_CurrentModeSelectionWindow_Show(){
  ShowWindow(currModeSelectionWin.hWnd, SW_SHOW);
}

void mb_CurrentModeSelectionWindow_Hide(){
  ShowWindow(currModeSelectionWin.hWnd, SW_HIDE);
}

void mb_CurrentModeSelectionWindowRepaint(){
  InvalidateRect(currModeSelectionWin.hWnd, NULL, true);
}
