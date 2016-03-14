#include "mb_window_organization_mode_gui.h"

mb_WindowOrganizationModeWindow win;



LRESULT CALLBACK mb_WindowOrganizationModeWindow_WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
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

    mb_WindowOrganizationModeWindow_Render(&hdc);

    EndPaint(hWnd, &ps);
		break;

	case WM_CREATE:
    CreateWindow(TEXT("button"), TEXT(""),
      WS_VISIBLE | WS_CHILD | BS_FLAT | BS_OWNERDRAW,
      win.borderSize,
      win.borderSize,
      win.width-(win.borderSize*2),
      win.height-(win.borderSize*2),
      hWnd,
      (HMENU)MB_CONTROL_WINDOW_ORGANIZATION_MODE_WINDOW_LABEL,
      NULL, NULL);
    break;

  case WM_DRAWITEM:
  {
    LPDRAWITEMSTRUCT item = (LPDRAWITEMSTRUCT)lParam;
    if(item->CtlID == MB_CONTROL_WINDOW_ORGANIZATION_MODE_WINDOW_LABEL){
      SetBkColor(item->hDC, win.bgColor);
      SetDCBrushColor(item->hDC, win.bgColor);
      SetTextColor(item->hDC, RGB(80,0,100));
      bgRgn = CreateRectRgnIndirect(&item->rcItem);
      hBrush = CreateSolidBrush(win.bgColor);
      FillRgn(item->hDC, bgRgn, hBrush);

      mb_WindowOrganizationMode *mode;
      mode = mb_GetCurrentWindowOrganizationMode();
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

void mb_WindowOrganizationModeWindow_RegisterClass(HINSTANCE hInstance){
  WNDCLASSEX wClass;
	wClass.cbClsExtra = 0;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = 0;
  wClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	wClass.hCursor = LoadCursor(0, IDC_ARROW);
	wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = mb_WindowOrganizationModeWindow_WinProc;
	wClass.lpszClassName = "MbWindowOrganizationModeWindow";
	wClass.lpszMenuName = "MbWindowOrganizationModeWindow";
	wClass.style = CS_VREDRAW | CS_HREDRAW;

	if(!RegisterClassEx(&wClass))
		exit(1);
}

void mb_WindowOrganizationModeWindow_Init(){
  //  GetSystemMetrics SM_CXSCREEN / SM_CYSCREEN
  win.windowName = "Window Organization Mode";
  win.width = 200;
  win.height = 50;
  win.borderSize = 5;
  win.x = GetSystemMetrics(SM_CXSCREEN)-win.width-win.borderSize;
  win.y = 10;
  win.bgColor = RGB(0,0,0);
  win.borderColor = RGB(60,0,80);
  win.hWnd = CreateWindowEx(
    WS_EX_TOPMOST,
    "MbWindowOrganizationModeWindow",
    win.windowName,
    WS_POPUP,
    win.x,
    win.y,
    win.width,
    win.height,
    0,
    0,
    0,
    0);
}

void mb_WindowOrganizationModeWindow_Render(HDC *hdc){
  // Draw the border
  GetClientRect(win.hWnd, &win.clientRect);
  win.bgRgn = CreateRectRgnIndirect(&win.clientRect);
  win.hBrush = CreateSolidBrush(win.borderColor);
  FillRgn(*hdc, win.bgRgn, win.hBrush);

  // Draw the background
  win.clientRect.left = win.clientRect.left + win.borderSize;
  win.clientRect.top = win.clientRect.top + win.borderSize;
  win.clientRect.right = win.clientRect.right - win.borderSize;
  win.clientRect.bottom = win.clientRect.bottom - win.borderSize;
  win.bgRgn = CreateRectRgnIndirect(&win.clientRect);
  win.hBrush = CreateSolidBrush(win.bgColor);
  FillRgn(*hdc, win.bgRgn, win.hBrush);
}

void mb_WindowOrganizationModeWindow_Show(){
  ShowWindow(win.hWnd, SW_SHOW);
}

void mb_WindowOrganizationModeWindow_Hide(){
  ShowWindow(win.hWnd, SW_HIDE);
}

void mb_WindowOrganizationModeWindowRepaint(){
  InvalidateRect(win.hWnd, NULL, true);
}

HWND mb_WindowOrganizationModeWindow_HWND(){
  return win.hWnd;
}
