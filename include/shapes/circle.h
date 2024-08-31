// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#pragma once
#include <SDL.h>

class ANGE_Circle {
 public:
  ANGE_Circle(int, int, int, Uint8, Uint8, Uint8, Uint8);
  void draw(SDL_Renderer*) const;

 private:
  int radius_;
  SDL_Point center_;
  SDL_Color color_;
};
