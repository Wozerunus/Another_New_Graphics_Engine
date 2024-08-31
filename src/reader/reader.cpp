// Copyright 2024 Vadim Chernyshov (aka Wozerunus)
#include "../../include/reader/reader.h"

void ANGE_Reader::readScene(const char* path,
                            std::vector<ANGE_Rectangle>& rectangles,
                            std::vector<ANGE_Triangle>& triangles,
                            std::vector<ANGE_Circle>& circles,
                            std::vector<ANGE_Image>& images,
                            std::vector<ANGE_Text>& texts) {
  int rectangle_x, rectangle_y, rectangle_w, rectangle_h,
    triangle_x1, triangle_x2, triangle_y1,
      triangle_y2, triangle_z1, triangle_z2,
    circle_x, circle_y, circle_radius,
    image_x, image_y, image_w, image_h,
    text_x, text_y, text_size, c_count,
    r, g, b, a;

  rectangle_x = rectangle_y = rectangle_w = rectangle_h = 0;
  triangle_x1 = triangle_x2 = triangle_y1 =
    triangle_y2 = triangle_z1 = triangle_z2 = 0;
  circle_x = circle_y = circle_radius = 0;
  image_x = image_y = image_w = image_h = 0;
  text_x = text_y = text_size = c_count = 0;
  r = g = b = a = 0;

  char image_path[64] = "", text_font[64] = "";
  wchar_t text_msg[64] = L"";
  std::wstring ws;

  std::locale::global(std::locale("Russian_Russia"));
  std::ifstream in(path, std::ios::binary);

  int id = -1;
  while (id != 0) {
    in.read(reinterpret_cast<char*>(&id), sizeof(id));
    switch (id) {
      case 1:
        in.read(reinterpret_cast<char*>(&rectangle_x), sizeof(rectangle_x));
        in.read(reinterpret_cast<char*>(&rectangle_y), sizeof(rectangle_y));
        in.read(reinterpret_cast<char*>(&rectangle_w), sizeof(rectangle_w));
        in.read(reinterpret_cast<char*>(&rectangle_h), sizeof(rectangle_h));
        in.read(reinterpret_cast<char*>(&r),      sizeof(r));
        in.read(reinterpret_cast<char*>(&g),      sizeof(g));
        in.read(reinterpret_cast<char*>(&b),      sizeof(b));
        in.read(reinterpret_cast<char*>(&a),      sizeof(a));
        rectangles.push_back({rectangle_x,
                              rectangle_y,
                              rectangle_w,
                              rectangle_h,
                              static_cast<Uint8>(r),
                              static_cast<Uint8>(g),
                              static_cast<Uint8>(b),
                              static_cast<Uint8>(a)});
        break;
      case 2:
        in.read(reinterpret_cast<char*>(&triangle_x1), sizeof(triangle_x1));
        in.read(reinterpret_cast<char*>(&triangle_x2), sizeof(triangle_x2));
        in.read(reinterpret_cast<char*>(&triangle_y1), sizeof(triangle_y1));
        in.read(reinterpret_cast<char*>(&triangle_y2), sizeof(triangle_y2));
        in.read(reinterpret_cast<char*>(&triangle_z1), sizeof(triangle_z1));
        in.read(reinterpret_cast<char*>(&triangle_z2), sizeof(triangle_z2));
        in.read(reinterpret_cast<char*>(&r),     sizeof(r));
        in.read(reinterpret_cast<char*>(&g),     sizeof(g));
        in.read(reinterpret_cast<char*>(&b),     sizeof(b));
        in.read(reinterpret_cast<char*>(&a),     sizeof(a));
        triangles.push_back({static_cast<float>(triangle_x1),
                             static_cast<float>(triangle_x2),
                             static_cast<float>(triangle_y1),
                             static_cast<float>(triangle_y2),
                             static_cast<float>(triangle_z1),
                             static_cast<float>(triangle_z2),
                             static_cast<Uint8>(r),
                             static_cast<Uint8>(g),
                             static_cast<Uint8>(b),
                             static_cast<Uint8>(a)});
        break;
      case 3:
        in.read(reinterpret_cast<char*>(&circle_x),   sizeof(circle_x));
        in.read(reinterpret_cast<char*>(&circle_y),   sizeof(circle_y));
        in.read(reinterpret_cast<char*>(&circle_radius), sizeof(circle_radius));
        in.read(reinterpret_cast<char*>(&r),     sizeof(r));
        in.read(reinterpret_cast<char*>(&g),     sizeof(g));
        in.read(reinterpret_cast<char*>(&b),     sizeof(b));
        in.read(reinterpret_cast<char*>(&a),     sizeof(a));
        circles.push_back({circle_x,
                           circle_y,
                           circle_radius,
                           static_cast<Uint8>(r),
                           static_cast<Uint8>(g),
                           static_cast<Uint8>(b),
                           static_cast<Uint8>(a)});
        break;
      case 4:
        in.read(reinterpret_cast<char*>(&image_x),    sizeof(image_x));
        in.read(reinterpret_cast<char*>(&image_y),    sizeof(image_y));
        in.read(reinterpret_cast<char*>(&image_w),    sizeof(image_w));
        in.read(reinterpret_cast<char*>(&image_h),    sizeof(image_h));
        in.read(reinterpret_cast<char*>(&image_path), 64);
        images.push_back({image_x,
                          image_y,
                          image_w,
                          image_h,
                          image_path});
        break;
      case 5:
        in.read(reinterpret_cast<char*>(&text_x),     sizeof(text_x));
        in.read(reinterpret_cast<char*>(&text_y),     sizeof(text_y));
        in.read(reinterpret_cast<char*>(&c_count), sizeof(c_count));
        in.read(reinterpret_cast<char*>(&text_msg),   64);
        in.read(reinterpret_cast<char*>(&text_font),  64);
        in.read(reinterpret_cast<char*>(&text_size),  sizeof(text_size));
        in.read(reinterpret_cast<char*>(&r),       sizeof(r));
        in.read(reinterpret_cast<char*>(&g),       sizeof(g));
        in.read(reinterpret_cast<char*>(&b),       sizeof(b));
        in.read(reinterpret_cast<char*>(&a),       sizeof(a));
        for (size_t i = 0; i < c_count; i++) {
          ws.push_back(text_msg[i]);
        }
        texts.push_back({text_x,
                         text_y,
                         ws,
                         text_font,
                         text_size,
                         static_cast<Uint8>(r),
                         static_cast<Uint8>(g),
                         static_cast<Uint8>(b),
                         static_cast<Uint8>(a)});
        ws.clear();
        break;
      default:
        break;
    }
  }
  in.close();
}
