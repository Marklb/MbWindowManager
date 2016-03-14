#ifndef MB_WINDOW_ORGANIZATION_MODE_H
#define MB_WINDOW_ORGANIZATION_MODE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Mode Ids
#define MB_WINDOW_ORGANIZATION_MODE_BASIC 0
#define MB_WINDOW_ORGANIZATION_MODE_C_PROGRAMMING 1
#define MB_WINDOW_ORGANIZATION_MODE_MATLAB 2
#define MB_WINDOW_ORGANIZATION_MODE_MATLAB2 3

typedef void (*mb_window_organization_mode_func)();
typedef int (*mb_window_organization_mode_key_func)(int);

struct mb_WindowOrganizationMode_t{
  int type;
  char *name;
  HWND *processes;
  mb_window_organization_mode_func func;
  mb_window_organization_mode_key_func keyDownFunc;
  mb_window_organization_mode_key_func keyUpFunc;
}typedef mb_WindowOrganizationMode;

void mb_InitializeWindowOrganizationModes();

mb_WindowOrganizationMode * mb_GetWindowOrganizationMode(int mode_type);

mb_WindowOrganizationMode * mb_GetCurrentWindowOrganizationMode();

void mb_SetCurrentWindowOrganizationMode(int mode_type);

void mb_WindowOrganizationModeShowAllProcesses();

#endif // MB_WINDOW_ORGANIZATION_MODE_H
