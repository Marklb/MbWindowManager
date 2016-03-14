#include "mb_keyboard.h"
#include "mb_mode.h"
#include "mb_mode_gui.h"
#include "mb_window_organization_mode.h"


void mb_HideTaskBar(){
    HWND TaskBar = FindWindow(TEXT("Shell_TrayWnd"), NULL);
    if(TaskBar != NULL){
        ShowWindow(TaskBar, SW_HIDE);
    }
}

void mb_ShowTaskBar(){
    HWND TaskBar = FindWindow(TEXT("Shell_TrayWnd"), NULL);
    if(TaskBar != NULL){
        ShowWindow(TaskBar, SW_SHOW);
    }
}


//
int mb_Keyboard_IsKeyDown__KEYPAD_DIVIDE = false;
int mb_Keyboard_KEYDOWN__KEYPAD_DIVIDE(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type != MB_MODE_WORKING){
    mb_SetCurrentMode(MB_MODE_WORKING);
    mb_CurrentModeWindowRepaint();
    return 1;
  }else{
    return 0;
  }
}
int mb_Keyboard_KEYUP__KEYPAD_DIVIDE(int nCode, WPARAM wParam, LPARAM lParam){}


//
int mb_Keyboard_KEYDOWN__KEYPAD_MINUS(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type != MB_MODE_COMMAND){
    mb_SetCurrentMode(MB_MODE_COMMAND);
    mb_CurrentModeWindowRepaint();
    return 1;
  }else{
    return 0;
  }
}
int mb_Keyboard_KEYUP__KEYPAD_MINUS(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__KEYPAD_MULTIPLY(int nCode, WPARAM wParam, LPARAM lParam){
  mb_SetCurrentMode(MB_MODE_BASIC);
  mb_CurrentModeWindowRepaint();
  return 1;
}
int mb_Keyboard_KEYUP__KEYPAD_MULTIPLY(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_PLUS(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_PLUS);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_PLUS(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_ENTER(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_ENTER);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_ENTER(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_PERIOD(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_PERIOD);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_PERIOD(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__KEYPAD_RIGHT_CONTROL(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    PostQuitMessage(0);
  }
}
int mb_Keyboard_KEYUP__KEYPAD_RIGHT_CONTROL(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__PAUSE_BREAK(int nCode, WPARAM wParam, LPARAM lParam){
  if(IsWindowVisible((HWND)mb_CurrentModeWindow_HWND())){
    mb_CurrentModeWindow_Hide();
    mb_WindowOrganizationModeWindow_Hide();
    return 1;
  }else{
    mb_CurrentModeWindow_Show();
    mb_WindowOrganizationModeWindow_Show();
    return 1;
  }
}
int mb_Keyboard_KEYUP__PAUSE_BREAK(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__HOME(int nCode, WPARAM wParam, LPARAM lParam){}
int mb_Keyboard_KEYUP__HOME(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__PAGE_UP(int nCode, WPARAM wParam, LPARAM lParam){

}
int mb_Keyboard_KEYUP__PAGE_UP(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__PAGE_DOWN(int nCode, WPARAM wParam, LPARAM lParam){

}
int mb_Keyboard_KEYUP__PAGE_DOWN(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_1(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_BASIC);
    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_1(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_2(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING);
    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_2(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_3(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_MATLAB);
    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_3(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_4(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_4(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_5(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_5(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_6(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_6(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_7(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_7(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_8(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_8(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUM_9(int nCode, WPARAM wParam, LPARAM lParam){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

    return 1;
  }
}
int mb_Keyboard_KEYUP__NUM_9(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_1(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_1);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_1(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_2(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_2);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_2(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_3(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_3);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_3(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_4(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_4);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_4(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_5(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_5);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_5(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_6(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_6);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_6(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_7(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_7);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_7(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_8(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_8);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_8(int nCode, WPARAM wParam, LPARAM lParam){}

//
int mb_Keyboard_KEYDOWN__NUMPAD_9(int nCode, WPARAM wParam, LPARAM lParam){
  int ret = mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_9);
  return ret;
}
int mb_Keyboard_KEYUP__NUMPAD_9(int nCode, WPARAM wParam, LPARAM lParam){}



HHOOK _hookKeyboard;
LRESULT __stdcall mb_HookKeyboardCallback(int nCode, WPARAM wParam, LPARAM lParam){
    // typedef struct tagKBDLLHOOKSTRUCT {
    //   DWORD     vkCode;
    //   DWORD     scanCode;
    //   DWORD     flags;
    //   DWORD     time;
    //   ULONG_PTR dwExtraInfo;
    // } KBDLLHOOKSTRUCT, *PKBDLLHOOKSTRUCT, *LPKBDLLHOOKSTRUCT;
    char tmp[256];
    int ret = 0;
    if (nCode >= 0)
    {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
        switch(wParam)
        {
        case WM_KEYDOWN:
            printf("WM_KEYDOWN: vkCode: %d  0x%x  scanCode: %d\n", p->vkCode, p->vkCode, p->scanCode);
            // sprintf(tmp, "WM_KEYDOWN: vkCode: %d  0x%x  scanCode: %d\n", p->vkCode, p->vkCode, p->scanCode);
            // MessageBox(NULL, tmp, "Error", MB_ICONERROR);

            // if(p->vkCode == MB_VKCODE_LEFT_CONTROL)ret=mb_Keyboard_KEYDOWN__KEYPAD_RIGHT_CONTROL(nCode, wParam, lParam);
            // // else if(p->vkCode == (VK_RCONTROL))ret=mb_Keyboard_KEYDOWN__KEYPAD_RIGHT_CONTROL(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_PAUSE_BREAK)ret=mb_Keyboard_KEYDOWN__PAUSE_BREAK(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_PAGE_UP)ret=mb_Keyboard_KEYDOWN__PAGE_UP(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_PAGE_DOWN)ret=mb_Keyboard_KEYDOWN__PAGE_DOWN(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_KEYPAD_DIVIDE)ret=mb_Keyboard_KEYDOWN__KEYPAD_DIVIDE(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_KEYPAD_MINUS)ret=mb_Keyboard_KEYDOWN__KEYPAD_MINUS(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_KEYPAD_MULTIPLY)ret=mb_Keyboard_KEYDOWN__KEYPAD_MULTIPLY(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_PLUS)ret=mb_Keyboard_KEYDOWN__NUMPAD_PLUS(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_ENTER)ret=mb_Keyboard_KEYDOWN__NUMPAD_ENTER(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_PERIOD)ret=mb_Keyboard_KEYDOWN__NUMPAD_PERIOD(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_1)ret=mb_Keyboard_KEYDOWN__NUM_1(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_2)ret=mb_Keyboard_KEYDOWN__NUM_2(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_3)ret=mb_Keyboard_KEYDOWN__NUM_3(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_4)ret=mb_Keyboard_KEYDOWN__NUM_4(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_5)ret=mb_Keyboard_KEYDOWN__NUM_5(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_6)ret=mb_Keyboard_KEYDOWN__NUM_6(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_7)ret=mb_Keyboard_KEYDOWN__NUM_7(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_8)ret=mb_Keyboard_KEYDOWN__NUM_8(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUM_9)ret=mb_Keyboard_KEYDOWN__NUM_9(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_1)ret=mb_Keyboard_KEYDOWN__NUMPAD_1(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_2)ret=mb_Keyboard_KEYDOWN__NUMPAD_2(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_3)ret=mb_Keyboard_KEYDOWN__NUMPAD_3(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_4)ret=mb_Keyboard_KEYDOWN__NUMPAD_4(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_5)ret=mb_Keyboard_KEYDOWN__NUMPAD_5(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_6)ret=mb_Keyboard_KEYDOWN__NUMPAD_6(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_7)ret=mb_Keyboard_KEYDOWN__NUMPAD_7(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_8)ret=mb_Keyboard_KEYDOWN__NUMPAD_8(nCode, wParam, lParam);
            // else if(p->vkCode == MB_VKCODE_NUMPAD_9)ret=mb_Keyboard_KEYDOWN__NUMPAD_9(nCode, wParam, lParam);

            switch(p->vkCode)
            {
              // 0x08: BACKSPACE key
              case VK_BACK:

              break;

              // 0x09: TAB key
              case VK_TAB:

              break;

              // 0x0D: ENTER key
              case VK_RETURN:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_ENTER);
              break;

              // 0x10: SHIFT key
              case VK_SHIFT:

              break;

              // 0x11: CRTL key
              case VK_CONTROL:

              break;

              // 0x12: ALT key
              case VK_MENU:

              break;

              // 0x13: PAUSE key
              case VK_PAUSE:
                if(IsWindowVisible((HWND)mb_CurrentModeWindow_HWND())){
                  mb_CurrentModeWindow_Hide();
                  mb_WindowOrganizationModeWindow_Hide();
                  return 1;
                }else{
                  mb_CurrentModeWindow_Show();
                  mb_WindowOrganizationModeWindow_Show();
                  return 1;
                }
              break;

              // 0x14: CAPS LOCK key
              case VK_CAPITAL:

              break;

              // 0x1B: ESC key
              case VK_ESCAPE:

              break;

              // 0x20: SPACEBAR
              case VK_SPACE:

              break;

              // 0x21: PAGE UP key
              case VK_PRIOR:

              break;

              // 0x22: PAGE DOWN key
              case VK_NEXT:

              break;

              // 0x23: END key
              case VK_END:

              break;

              // 0x24: HOME key
              case VK_HOME:

              break;

              // 0x24: LEFT ARROW key
              case VK_LEFT:

              break;

              // 0x26: UP ARROW key
              case VK_UP:

              break;

              // 0x27: RIGHT ARROW key
              case VK_RIGHT:

              break;

              // 0x28: DOWN ARROW key
              case VK_DOWN:

              break;

              //0x29: SELECT key
              case VK_SELECT:

              break;

              // 0x2A: PRINT key
              case VK_PRINT:

              break;

              // 0x2B: EXECUTE key
              case VK_EXECUTE:

              break;

              // 0x2C: PRINT SCREEN key
              case VK_SNAPSHOT:

              break;

              // 0x2D: INS key
              case VK_INSERT:

              break;

              // 0x2E: DEL key
              case VK_DELETE:

              break;

              // 0x2F: HELP key
              case VK_HELP:

              break;

              // 0x30: 0 key
              case 0x30:

              break;

              // 0x31: 1 key
              case 0x31:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
                  mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_BASIC);
                  return 1;
                }
              break;

              // 0x32: 2 key
              case 0x32:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
                  mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING);
                  return 1;
                }
              break;

              // 0x33: 3 key
              case 0x33:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
                  mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_MATLAB);
                  return 1;
                }
              break;

              // 0x34: 4 key
              case 0x34:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
                  mb_SetCurrentWindowOrganizationMode(MB_WINDOW_ORGANIZATION_MODE_MATLAB2);
                  return 1;
                }
              break;

              // 0x35: 5 key
              case 0x35:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

                  return 1;
                }
              break;

              // 0x36: 6 key
              case 0x36:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

                  return 1;
                }
              break;

              // 0x37: 7 key
              case 0x37:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

                  return 1;
                }
              break;

              // 0x38: 8 key
              case 0x38:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

                  return 1;
                }
              break;

              // 0x39: 9 key
              case 0x39:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){

                  return 1;
                }
              break;

              // 0x41: A key
              case 0x41:

              break;

              // 0x42: B key
              case 0x42:

              break;

              // 0x43: C key
              case 0x43:

              break;

              // 0x44: D key
              case 0x44:

              break;

              // 0x45: E key
              case 0x45:

              break;

              // 0x46: F key
              case 0x46:

              break;

              // 0x47: G key
              case 0x47:

              break;

              // 0x48: H key
              case 0x48:

              break;

              // 0x49: I key
              case 0x49:

              break;

              // 0x4A: J key
              case 0x4A:

              break;

              // 0x4B: K key
              case 0x4B:

              break;

              // 0x4C: L key
              case 0x4C:

              break;

              // 0x4D: M key
              case 0x4D:

              break;

              // 0x4E: N key
              case 0x4E:

              break;

              // 0x4F: O key
              case 0x4F:

              break;

              // 0x50: P key
              case 0x50:

              break;

              // 0x51: Q key
              case 0x51:

              break;

              // 0x52: R key
              case 0x52:

              break;

              // 0x53: S key
              case 0x53:

              break;

              // 0x54: T key
              case 0x54:

              break;

              // 0x55: U key
              case 0x55:

              break;

              // 0x56: V key
              case 0x56:

              break;

              // 0x57: W key
              case 0x57:

              break;

              // 0x58: X key
              case 0x58:

              break;

              // 0x59: Y key
              case 0x59:

              break;

              // 0x5A: Z key
              case 0x5A:

              break;

              // 0x5B: Left Windows key (Natural keyboard)
              case VK_LWIN:

              break;

              // 0x5C Right Windows key (Natural keyboard)
              case VK_RWIN:

              break;

              // 0x60: Numeric keypad 0 key
              case VK_NUMPAD0:
                mb_WindowOrganizationModeShowAllProcesses();
              break;

              // 0x61: Numeric keypad 1 key
              case VK_NUMPAD1:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_1);
              break;

              // 0x62: Numeric keypad 2 key
              case VK_NUMPAD2:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_2);
              break;

              // 0x63: Numeric keypad 3 key
              case VK_NUMPAD3:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_3);
              break;

              // 0x64: Numeric keypad 4 key
              case VK_NUMPAD4:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_4);
              break;

              // 0x65: Numeric keypad 5 key
              case VK_NUMPAD5:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_5);
              break;

              // 0x66: Numeric keypad 6 key
              case VK_NUMPAD6:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_6);
              break;

              // 0x67: Numeric keypad 7 key
              case VK_NUMPAD7:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_7);
              break;

              // 0x68: Numeric keypad 8 key
              case VK_NUMPAD8:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_8);
              break;

              // 0x69: Numeric keypad 9 key
              case VK_NUMPAD9:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_9);
              break;

              // 0x6A: Multiply key
              case VK_MULTIPLY:
                mb_SetCurrentMode(MB_MODE_BASIC);
                mb_CurrentModeWindowRepaint();
                return 1;
              break;

              // 0x6B: Add key
              case VK_ADD:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_PLUS);
              break;

              // 0x6C: Separator key
              case VK_SEPARATOR:

              break;

              // 0x6D: Subtract key
              case VK_SUBTRACT:
                if(mb_GetCurrentMode()->type != MB_MODE_COMMAND){
                  mb_SetCurrentMode(MB_MODE_COMMAND);
                  mb_CurrentModeWindowRepaint();
                  return 1;
                }else{
                  return 0;
                }
              break;

              // 0x6E: Decimal key
              case VK_DECIMAL:
                return mb_GetCurrentWindowOrganizationMode()->keyDownFunc(MB_VKCODE_NUMPAD_PERIOD);
              break;

              // 0x6F: Divide key
              case VK_DIVIDE:
                if(mb_GetCurrentMode()->type != MB_MODE_WORKING){
                  mb_SetCurrentMode(MB_MODE_WORKING);
                  mb_CurrentModeWindowRepaint();
                  return 1;
                }else{
                  return 0;
                }
              break;

              // 0x70: F1 key
              case VK_F1:

              break;

              // 0x71: F2 key
              case VK_F2:

              break;

              // 0x72: F3 key
              case VK_F3:
                mb_HideTaskBar();
              break;

              // 0x73: F4 key
              case VK_F4:
                mb_ShowTaskBar();
              break;

              // 0x74: F5 key
              case VK_F5:
                if(IsWindowVisible((HWND)mb_CurrentModeWindow_HWND())){
                  mb_CurrentModeWindow_Hide();
                  mb_WindowOrganizationModeWindow_Hide();
                  return 1;
                }else{
                  mb_CurrentModeWindow_Show();
                  mb_WindowOrganizationModeWindow_Show();
                  return 1;
                }
              break;

              // 0x75: F6 key
              case VK_F6:

              break;

              // 0x76: F7 key
              case VK_F7:

              break;

              // 0x77: F8 key
              case VK_F8:

              break;

              // 0x78: F9 key
              case VK_F9:

              break;

              // 0x79: F10 key
              case VK_F10:

              break;

              // 0x7A: F11 key
              case VK_F11:

              break;

              // 0x7B: F12 key
              case VK_F12:

              break;

              // 0x7C: F13 key
              case VK_F13:

              break;

              // 0x7D: F14 key
              case VK_F14:

              break;

              // 0x7E: F15 key
              case VK_F15:

              break;

              // 0x7F: F16 key
              case VK_F16:

              break;

              // 0x80: F17 key
              case VK_F17:

              break;

              // 0x81: F18 key
              case VK_F18:

              break;

              // 0x82: F19 key
              case VK_F19:

              break;

              // 0x83: F20 key
              case VK_F20:

              break;

              // 0x84: F21 key
              case VK_F21:

              break;

              // 0x85: F22 key
              case VK_F22:

              break;

              // 0x86: F23 key
              case VK_F23:

              break;

              // 0x87: F24 key
              case VK_F24:

              break;

              // 0x90: NUM LOCK key
              case VK_NUMLOCK:

              break;

              // 0x91: SCROLL LOCK key
              case VK_SCROLL:

              break;

              // 0xA0: Left SHIFT key
              case VK_LSHIFT:

              break;

              // 0xA1: Right SHIFT key
              case VK_RSHIFT:

              break;

              // 0xA2: Left CONTROL key
              case VK_LCONTROL:
                if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
                  mb_WindowOrganizationModeShowAllProcesses();
                  PostQuitMessage(0);
                }
              break;

              // 0xA3: Right CONTROL key
              case VK_RCONTROL:

              break;
            }

            if(ret == 1)return;
            break;

        case WM_KEYUP:
          // if(p->vkCode == MB_VKCODE_LEFT_CONTROL)ret=mb_Keyboard_KEYUP__KEYPAD_RIGHT_CONTROL(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_HOME)ret=mb_Keyboard_KEYUP__HOME(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_PAUSE_BREAK)ret=mb_Keyboard_KEYUP__PAUSE_BREAK(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_PAGE_UP)ret=mb_Keyboard_KEYUP__PAGE_UP(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_PAGE_DOWN)ret=mb_Keyboard_KEYUP__PAGE_DOWN(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_KEYPAD_DIVIDE)ret=mb_Keyboard_KEYUP__KEYPAD_DIVIDE(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_KEYPAD_MINUS)ret=mb_Keyboard_KEYUP__KEYPAD_MINUS(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_KEYPAD_MULTIPLY)ret=mb_Keyboard_KEYUP__KEYPAD_MULTIPLY(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_PLUS)ret=mb_Keyboard_KEYUP__NUMPAD_PLUS(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_ENTER)ret=mb_Keyboard_KEYUP__NUMPAD_ENTER(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_PERIOD)ret=mb_Keyboard_KEYUP__NUMPAD_PERIOD(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_1)ret=mb_Keyboard_KEYUP__NUM_1(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_2)ret=mb_Keyboard_KEYUP__NUM_2(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_3)ret=mb_Keyboard_KEYUP__NUM_3(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_4)ret=mb_Keyboard_KEYUP__NUM_4(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_5)ret=mb_Keyboard_KEYUP__NUM_5(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_6)ret=mb_Keyboard_KEYUP__NUM_6(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_7)ret=mb_Keyboard_KEYUP__NUM_7(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_8)ret=mb_Keyboard_KEYUP__NUM_8(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUM_9)ret=mb_Keyboard_KEYUP__NUM_9(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_1)ret=mb_Keyboard_KEYUP__NUMPAD_1(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_2)ret=mb_Keyboard_KEYUP__NUMPAD_2(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_3)ret=mb_Keyboard_KEYUP__NUMPAD_3(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_4)ret=mb_Keyboard_KEYUP__NUMPAD_4(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_5)ret=mb_Keyboard_KEYUP__NUMPAD_5(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_6)ret=mb_Keyboard_KEYUP__NUMPAD_6(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_7)ret=mb_Keyboard_KEYUP__NUMPAD_7(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_8)ret=mb_Keyboard_KEYUP__NUMPAD_8(nCode, wParam, lParam);
          // else if(p->vkCode == MB_VKCODE_NUMPAD_9)ret=mb_Keyboard_KEYUP__NUMPAD_9(nCode, wParam, lParam);

          switch(p->vkCode)
          {
            // 0x08: BACKSPACE key
            case VK_BACK:

            break;

            // 0x09: TAB key
            case VK_TAB:

            break;

            // 0x0D: ENTER key
            case VK_RETURN:

            break;

            // 0x10: SHIFT key
            case VK_SHIFT:

            break;

            // 0x11: CRTL key
            case VK_CONTROL:

            break;

            // 0x12: ALT key
            case VK_MENU:

            break;

            // 0x13: PAUSE key
            case VK_PAUSE:

            break;

            // 0x14: CAPS LOCK key
            case VK_CAPITAL:

            break;

            // 0x1B: ESC key
            case VK_ESCAPE:

            break;

            // 0x20: SPACEBAR
            case VK_SPACE:

            break;

            // 0x21: PAGE UP key
            case VK_PRIOR:

            break;

            // 0x22: PAGE DOWN key
            case VK_NEXT:

            break;

            // 0x23: END key
            case VK_END:

            break;

            // 0x24: HOME key
            case VK_HOME:

            break;

            // 0x24: LEFT ARROW key
            case VK_LEFT:

            break;

            // 0x26: UP ARROW key
            case VK_UP:

            break;

            // 0x27: RIGHT ARROW key
            case VK_RIGHT:

            break;

            // 0x28: DOWN ARROW key
            case VK_DOWN:

            break;

            //0x29: SELECT key
            case VK_SELECT:

            break;

            // 0x2A: PRINT key
            case VK_PRINT:

            break;

            // 0x2B: EXECUTE key
            case VK_EXECUTE:

            break;

            // 0x2C: PRINT SCREEN key
            case VK_SNAPSHOT:

            break;

            // 0x2D: INS key
            case VK_INSERT:

            break;

            // 0x2E: DEL key
            case VK_DELETE:

            break;

            // 0x2F: HELP key
            case VK_HELP:

            break;

            // 0x30: 0 key
            case 0x30:

            break;

            // 0x31: 1 key
            case 0x31:

            break;

            // 0x32: 2 key
            case 0x32:

            break;

            // 0x33: 3 key
            case 0x33:

            break;

            // 0x34: 4 key
            case 0x34:

            break;

            // 0x35: 5 key
            case 0x35:

            break;

            // 0x36: 6 key
            case 0x36:

            break;

            // 0x37: 7 key
            case 0x37:

            break;

            // 0x38: 8 key
            case 0x38:

            break;

            // 0x39: 9 key
            case 0x39:

            break;

            // 0x41: A key
            case 0x41:

            break;

            // 0x42: B key
            case 0x42:

            break;

            // 0x43: C key
            case 0x43:

            break;

            // 0x44: D key
            case 0x44:

            break;

            // 0x45: E key
            case 0x45:

            break;

            // 0x46: F key
            case 0x46:

            break;

            // 0x47: G key
            case 0x47:

            break;

            // 0x48: H key
            case 0x48:

            break;

            // 0x49: I key
            case 0x49:

            break;

            // 0x4A: J key
            case 0x4A:

            break;

            // 0x4B: K key
            case 0x4B:

            break;

            // 0x4C: L key
            case 0x4C:

            break;

            // 0x4D: M key
            case 0x4D:

            break;

            // 0x4E: N key
            case 0x4E:

            break;

            // 0x4F: O key
            case 0x4F:

            break;

            // 0x50: P key
            case 0x50:

            break;

            // 0x51: Q key
            case 0x51:

            break;

            // 0x52: R key
            case 0x52:

            break;

            // 0x53: S key
            case 0x53:

            break;

            // 0x54: T key
            case 0x54:

            break;

            // 0x55: U key
            case 0x55:

            break;

            // 0x56: V key
            case 0x56:

            break;

            // 0x57: W key
            case 0x57:

            break;

            // 0x58: X key
            case 0x58:

            break;

            // 0x59: Y key
            case 0x59:

            break;

            // 0x5A: Z key
            case 0x5A:

            break;

            // 0x5B: Left Windows key (Natural keyboard)
            case VK_LWIN:

            break;

            // 0x5C Right Windows key (Natural keyboard)
            case VK_RWIN:

            break;

            // 0x60: Numeric keypad 0 key
            case VK_NUMPAD0:

            break;

            // 0x61: Numeric keypad 1 key
            case VK_NUMPAD1:

            break;

            // 0x62: Numeric keypad 2 key
            case VK_NUMPAD2:

            break;

            // 0x63: Numeric keypad 3 key
            case VK_NUMPAD3:

            break;

            // 0x64: Numeric keypad 4 key
            case VK_NUMPAD4:

            break;

            // 0x65: Numeric keypad 5 key
            case VK_NUMPAD5:

            break;

            // 0x66: Numeric keypad 6 key
            case VK_NUMPAD6:

            break;

            // 0x67: Numeric keypad 7 key
            case VK_NUMPAD7:

            break;

            // 0x68: Numeric keypad 8 key
            case VK_NUMPAD8:

            break;

            // 0x69: Numeric keypad 9 key
            case VK_NUMPAD9:

            break;

            // 0x6A: Multiply key
            case VK_MULTIPLY:

            break;

            // 0x6B: Add key
            case VK_ADD:

            break;

            // 0x6C: Separator key
            case VK_SEPARATOR:

            break;

            // 0x6D: Subtract key
            case VK_SUBTRACT:

            break;

            // 0x6E: Decimal key
            case VK_DECIMAL:

            break;

            // 0x6F: Divide key
            case VK_DIVIDE:

            break;

            // 0x70: F1 key
            case VK_F1:

            break;

            // 0x71: F2 key
            case VK_F2:

            break;

            // 0x72: F3 key
            case VK_F3:

            break;

            // 0x73: F4 key
            case VK_F4:

            break;

            // 0x74: F5 key
            case VK_F5:

            break;

            // 0x75: F6 key
            case VK_F6:

            break;

            // 0x76: F7 key
            case VK_F7:

            break;

            // 0x77: F8 key
            case VK_F8:

            break;

            // 0x78: F9 key
            case VK_F9:

            break;

            // 0x79: F10 key
            case VK_F10:

            break;

            // 0x7A: F11 key
            case VK_F11:

            break;

            // 0x7B: F12 key
            case VK_F12:

            break;

            // 0x7C: F13 key
            case VK_F13:

            break;

            // 0x7D: F14 key
            case VK_F14:

            break;

            // 0x7E: F15 key
            case VK_F15:

            break;

            // 0x7F: F16 key
            case VK_F16:

            break;

            // 0x80: F17 key
            case VK_F17:

            break;

            // 0x81: F18 key
            case VK_F18:

            break;

            // 0x82: F19 key
            case VK_F19:

            break;

            // 0x83: F20 key
            case VK_F20:

            break;

            // 0x84: F21 key
            case VK_F21:

            break;

            // 0x85: F22 key
            case VK_F22:

            break;

            // 0x86: F23 key
            case VK_F23:

            break;

            // 0x87: F24 key
            case VK_F24:

            break;

            // 0x90: NUM LOCK key
            case VK_NUMLOCK:

            break;

            // 0x91: SCROLL LOCK key
            case VK_SCROLL:

            break;

            // 0xA0: Left SHIFT key
            case VK_LSHIFT:

            break;

            // 0xA1: Right SHIFT key
            case VK_RSHIFT:

            break;

            // 0xA2: Left CONTROL key
            case VK_LCONTROL:

            break;

            // 0xA3: Right CONTROL key
            case VK_RCONTROL:

            break;
          }

          break;

        case WM_SYSKEYDOWN:
          break;

        case WM_SYSKEYUP:
          break;
        }
    }

    // call the next hook in the hook chain. This is nessecary or your hook chain will break and the hook stops
    return CallNextHookEx(_hookKeyboard, nCode, wParam, lParam);
}
void mb_SetKeyboardHook(){
  if (!(_hookKeyboard = SetWindowsHookEx(WH_KEYBOARD_LL, mb_HookKeyboardCallback, NULL, 0)))
  {
    MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
  }
}
void mb_ReleaseKeyboardHook(){
  UnhookWindowsHookEx(_hookKeyboard);
}
