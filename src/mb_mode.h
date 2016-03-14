#ifndef MB_MODE_H
#define MB_MODE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Mode Ids
#define MB_MODE_BASIC 0
#define MB_MODE_COMMAND 1
#define MB_MODE_WORKING 2


struct mb_Mode_t{
  int type;
  // char name[256];
  char *name;
}typedef mb_Mode;

void mb_InitializeModes();

mb_Mode * mb_GetMode(int mode_type);

mb_Mode * mb_GetCurrentMode();

void mb_SetCurrentMode(int mode_type);

#endif // MB_MODE_H
