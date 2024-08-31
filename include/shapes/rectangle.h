// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#pragma once
#include <SDL.h>

class ANGE_Rectangle {
 public:
  ANGE_Rectangle(int, int, int, int, Uint8, Uint8, Uint8, Uint8);
  void draw(SDL_Renderer*) const;

 private:
  SDL_Rect rect_;
  SDL_Color color_;
};
