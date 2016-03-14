#include "mb_window_organization_mode.h"
#include "mb_window_organization_mode_gui.h"
#include "mb_keyboard.h"
#include "mb_mode.h"


mb_WindowOrganizationMode mb_window_organization_mode_list[4];
mb_WindowOrganizationMode *mb_window_organization_current_mode;

///////////////////////////////////////////////////////////////////////////////
HWND mb_wom_basic_hwnds[9];
void mb_WindowOrganizationMode_Basic_Func(){

}

int mb_WindowOrganizationMode_Basic_KeyDown_Func(int mb_vkCode){
  return 0;
}

int mb_WindowOrganizationMode_Basic_KeyUp_Func(int mb_vkCode){
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
HWND mb_wom_c_programming_hwnds[9];
void mb_WindowOrganizationMode_C_Programming_Func(){

}

// void SetForegroundWindowInternal(HWND hWnd)
// {
// 	if(!IsWindow(hWnd)) return;
//
// 	//relation time of SetForegroundWindow lock
// 	DWORD lockTimeOut = 0;
// 	HWND  hCurrWnd = GetForegroundWindow();
// 	DWORD dwThisTID = GetCurrentThreadId(),
// 	      dwCurrTID = GetWindowThreadProcessId(hCurrWnd,0);
//
// 	//we need to bypass some limitations from Microsoft :)
// 	if(dwThisTID != dwCurrTID)
// 	{
// 		AttachThreadInput(dwThisTID, dwCurrTID, TRUE);
//
// 		SystemParametersInfo(SPI_GETFOREGROUNDLOCKTIMEOUT,0,&lockTimeOut,0);
// 		SystemParametersInfo(SPI_SETFOREGROUNDLOCKTIMEOUT,0,0,SPIF_SENDWININICHANGE | SPIF_UPDATEINIFILE);
//
// 		AllowSetForegroundWindow(ASFW_ANY);
// 	}
//
// 	SetForegroundWindow(hWnd);
//
// 	if(dwThisTID != dwCurrTID)
// 	{
// 		SystemParametersInfo(SPI_SETFOREGROUNDLOCKTIMEOUT,0,(PVOID)lockTimeOut,SPIF_SENDWININICHANGE | SPIF_UPDATEINIFILE);
// 		AttachThreadInput(dwThisTID, dwCurrTID, FALSE);
// 	}
// }




int mb_WindowOrganizationMode_C_Programming_KeyDown_Func(int mb_vkCode){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    if(mb_vkCode == MB_VKCODE_NUMPAD_1){
      mb_wom_c_programming_hwnds[0] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_2){
      mb_wom_c_programming_hwnds[1] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_3){
      mb_wom_c_programming_hwnds[2] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_4){
      mb_wom_c_programming_hwnds[3] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_5){
      mb_wom_c_programming_hwnds[4] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_6){
      mb_wom_c_programming_hwnds[5] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_7){
      mb_wom_c_programming_hwnds[6] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_8){
      mb_wom_c_programming_hwnds[7] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_9){
      mb_wom_c_programming_hwnds[8] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_PLUS){
      int i;
      for(i = 0; i < 9; i++){
        printf("C Programming HWND %d: %d\n", (i+1), mb_wom_c_programming_hwnds[i]);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_ENTER){
      int i;
      for(i = 0; i < 9; i++){
        if(mb_wom_c_programming_hwnds[i] != 0){
          if(i == 0 || i == 1){
            // 1: Atom, 2: Terminal
            MoveWindow(mb_wom_c_programming_hwnds[i], 2, 2, 1920-2-2, 1080-2-2, true);
            // Remove Caption
            LONG lStyle = GetWindowLong(mb_wom_c_programming_hwnds[i], GWL_STYLE);
            lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU); // Remove Caption bar
            // lStyle |= WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU; // Enable Caption bar
            SetWindowLongPtr(mb_wom_c_programming_hwnds[i], GWL_STYLE, lStyle);
            // Remove the extended border styles
            // LONG lExStyle = GetWindowLong(mb_wom_c_programming_hwnds[i], GWL_EXSTYLE);
            // lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
            // SetWindowLongPtr(mb_wom_c_programming_hwnds[i], GWL_EXSTYLE, lExStyle);
            // Redraw with new style
            SetWindowPos(mb_wom_c_programming_hwnds[i], NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
          }
        }
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_PERIOD){
      int i;
      for(i = 0; i < 9; i++){
        mb_wom_c_programming_hwnds[i] = 0;
      }
      return 1;
    }
  }
  if(mb_GetCurrentMode()->type == MB_MODE_WORKING){
    // TODO: FIX this
    if(mb_vkCode == MB_VKCODE_NUMPAD_1){
      printf("Activate: %d\n", mb_wom_c_programming_hwnds[0]);
      // ShowWindow(mb_wom_c_programming_hwnds[0], SW_HIDE);
      // ShowWindow(mb_wom_c_programming_hwnds[0], SW_SHOW);
      // SetForegroundWindow(mb_wom_c_programming_hwnds[0]);
      // SetForegroundWindowInternal(mb_wom_c_programming_hwnds[0]);
      // SetActiveWindow(mb_wom_c_programming_hwnds[0]);
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[0]);
        // ShowWindow(mb_wom_c_programming_hwnds[0], SW_HIDE);
        // ShowWindow(mb_wom_c_programming_hwnds[0], SW_SHOW);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_2){
      printf("Activate: %d\n", mb_wom_c_programming_hwnds[1]);
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[1]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_3){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[2]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_4){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[3]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_5){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[4]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_6){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[5]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_7){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[6]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_8){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[7]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_9){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_c_programming_hwnds[8]);
        Sleep(30);
      }
      return 1;
    }
  }
  return 0;
}

