// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <Windows.h>
#include <comdef.h>

#include <iostream>
#include <vector>
#include <string>

#include "../ANGE/include/reader/reader.h"

const int LAUNCH_WINDOW_WIDTH = 800;
const int LAUNCH_WINDOW_HEIGHT = 800;
const char* LAUNCH_WINDOW_NAME = "Plant Nursery";

int main(int argc, char* argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
     SDL_Quit();
  } else if (TTF_Init() == -1) {
     SDL_Quit();
  } else if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
     SDL_Quit();
  } else if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) {
     SDL_Quit();
  }

  auto window = SDL_CreateWindow(
    LAUNCH_WINDOW_NAME,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    LAUNCH_WINDOW_WIDTH,
    LAUNCH_WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC
  );

  auto renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  std::vector<ANGE_Rectangle> rectangles;
  std::vector<ANGE_Triangle> triangles;
  std::vector<ANGE_Circle> circles;
  std::vector<ANGE_Image> images;
  std::vector<ANGE_Text> texts;

  ANGE_Reader::readScene(
    "data/start.sc",
    rectangles,
    triangles,
    circles,
    images,
    texts
  );


  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
        case SDL_QUIT:
          quit = true;
          break;
        case SDL_KEYDOWN:
          switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
              quit = true;
              break;
            default:
              break;
          }
          break;
        default:
          break;
      }
    }

    for (auto iter{rectangles.begin()}; iter != rectangles.end(); ++iter) {
      (*iter).draw(renderer);
    }
    for (auto iter{triangles.begin()}; iter != triangles.end(); ++iter) {
      (*iter).draw(renderer);
    }
    for (auto iter{circles.begin()}; iter != circles.end(); ++iter) {
      (*iter).draw(renderer);
    }
    for (auto iter{images.begin()}; iter != images.end(); ++iter) {
      (*iter).draw(renderer);
    }
    for (auto iter{texts.begin()}; iter != texts.end(); ++iter) {
      (*iter).draw(renderer);
    }

    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  return EXIT_SUCCESS;
}
