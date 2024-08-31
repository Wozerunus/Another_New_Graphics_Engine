// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#include "../../include/shapes/triangle.h"

ANGE_Triangle::ANGE_Triangle(float x1,
                             float x2,
                             float y1,
                             float y2,
                             float z1,
                             float z2,
                             Uint8 r,
                             Uint8 g,
                             Uint8 b,
                             Uint8 a) {
  verts_ = {
    {SDL_FPoint{x1, x2}, SDL_Color{r, g, b, a}, 0},
    {SDL_FPoint{y1, y2}, SDL_Color{r, g, b, a}, 0},
    {SDL_FPoint{z1, z2}, SDL_Color{r, g, b, a}, 0},
  };
}

void ANGE_Triangle::draw(SDL_Renderer* renderer) const {
  SDL_RenderGeometry(renderer, nullptr, verts_.data(), verts_.size(), nullptr, 0);
}
