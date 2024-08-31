// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#include "../../include/shapes/circle.h"

ANGE_Circle::ANGE_Circle(int x,
                         int y,
                         int radius,
                         Uint8 r,
                         Uint8 g,
                         Uint8 b,
                         Uint8 a)
: radius_(radius) {
  center_ = {x, y};
  color_ = {r, g, b, a};
}

void ANGE_Circle::draw(SDL_Renderer* renderer) const {
  SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);

  for (int x = center_.x - radius_; x <= center_.x + radius_; x++) {
    for (int y = center_.y - radius_; y <= center_.y + radius_; y++) {
      if ((x - center_.x) * (x - center_.x) +
           (y - center_.y) * (y - center_.y) <= radius_ * radius_) {
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
  }
}
