// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "../../include/shapes/rectangle.h"
#include "../../include/shapes/triangle.h"
#include "../../include/shapes/circle.h"
#include "../../include/images/image.h"
#include "../../include/text/text.h"

class ANGE_Reader {
 public:
  ANGE_Reader() {}
  static void readScene(const char*, 
                         std::vector<ANGE_Rectangle>&, 
                         std::vector<ANGE_Triangle>&,
                         std::vector<ANGE_Circle>&, 
                         std::vector<ANGE_Image>&,
                         std::vector<ANGE_Text>&);
};
