#ifndef MB_WINDOW_SPEC_H
#define MB_WINDOW_SPEC_H


struct mb_WindowSpec_t{
  char name[32];
  int isSelectedSpec;
  HWND hwnd;
  RECT winRect;
  int activateKey;
}typedef mb_WindowSpec;


mb_WindowSpec_Init(mb_WindowSpec *winSpec, char *name);


#endif // MB_WINDOW_SPEC_H