int mb_WindowOrganizationMode_C_Programming_KeyUp_Func(int mb_vkCode){
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
HWND mb_wom_matlab_hwnds[9];
void mb_WindowOrganizationMode_Matlab_Func(){

}

int mb_WindowOrganizationMode_Matlab_KeyDown_Func(int mb_vkCode){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    if(mb_vkCode == MB_VKCODE_NUMPAD_1){
      mb_wom_matlab_hwnds[0] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_2){
      mb_wom_matlab_hwnds[1] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_3){
      mb_wom_matlab_hwnds[2] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_4){
      mb_wom_matlab_hwnds[3] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_5){
      mb_wom_matlab_hwnds[4] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_6){
      mb_wom_matlab_hwnds[5] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_7){
      mb_wom_matlab_hwnds[6] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_8){
      mb_wom_matlab_hwnds[7] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_9){
      mb_wom_matlab_hwnds[8] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_PLUS){
      int i;
      for(i = 0; i < 9; i++){
        printf("Matlab HWND %d: %d\n", (i+1), mb_wom_matlab_hwnds[i]);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_ENTER){
      printf("Matlab Pressed Enter: %d\n", MB_VKCODE_NUMPAD_ENTER);
      int i;
      // for(i = 0; i < 9; i++){
      //   HWND tmpHwnd = mb_wom_matlab_hwnds[i];
      //   if(tmpHwnd != 0){
      //     int gap = 2;
      //     int scrn_w = 1920;
      //     int scrn_h = 1080;
      //     // Atom
      //     int atom_x, atom_y, atom_w, atom_h;
      //     // Command Window
      //     int cmdWin_crop_x, cmdWin_crop_y, cmdWin_crop_w, cmdWin_crop_h;
      //     int cmdWin_x, cmdWin_y, cmdWin_w, cmdWin_h;
      //     // Workspace Window
      //     int wrkSp_crop_x, wrkSp_crop_y, wrkSp_crop_w, wrkSp_crop_h;
      //     int wrkSp_x, wrkSp_y, wrkSp_w, wrkSp_h;
      //
      //     cmdWin_h = 250;
      //     cmdWin_w = scrn_w;
      //     wrkSp_w = 250;
      //     wrkSp_h = scrn_h-cmdWin_h;
      //     atom_w = scrn_w-wrkSp_w;
      //     atom_h = scrn_h-cmdWin_h;
      //
      //     atom_x = 0;
      //     atom_y = 0;
      //     cmdWin_x = 0;
      //     cmdWin_y = scrn_h-cmdWin_h;
      //     wrksp_x = 0;
      //     wrksp_y = scrn_h-cmdWin_h;
      //
      //     if(i == 0){
      //       // 1: Atom
      //       MoveWindow(tmpHwnd, atom_x, atom_y, atom_w, atom_h, true);
      //       // Remove Caption
      //       LONG lStyle = GetWindowLong(tmpHwnd, GWL_STYLE);
      //       lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU); // Remove Caption bar
      //       // lStyle |= WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU; // Enable Caption bar
      //       SetWindowLongPtr(tmpHwnd, GWL_STYLE, lStyle);
      //       // Remove the extended border styles
      //       // LONG lExStyle = GetWindowLong(tmpHwnd, GWL_EXSTYLE);
      //       // lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
      //       // SetWindowLongPtr(tmpHwnd, GWL_EXSTYLE, lExStyle);
      //       // Redraw with new style
      //       SetWindowPos(tmpHwnd, NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
      //     }else if(i == 1){
      //       // 2: Command Window
      //       int xCrop = 10;
      //       int yCrop = 10;
      //       int wCrop = 17;
      //       int hCrop = 24;
      //       HRGN hrgn = CreateRectRgn(xCrop,yCrop,(1920-2)-(wCrop)+(wCrop*2),(202)-(hCrop)+(hCrop*2));
      //       SetWindowRgn(tmpHwnd, hrgn, TRUE);
      //       DeleteObject(hrgn);
      //
      //       MoveWindow(tmpHwnd, (2)-xCrop, (1080-2-2-200)-yCrop, (1920-2)+(wCrop*2), (202)+(hCrop*2), true);
      //       // Remove Caption
      //       LONG lStyle = GetWindowLong(tmpHwnd, GWL_STYLE);
      //       lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
      //       SetWindowLongPtr(tmpHwnd, GWL_STYLE, lStyle);
      //       // Redraw with new style
      //       SetWindowPos(tmpHwnd, NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
      //     }else if(i == 2){
      //       // 3: Workspace
      //       int xCrop = 15;
      //       int yCrop = 78;
      //       int wCrop = 1;
      //       int hCrop = 42;
      //       HRGN hrgn = CreateRectRgn(xCrop,yCrop,(214)-(wCrop)+(wCrop*2),(1080-2-2-4-164)-(hCrop)+(hCrop*2));
      //       SetWindowRgn(tmpHwnd, hrgn, TRUE);
      //       DeleteObject(hrgn);
      //
      //       MoveWindow(tmpHwnd, (1920-2-200)-xCrop, (2)-yCrop, (214)+(wCrop*2), (1080-2-2-4-164)+(hCrop*2), true);
      //       // Remove Caption
      //       LONG lStyle = GetWindowLong(tmpHwnd, GWL_STYLE);
      //       lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
      //       SetWindowLongPtr(tmpHwnd, GWL_STYLE, lStyle);
      //       // Redraw with new style
      //       SetWindowPos(tmpHwnd, NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
      //     }
      //   }
      // }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_PERIOD){
      int i;
      for(i = 0; i < 9; i++){
        mb_wom_matlab_hwnds[i] = 0;
      }
      return 1;
    }
  }
  if(mb_GetCurrentMode()->type == MB_MODE_WORKING){
    // TODO: FIX this
    if(mb_vkCode == MB_VKCODE_NUMPAD_1){
      printf("Activate: %d\n", mb_wom_matlab_hwnds[0]);
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[0]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_2){
      printf("Activate: %d\n", mb_wom_matlab_hwnds[1]);
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[1]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_3){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[2]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_4){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[3]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_5){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[4]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_6){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[5]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_7){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[6]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_8){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[7]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_9){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab_hwnds[8]);
        Sleep(30);
      }
      return 1;
    }
  }
  return 0;
}

