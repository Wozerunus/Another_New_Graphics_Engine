// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#include "../../include/shapes/rectangle.h"

ANGE_Rectangle::ANGE_Rectangle(int x,
                               int y,
                               int w,
                               int h,
                               Uint8 r,
                               Uint8 g,
                               Uint8 b,
                               Uint8 a) {
  rect_ = {x, y, w, h};
  color_ = {r, g, b, a};
}

void ANGE_Rectangle::draw(SDL_Renderer* renderer) const {
  SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
  SDL_RenderFillRect(renderer, &rect_);
}
