// Copyright 2024 Vadim Chernyshov
#include "../../include/text/text.h"

ANGE_Text::ANGE_Text(int x,
                     int y,
                     std::wstring message,
                     std::string font_name,
                     int size,
                     Uint8 r,
                     Uint8 g,
                     Uint8 b,
                     Uint8 a)
  : x_(x),
    y_(y),
    message_(message),
    font_(TTF_OpenFont(std::string("fonts/" + font_name + ".ttf").c_str(), size_)),
    size_(size),
    surface_(TTF_RenderUNICODE_Blended(font_, (const Uint16*)message_.c_str(), {r, g, b, a}))
{}

void ANGE_Text::draw(SDL_Renderer* renderer) {
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface_);
  int texW = 0, texH = 0;

  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

  SDL_Rect dstrect = {x_, y_, texW, texH};

  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_DestroyTexture(texture);
}
