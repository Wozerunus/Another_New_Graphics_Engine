// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class ANGE_Text {
 public:
  ANGE_Text(int,
             int,
             std::wstring,
             std::string,
             int, Uint8,
             Uint8,
             Uint8,
             Uint8);
  void draw(SDL_Renderer*);

 private:
  int x_, y_, size_;
  std::wstring message_;
  TTF_Font* font_;
  SDL_Surface* surface_;
};
