#include "mb_processes_list_gui.h"

mb_ProcessesListWindow processesListWin;


LRESULT CALLBACK mb_ProcessesListWindow_WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
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

    mb_ProcessesListWindow_Render(&hdc);

    EndPaint(hWnd, &ps);
		break;

	case WM_CREATE:
    CreateWindow(TEXT("button"), TEXT(""),
      WS_VISIBLE | WS_CHILD | BS_FLAT | BS_OWNERDRAW,
      processesListWin.borderSize,
      processesListWin.borderSize,
      processesListWin.width-(processesListWin.borderSize*2),
      processesListWin.height-(processesListWin.borderSize*2),
      hWnd,
      (HMENU)1,
      NULL, NULL);
    break;

  case WM_DRAWITEM:
  {
    LPDRAWITEMSTRUCT item = (LPDRAWITEMSTRUCT)lParam;
    if(item->CtlID == 1){
      SetBkColor(item->hDC, processesListWin.bgColor);
      SetDCBrushColor(item->hDC, processesListWin.bgColor);
      SetTextColor(item->hDC, RGB(80,0,100));
      bgRgn = CreateRectRgnIndirect(&item->rcItem);
      hBrush = CreateSolidBrush(processesListWin.bgColor);
      FillRgn(item->hDC, bgRgn, hBrush);

      // mb_Mode *mode;
      // mode = mb_GetCurrentMode();
      // DrawText(item->hDC, mode->name, strlen(mode->name), &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
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

void mb_ProcessesListWindow_RegisterClass(HINSTANCE hInstance){
  WNDCLASSEX wClass;
	wClass.cbClsExtra = 0;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = 0;
  wClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	wClass.hCursor = LoadCursor(0, IDC_ARROW);
	wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = mb_ProcessesListWindow_WinProc;
	wClass.lpszClassName = "MbProcessesListWindow";
	wClass.lpszMenuName = "MbProcessesListWindow";
	wClass.style = CS_VREDRAW | CS_HREDRAW;

	if(!RegisterClassEx(&wClass))
		exit(1);
}

void mb_ProcessesListWindow_Init(){
  processesListWin.windowName = "Processes List";
  processesListWin.x = 400;
  processesListWin.y = 10;
  processesListWin.width = 200;
  processesListWin.height = 50;
  processesListWin.borderSize = 5;
  processesListWin.bgColor = RGB(0,0,0);
  processesListWin.borderColor = RGB(60,0,80);
  processesListWin.hWnd = CreateWindowEx(
    WS_EX_TOPMOST,
    "MbProcessesListWindow",
    processesListWin.windowName,
    WS_POPUP,
    processesListWin.x,
    processesListWin.y,
    processesListWin.width,
    processesListWin.height,
    0,
    0,
    0,
    0);
}

void mb_ProcessesListWindow_Render(HDC *hdc){
  // Draw the border
  GetClientRect(processesListWin.hWnd, &processesListWin.clientRect);
  processesListWin.bgRgn = CreateRectRgnIndirect(&processesListWin.clientRect);
  processesListWin.hBrush = CreateSolidBrush(processesListWin.borderColor);
  FillRgn(*hdc, processesListWin.bgRgn, processesListWin.hBrush);

  // Draw the background
  processesListWin.clientRect.left = processesListWin.clientRect.left + processesListWin.borderSize;
  processesListWin.clientRect.top = processesListWin.clientRect.top + processesListWin.borderSize;
  processesListWin.clientRect.right = processesListWin.clientRect.right - processesListWin.borderSize;
  processesListWin.clientRect.bottom = processesListWin.clientRect.bottom - processesListWin.borderSize;
  processesListWin.bgRgn = CreateRectRgnIndirect(&processesListWin.clientRect);
  processesListWin.hBrush = CreateSolidBrush(processesListWin.bgColor);
  FillRgn(*hdc, processesListWin.bgRgn, processesListWin.hBrush);
}

void mb_ProcessesListWindow_Show(){
  ShowWindow(processesListWin.hWnd, SW_SHOW);
}

void mb_ProcessesListWindow_Hide(){
  ShowWindow(processesListWin.hWnd, SW_HIDE);
}

void mb_ProcessesListWindowRepaint(){
  InvalidateRect(processesListWin.hWnd, NULL, true);
}

HWND mb_ProcessesListWindow_HWND(){
  return processesListWin.hWnd;
}

void mb_ProcessesListWindow_InitProcessesList(){
  // printf("Initializing Processes\n");
  // mb_linkedlist *processesList = malloc(sizeof(mb_linkedlist));
  // printf("Initializing Processes 1\n");
  // mb_linkedlist_Node *first_node = malloc(sizeof(mb_linkedlist_Node));
  // printf("Initializing Processes 1.1\n");
  // first_node->val = 98.0;
  // printf("Initializing Processes 1.2\n");
  // mb_linkedlist_append_node(processesList, first_node);
  // printf("Initializing Processes 2\n");
  // mb_linkedlist_Node *second_node = malloc(sizeof(mb_linkedlist_Node));
  // second_node->val = 56.0;
  // mb_linkedlist_append_node(processesList, second_node);
  // printf("Initializing Processes 3\n");
  // mb_linkedlist_Node *third_node = malloc(sizeof(mb_linkedlist_Node));
  // third_node->val = 367.0;
  // mb_linkedlist_append_node(processesList, third_node);
  // printf("Initializing Processes 4\n");
  // mb_linkedlist_Node *fourth_node = malloc(sizeof(mb_linkedlist_Node));
  // fourth_node->val = 726.0;
  // mb_linkedlist_append_node(processesList, fourth_node);
  // printf("Initializing Processes 5\n");
  // mb_linkedlist_print(processesList);


}
