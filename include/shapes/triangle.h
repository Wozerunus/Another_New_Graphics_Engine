// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#pragma once
#include <vector>
#include <SDL.h>

class ANGE_Triangle {
 public:
  ANGE_Triangle(float, float, float, float, float, float, Uint8, Uint8, Uint8, Uint8);
  void draw(SDL_Renderer*) const;

 private:
  std::vector<SDL_Vertex> verts_;
};