int mb_WindowOrganizationMode_Matlab_KeyUp_Func(int mb_vkCode){
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
HWND mb_wom_matlab2_hwnds[9];
void mb_WindowOrganizationMode_Matlab2_Func(){

}

int mb_WindowOrganizationMode_Matlab2_KeyDown_Func(int mb_vkCode){
  if(mb_GetCurrentMode()->type == MB_MODE_COMMAND){
    if(mb_vkCode == MB_VKCODE_NUMPAD_1){
      mb_wom_matlab2_hwnds[0] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_2){
      mb_wom_matlab2_hwnds[1] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_3){
      mb_wom_matlab2_hwnds[2] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_4){
      mb_wom_matlab2_hwnds[3] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_5){
      mb_wom_matlab2_hwnds[4] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_6){
      mb_wom_matlab2_hwnds[5] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_7){
      mb_wom_matlab2_hwnds[6] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_8){
      mb_wom_matlab2_hwnds[7] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_9){
      mb_wom_matlab2_hwnds[8] = GetForegroundWindow();
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_PLUS){
      int i;
      for(i = 0; i < 9; i++){
        printf("Matlab2 HWND %d: %d\n", (i+1), mb_wom_matlab2_hwnds[i]);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_ENTER){
      printf("Pressed NUMPAD_ENTER");
      int i;
      for(i = 0; i < 9; i++){
        if(mb_wom_matlab2_hwnds[i] != 0){
          if(i == 0){
            // 1: Atom
            // MoveWindow(mb_wom_matlab2_hwnds[i], 2, 2, 1920-2-2-2-200, 1080-2-2-4-200, true); // Desktop Home
            MoveWindow(mb_wom_matlab2_hwnds[i], 2, 2, (1920-4-250-2), (1080-4-250), true); // Desktop Lab
            // Remove Caption
            LONG lStyle = GetWindowLong(mb_wom_matlab2_hwnds[i], GWL_STYLE);
            lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU); // Remove Caption bar
            // lStyle |= WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU; // Enable Caption bar
            SetWindowLongPtr(mb_wom_matlab2_hwnds[i], GWL_STYLE, lStyle);
            // Remove the extended border styles
            // LONG lExStyle = GetWindowLong(mb_wom_matlab_hwnds[i], GWL_EXSTYLE);
            // lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
            // SetWindowLongPtr(mb_wom_matlab_hwnds[i], GWL_EXSTYLE, lExStyle);
            // Redraw with new style
            SetWindowPos(mb_wom_matlab2_hwnds[i], NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
          }else if(i == 1){
            // 2: Command Window
            // int xCrop = 19;
            // int yCrop = 25;
            // int wCrop = 17;
            // int hCrop = 24;
            // HRGN hrgn = CreateRectRgn(xCrop,yCrop,(1920-2)-(wCrop)+(wCrop*2),(202)-(hCrop)+(hCrop*2)); // Home Desktop
            // WinSet, Region, 20-2 W1916 H217, %title% ; With taskbar scale
            HRGN hrgn = CreateRectRgn(20,2,1916,217); // Lab Desktop
            SetWindowRgn(mb_wom_matlab2_hwnds[i], hrgn, TRUE);
            DeleteObject(hrgn);

            // MoveWindow(mb_wom_matlab2_hwnds[i], (2)-xCrop, (1080-2-2-200)-yCrop, (1920-2)+(wCrop*2), (202)+(hCrop*2), true); // Home Desktop
            // WinMove, %title%,, (2-20), (2+(1080-4-250)), (1920-3+20), (247-2) ; With taskbar scale
            MoveWindow(mb_wom_matlab2_hwnds[i], 2-20, (2+(1080-4-250)), (1920-3+20), (247-2), true); // Lab Desktop
            // Remove Caption
            LONG lStyle = GetWindowLong(mb_wom_matlab2_hwnds[i], GWL_STYLE);
            lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
            SetWindowLongPtr(mb_wom_matlab2_hwnds[i], GWL_STYLE, lStyle);
            // Redraw with new style
            SetWindowPos(mb_wom_matlab2_hwnds[i], NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
          }else if(i == 2){
            // 3: Workspace
            // int xCrop = 15;
            // int yCrop = 78;
            // int wCrop = 1;
            // int hCrop = 42;
            // HRGN hrgn = CreateRectRgn(xCrop,yCrop,(214)-(wCrop)+(wCrop*2),(1080-2-2-4-164)-(hCrop)+(hCrop*2)); // Home Desktop
            // WinSet, Region, 2-29 W250 H826, %title%
            HRGN hrgn = CreateRectRgn(2, 29, 250, 826); // Lab Desktop
            SetWindowRgn(mb_wom_matlab2_hwnds[i], hrgn, TRUE);
            DeleteObject(hrgn);

            // MoveWindow(mb_wom_matlab2_hwnds[i], (1920-2-200)-xCrop, (2)-yCrop, (214)+(wCrop*2), (1080-2-2-4-164)+(hCrop*2), true); // Home Desktop
            // WinMove, %title%,, (1920-250-2-2), (2-29), (250+4), (1080-4-250+29+45)
            MoveWindow(mb_wom_matlab2_hwnds[i], (1920-250-2-2), (2-29), (250+4), (1080-4-250+29+45), true); // Lab Desktop
            // Remove Caption
            LONG lStyle = GetWindowLong(mb_wom_matlab2_hwnds[i], GWL_STYLE);
            lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
            SetWindowLongPtr(mb_wom_matlab2_hwnds[i], GWL_STYLE, lStyle);
            // Redraw with new style
            SetWindowPos(mb_wom_matlab2_hwnds[i], NULL, 0,0,0,0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
          }
        }
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_PERIOD){
      int i;
      for(i = 0; i < 9; i++){
        mb_wom_matlab2_hwnds[i] = 0;
      }
      return 1;
    }
  }
  if(mb_GetCurrentMode()->type == MB_MODE_WORKING){
    // TODO: FIX this
    if(mb_vkCode == MB_VKCODE_NUMPAD_1){
      printf("Activate: %d\n", mb_wom_matlab2_hwnds[0]);
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[0]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_2){
      printf("Activate: %d\n", mb_wom_matlab2_hwnds[1]);
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[1]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_3){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[2]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_4){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[3]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_5){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[4]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_6){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[5]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_7){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[6]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_8){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[7]);
        Sleep(30);
      }
      return 1;
    }else if(mb_vkCode == MB_VKCODE_NUMPAD_9){
      int i;
      // Used to fix bug with focus going back to previous window
      for(i = 0; i < 5; i++){
        SetForegroundWindow(mb_wom_matlab2_hwnds[8]);
        Sleep(30);
      }
      return 1;
    }
  }
  return 0;
}

int mb_WindowOrganizationMode_Matlab2_KeyUp_Func(int mb_vkCode){
  return 0;
}




void mb_InitializeWindowOrganizationModes(){
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC].type = MB_WINDOW_ORGANIZATION_MODE_BASIC;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC].name = "Basic";
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC].func = &mb_WindowOrganizationMode_Basic_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC].keyDownFunc = &mb_WindowOrganizationMode_Basic_KeyDown_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC].keyUpFunc = &mb_WindowOrganizationMode_Basic_KeyUp_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC].processes = mb_wom_basic_hwnds;

  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING].type = MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING].name = "C Programming";
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING].func = &mb_WindowOrganizationMode_C_Programming_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING].keyDownFunc = &mb_WindowOrganizationMode_C_Programming_KeyDown_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING].keyUpFunc = &mb_WindowOrganizationMode_C_Programming_KeyUp_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING].processes = mb_wom_c_programming_hwnds;

  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB].type = MB_WINDOW_ORGANIZATION_MODE_MATLAB;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB].name = "Matlab";
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB].func = &mb_WindowOrganizationMode_Matlab_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB].keyDownFunc = &mb_WindowOrganizationMode_Matlab_KeyDown_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB].keyUpFunc = &mb_WindowOrganizationMode_Matlab_KeyUp_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB].processes = mb_wom_matlab_hwnds;

  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB2].type = MB_WINDOW_ORGANIZATION_MODE_MATLAB2;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB2].name = "Matlab2";
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB2].func = &mb_WindowOrganizationMode_Matlab2_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB2].keyDownFunc = &mb_WindowOrganizationMode_Matlab2_KeyDown_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB2].keyUpFunc = &mb_WindowOrganizationMode_Matlab2_KeyUp_Func;
  mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_MATLAB2].processes = mb_wom_matlab2_hwnds;

  mb_window_organization_current_mode = &mb_window_organization_mode_list[MB_WINDOW_ORGANIZATION_MODE_BASIC];
}

