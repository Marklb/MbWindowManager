#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#include "mb_keyboard.h"
#include "MB_LinkedList.h"
#include "WorkspaceList.h"
#include "mb_mode.h"
#include "mb_mode_gui.h"
#include "mb_window_organization_mode.h"
#include "mb_window_organization_mode_gui.h"
#include "mb_processes_list_gui.h"


// Move a window smoothly
// http://stackoverflow.com/questions/932706/how-to-programmatically-move-a-window-slowly-as-if-the-user-were-doing-it





// char lWindowName[256] = "MB Window Manager";

MSG Message;


char MbDesktopName1[256] = "MB Desktop 1";
int MbDesktopName1Len = 12;

HWND IDC_EDIT_RECOLOR;

RECT tClientRect;
HRGN tBgRgn;
HBRUSH tHBrush;


// MB_LinkedList list;






WorkspaceListWindow wrkspListWin;











LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hdc;
  RECT clientRect;
  RECT rectInner;
  HRGN bgRgn;
  HBRUSH hBrush;
  // HPEN hPen;


	switch (Message)
	{
	case WM_PAINT:
		// Render();
    hdc = BeginPaint(hWnd, &ps);
    if(hWnd == wrkspListWin.hWnd){
      WorkspaceListWindow_Render(&wrkspListWin, &hdc);
    }

        // GetClientRect(hWnd, &clientRect);
        // bgRgn = CreateRectRgnIndirect(&clientRect);
        // hBrush = CreateSolidBrush(RGB(60,0,80));
        // FillRgn(hdc, bgRgn, hBrush);
        //
        // rectInner.left = clientRect.left + borderSize;
        // rectInner.top = clientRect.top + borderSize;
        // rectInner.right = clientRect.right - borderSize;
        // rectInner.bottom = clientRect.bottom - borderSize;
        // bgRgn = CreateRectRgnIndirect(&rectInner);
        // hBrush = CreateSolidBrush(RGB(0,0,0));
        // FillRgn(hdc, bgRgn, hBrush);
        //
        //
        // rectInner.left = clientRect.left + borderSize;
        // rectInner.top = clientRect.top + borderSize + 0;
        // rectInner.right = clientRect.right - borderSize;
        // rectInner.bottom = clientRect.top + 30;
        // bgRgn = CreateRectRgnIndirect(&rectInner);
        // hBrush = CreateSolidBrush(RGB(0,0,100));
        // FillRgn(hdc, bgRgn, hBrush);
        // SetBkColor(hdc, RGB(0,0,100));
        // SetTextColor(hdc, RGB(255,255,255));
        // DrawText(hdc, MbDesktopName1, MbDesktopName1Len, &rectInner, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
        //
        // rectInner.left = clientRect.left + borderSize;
        // rectInner.top = clientRect.top + borderSize + 30;
        // rectInner.right = clientRect.right - borderSize;
        // rectInner.bottom = clientRect.top + 60;
        // bgRgn = CreateRectRgnIndirect(&rectInner);
        // hBrush = CreateSolidBrush(RGB(0,0,100));
        // FillRgn(hdc, bgRgn, hBrush);
        // SetBkColor(hdc, RGB(0,0,100));
        // SetTextColor(hdc, RGB(255,255,255));
        // DrawText(hdc, MbDesktopName1, MbDesktopName1Len, &rectInner, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

        EndPaint(hWnd, &ps);
		break;

	case WM_CREATE:
        printf("WM_CREATE\n");
        CreateWindow(TEXT("button"), TEXT(""),
		             WS_VISIBLE | WS_CHILD | BS_FLAT | BS_OWNERDRAW,
		             10, 100, 200, 50,
		             hWnd, (HMENU) 1, NULL, NULL);
        // IDC_EDIT_RECOLOR = CreateWindow(TEXT("edit"), TEXT("Beep"),
		    //          WS_VISIBLE | WS_CHILD | ES_LEFT | ES_CENTER,
		    //          20, 50, 80, 25,
		    //          hWnd, (HMENU) 1, NULL, NULL);
        break;

  case WM_CTLCOLOREDIT:
  {
    // MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
    hdc = (HDC)wParam;
    HWND hwndEdit = (HWND)lParam;

    // MessageBox(NULL, tmp, "Error", MB_ICONERROR);
    if(hwndEdit == IDC_EDIT_RECOLOR){
      SetBkColor(hdc, RGB(0,0,100));
      SetDCBrushColor(hdc, RGB(0,0,100));
      SetTextColor(hdc, RGB(255,255,255));
      return (LRESULT) GetStockObject(DC_BRUSH);
    }
  }
  break;

  case WM_DRAWITEM:
  {
    LPDRAWITEMSTRUCT item = (LPDRAWITEMSTRUCT)lParam;
    if(item->CtlID == 1){
      // MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
      SetBkColor(item->hDC, RGB(0,0,100));
      SetDCBrushColor(item->hDC, RGB(0,0,100));
      SetTextColor(item->hDC, RGB(255,255,255));
      bgRgn = CreateRectRgnIndirect(&item->rcItem);
      hBrush = CreateSolidBrush(RGB(0,0,100));
      FillRgn(item->hDC, bgRgn, hBrush);
      // DrawText(item->hDC, MbDesktopName1, MbDesktopName1Len, &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
      char tmp[256];
      // sprintf(tmp, "Mode: %s", (char *)list.head->data);
      // DrawText(item->hDC, tmp, strlen(tmp), &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
      // DrawText(item->hDC, MbDesktopName1, strlen(MbDesktopName1), &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
      mb_Mode *mode;
      mode = mb_GetMode(MB_MODE_BASIC);
      mode = mb_GetCurrentMode();
      sprintf(tmp, "Mode: %s", mode->name);
      DrawText(item->hDC, tmp, strlen(tmp), &item->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
    }
  }
  break;

  case WM_COMMAND:
  {
       switch (wParam)
       {
              case 1:
              {
                //  SendMessage(lbLogs, LB_ADDSTRING, 0, (LPARAM)TEXT("TEST"));-
                MoveWindow(hWnd, 100, 100, 500, 800, TRUE);
                break;
              }
       }
       break;
  }

    // case WM_KEYDOWN:
    //     printf("KeyDown: %d\n", counter);
    //     break;

    // case WM_KEYUP:
    //     printf("KeyUp\n");
    //     break;

    case WM_CLOSE:
        printf("WM_CLOSE\n");
        mb_WindowOrganizationModeShowAllProcesses();
        DestroyWindow(hWnd);
        break;

	case WM_DESTROY:
        printf("WM_DESTROY\n");
        mb_WindowOrganizationModeShowAllProcesses();
	      PostQuitMessage(0);
        break;

	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}






HHOOK _hookMouse;
LRESULT __stdcall HookMouseCallback(int nCode, WPARAM wParam, LPARAM lParam){
    if (nCode >= 0)
    {
        //MessageBox(NULL, "Mouse", "Mouse Info", MB_ICONINFORMATION);
        // return 1;
        printf("MouseMessage\n");
    }

    // call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
    return CallNextHookEx(_hookMouse, nCode, wParam, lParam);
}
void SetMouseHook(){
    if (!(_hookMouse = SetWindowsHookEx(WH_MOUSE_LL, HookMouseCallback, NULL, 0)))  // TODO: HOOK WndProc and look at sending WM_COPYDATA message
    {
        MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
    }

}
void ReleaseMouseHook(){
    UnhookWindowsHookEx(_hookMouse);
}













// HINSTANCE dllHandle;
// HOOKPROC address;
// HHOOK keyboard_hook;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow)
{
  printf("Starting MB Window Manager\n");
  mb_InitializeModes();
  mb_InitializeWindowOrganizationModes();


  // MB_LinkedList_Init(&list);
  // char tmp[256];
  // sprintf(tmp, "Basic");
  // MB_LinkedList_Push(&list, tmp, sizeof(tmp));

  mb_SetKeyboardHook();




	WNDCLASSEX wClass;
	wClass.cbClsExtra = 0;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = 0;
  wClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	wClass.hCursor = LoadCursor(0, IDC_ARROW);
	wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = WinProc;
	wClass.lpszClassName = "MbWmWindow";
	wClass.lpszMenuName = "MbWMWindow";
	wClass.style = CS_VREDRAW | CS_HREDRAW;
    // wClass.style = 0;

	if(!RegisterClassEx(&wClass))
		exit(1);


  WorkspaceListWindow_Init(&wrkspListWin);
  // ShowWindow(wrkspListWin.hWnd, SW_SHOW);

  mb_CurrentModeWindow_RegisterClass(hInstance);
  mb_CurrentModeWindow_Init();
  mb_CurrentModeWindow_Show();

  // mb_CurrentModeSelectionWindow_RegisterClass(hInstance);
  // mb_CurrentModeSelectionWindow_Init();
  // mb_CurrentModeSelectionWindow_Show();

  mb_WindowOrganizationModeWindow_RegisterClass(hInstance);
  mb_WindowOrganizationModeWindow_Init();
  mb_WindowOrganizationModeWindow_Show();

  // mb_ProcessesListWindow_RegisterClass(hInstance);
  // mb_ProcessesListWindow_Init();
  // mb_ProcessesListWindow_Show();

  // mb_ProcessesListWindow_InitProcessesList();





  // SetMouseHook();

  while(GetMessage(&Message, NULL, 0, 0))
  {
      TranslateMessage(&Message);
      DispatchMessage(&Message);
  }

  // ReleaseMouseHook();
  mb_ReleaseKeyboardHook();

	return 0;
}
