#include "Classes/tool/tool.hpp"
#include "Classes/window/window.hpp"
#include "Classes/color/color.hpp"
#include "Classes/vector2/vector2.hpp"
#include "brush.hpp"

Brush::Brush() {}
Brush::~Brush() {}
Brush::Brush(int size) {
    this->brush_size = size;
}

void Brush::Use(Window* window, Vector2* position, Color* color) {
    int thickness = this->brush_size;

    int at_x = static_cast<int>(position->x) - this->brush_size/2;
    int at_y = static_cast<int>(position->y) - this->brush_size/2;

    window->setAreaColor(at_x, at_y, thickness, thickness, color);
}