mb_WindowOrganizationMode * mb_GetWindowOrganizationMode(int mode_type){
  return &mb_window_organization_mode_list[mode_type];
}

mb_WindowOrganizationMode * mb_GetCurrentWindowOrganizationMode(){
  return mb_window_organization_current_mode;
}

void mb_WindowOrganizationModeShowProcesses(mb_WindowOrganizationMode *org_mode){
  int i;
  for(i = 0; i < 9; i++){
    printf("Proc[%d]: %d\n", i, org_mode->processes[i]);
    if(org_mode->processes[i] != 0){
      // ShowWindow(org_mode->processes[i], SW_MAXIMIZE);
      ShowWindow(org_mode->processes[i], SW_SHOW);
    }
  }
}

void mb_WindowOrganizationModeHideProcesses(mb_WindowOrganizationMode *org_mode){
  int i;
  for(i = 0; i < 9; i++){
    printf("Proc[%d]: %d\n", i, org_mode->processes[i]);
    if(org_mode->processes[i] != 0){
      // ShowWindow(org_mode->processes[i], SW_MINIMIZE);
      ShowWindow(org_mode->processes[i], SW_HIDE);
    }
  }
}

void mb_WindowOrganizationModeShowAllProcesses(){
  int i ;
  for(i = 0; i < 4; i++){
    mb_WindowOrganizationModeShowProcesses(&mb_window_organization_mode_list[i]);
  }
}

void mb_SetCurrentWindowOrganizationMode(int mode_type){
  mb_WindowOrganizationModeHideProcesses(mb_window_organization_current_mode);
  mb_window_organization_current_mode = &mb_window_organization_mode_list[mode_type];
  mb_WindowOrganizationModeShowProcesses(mb_window_organization_current_mode);
  mb_WindowOrganizationModeWindowRepaint();
}
