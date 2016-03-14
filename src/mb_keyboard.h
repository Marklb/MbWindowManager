#ifndef MB_KEYBOARD_H
#define MB_KEYBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define MB_VKCODE_LEFT_SHIFT 0xA0
#define MB_VKCODE_RIGHT_SHIFT 0xA1
#define MB_VKCODE_LEFT_CONTROL 0xA2
#define MB_VKCODE_RIGHT_CONTROL 0xA3
#define MB_VKCODE_INCREASE_VOLUME 0xAF
#define MB_VKCODE_KEYPAD_DIVIDE 0x6f
#define MB_VKCODE_KEYPAD_MINUS 0x6d
#define MB_VKCODE_KEYPAD_MULTIPLY 0x6a
#define MB_VKCODE_NUMPAD_PLUS 0x6b
#define MB_VKCODE_NUMPAD_ENTER 0xd
#define MB_VKCODE_NUMPAD_PERIOD 0x6e
#define MB_VKCODE_RIGHT_CONTROL 0xA3
#define MB_VKCODE_PAUSE_BREAK 0x13
#define MB_VKCODE_HOME 0x24
#define MB_VKCODE_PAGE_UP 0x21
#define MB_VKCODE_PAGE_DOWN 0x22
#define MB_VKCODE_NUM_1 0x31
#define MB_VKCODE_NUM_2 0x32
#define MB_VKCODE_NUM_3 0x33
#define MB_VKCODE_NUM_4 0x34
#define MB_VKCODE_NUM_5 0x35
#define MB_VKCODE_NUM_6 0x36
#define MB_VKCODE_NUM_7 0x37
#define MB_VKCODE_NUM_8 0x38
#define MB_VKCODE_NUM_9 0x39
#define MB_VKCODE_NUMPAD_1 0x61
#define MB_VKCODE_NUMPAD_2 0x62
#define MB_VKCODE_NUMPAD_3 0x63
#define MB_VKCODE_NUMPAD_4 0x64
#define MB_VKCODE_NUMPAD_5 0x65
#define MB_VKCODE_NUMPAD_6 0x66
#define MB_VKCODE_NUMPAD_7 0x67
#define MB_VKCODE_NUMPAD_8 0x68
#define MB_VKCODE_NUMPAD_9 0x69







#define MB_VKCODE_A 0x41
#define MB_VKCODE_B 0x42
#define MB_VKCODE_C 0x43
#define MB_VKCODE_D 0x44
#define MB_VKCODE_E 0x45
#define MB_VKCODE_F 0x46
#define MB_VKCODE_G 0x47
#define MB_VKCODE_H 0x48
#define MB_VKCODE_I 0x49
#define MB_VKCODE_J 0x4a
#define MB_VKCODE_K 0x4b
#define MB_VKCODE_L 0x4c
#define MB_VKCODE_M 0x4d
#define MB_VKCODE_N 0x4e
#define MB_VKCODE_O 0x4f
#define MB_VKCODE_P 0x50
#define MB_VKCODE_Q 0x51
#define MB_VKCODE_R 0x52
#define MB_VKCODE_S 0x53
#define MB_VKCODE_T 0x54
#define MB_VKCODE_U 0x55
#define MB_VKCODE_V 0x56
#define MB_VKCODE_W 0x57
#define MB_VKCODE_X 0x58
#define MB_VKCODE_Y 0x59
#define MB_VKCODE_Z 0x5a



void mb_SetKeyboardHook();

void mb_ReleaseKeyboardHook();


#endif // MB_KEYBOARD_H
