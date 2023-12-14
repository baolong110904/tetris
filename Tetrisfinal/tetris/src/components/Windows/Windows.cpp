#pragma once
#include <iostream>
#include <windows.h>
#include <map>
#include <string>
#include <conio.h>
#include <vector>


using namespace std;
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
// SOUNDTRACK
#define MOVE_SOUND 0
#define ENTER_SOUND 1
#define ERROR_SOUND 2
#define WIN_SOUND 4
#define BACKGROUND_SOUND 5
#define EFFECT_SOUND 6

// MOVEMENT
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

class Windows {
public:
  Windows() {};
  static void setWindowSize(short width, short height) {
    SMALL_RECT WindowSize = {0, 0, width, height};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &WindowSize);
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), {width, height});
  }
  static void disableResizeWindow() {
    SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX);
  }
  static void disableCtrButton(bool close, bool min, bool max) {
    HMENU hMenu = GetSystemMenu(GetConsoleWindow(), false);
    if (close) DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    if (min) DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    if (max) DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
  }
  static void disableScrollbar() {
    ShowScrollBar(GetConsoleWindow(), SB_BOTH, false);
  }
  static void disableSelect() {
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ~ENABLE_QUICK_EDIT_MODE);
  }
  static void hideCursor() {
    CONSOLE_CURSOR_INFO ConCurInf = {10, false};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
  }
  // static void setConsoleTitle(string title) {
  //   SetConsoleTitle(title.c_str());
  // }
  static void setUnicodeOutput() {
    SetConsoleOutputCP(65001);
  }
  static void setColor(string textColor, string backgroundColor) {
    map <string, int> colorMap;
    colorMap["black"] = 0;
    colorMap["blue"] = 1;
    colorMap["green"] = 2;
    colorMap["aqua"] = 3;
    colorMap["red"] = 4;
    colorMap["purple"] = 5;
    colorMap["yellow"] = 6;
    colorMap["white"] = 7;
    colorMap["gray"] = 8;
    colorMap["lightblue"] = 9;
    colorMap["lightgreen"] = 10;
    colorMap["lightaqua"] = 11;
    colorMap["lightred"] = 12;
    colorMap["lightpurple"] = 13;
    colorMap["lightyellow"] = 14;
    colorMap["brightwhite"] = 15;
    int color_code = colorMap[backgroundColor] * 16 + colorMap[textColor];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
  }
  static void goTo(pair <int, int> pos, pair <int, int> startPos = {0, 0}) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short) (pos.first + startPos.first), (short) (pos.second + startPos.second)});
  }
  // static void playSound(int i)
  // {
  //   static vector<const wchar_t*> soundFile{L"move.wav", L"enter.wav", L"error.wav", L"placed.wav", L"win.wav",  L"background.wav", L"effect.wav" };
  //   PlaySoundA(reinterpret_cast<LPCSTR>(soundFile[i]), NULL, SND_FILENAME | SND_ASYNC);
  // }
  static void clearConsole()
  {
    system("cls");
  }
  static int getConsoleInput(){
      int c = _getch();
	  // Arrow key
    if (c == 0 || c == 224){
      switch (_getch())
      {
      case KEY_UP:				//lên
        return 2;
      case KEY_LEFT:				//trái
        return 3;
      case KEY_RIGHT:				//phải
        return 4;
      case KEY_DOWN:				//xuống
        return 5;
      default:				//nút khác
        return 0;
      }
    }
    else{
      if (c == KEY_ESC)                  //esc
        return 1;
      else if (c == 87 || c == 119) //W, w
        return 2;
      else if (c == 65 || c == 97)  //A, a
        return 3;
      else if (c == 68 || c == 100) //D, d
        return 4;
      else if (c == 83 || c == 115) //S, s
        return 5;
      else if (c == 13)             //Enter
        return 6;
      else if (c == 72 || c == 104) //H, h
        return 7;
      else if (c == 77 || c == 109) // M, m
        return 8;
      else
        return 0;                 //nút khác
    }
  } 
  static void gotoXY(int pX, int pY){
    SetConsoleCursorPosition(consoleOutput, COORD{ (short)pX, (short)pY });
  }
};
