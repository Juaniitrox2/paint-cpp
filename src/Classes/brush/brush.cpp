#include "Classes/tool/tool.hpp"
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"
#include "brush.hpp"

Brush::Brush() {}
Brush::~Brush() {}
Brush::Brush(int size) {
    this->brush_size = size;
}

void Brush::Use(Screen* screen, int pos_x, int pos_y, Color* color) {
    int thickness = this->brush_size;

    int at_x = pos_x - this->brush_size/2;
    int at_y = pos_y - this->brush_size/2;

    screen->setAreaColor(at_x, at_y, thickness, thickness, color);
}