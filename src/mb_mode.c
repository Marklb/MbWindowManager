#include "mb_mode.h"

mb_Mode mode_list[3];
mb_Mode *current_mode;

void mb_InitializeModes(){
  mode_list[MB_MODE_BASIC].type = MB_MODE_BASIC;
  mode_list[MB_MODE_BASIC].name = "Basic";
  mode_list[MB_MODE_COMMAND].type = MB_MODE_COMMAND;
  mode_list[MB_MODE_COMMAND].name = "Command";
  mode_list[MB_MODE_WORKING].type = MB_MODE_WORKING;
  mode_list[MB_MODE_WORKING].name = "Working";

  current_mode = &mode_list[MB_MODE_BASIC];
}

mb_Mode * mb_GetMode(int mode_type){
  return &mode_list[mode_type];
}

mb_Mode * mb_GetCurrentMode(){
  return current_mode;
}

void mb_SetCurrentMode(int mode_type){
  current_mode = &mode_list[mode_type];
}
