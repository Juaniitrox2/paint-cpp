#include "Classes/tool/tool.hpp"
#include "Classes/window/window.hpp"
#include "Classes/color/color.hpp"
#include "Classes/vector2/vector2.hpp"
#include "brush.hpp"
#include <vector>
#include <cmath>

std::vector<float> generateVertices(float x, float y, float radius, int segments) {
    std::vector<float> array;

    for (int i = 0; i < segments; i++) {
        float theta = 2.00f * M_PI * float(i) / float(segments);
        float vertex_x = radius * cosf(theta);
        float vertex_y = radius * sinf(theta);

        array.push_back(vertex_x);
        array.push_back(vertex_y);
    }

    return array;
}

Brush::Brush() {}
Brush::~Brush() {}
Brush::Brush(int size) {
    this->brush_size = size;
}

void Brush::Use(Window* window, Vector2* position, Color* color) {
    float nx = (position->x / window->width) * 2.0f - 1.0f;
    float ny = (position->y / window->height) * 2.0f - 1.0f;
    
    std::vector<float> vertices = generateVertices(nx, ny, 1.0f, 32);

    //std::cout << "MOUSE AT (" << nx << ";" << ny << ")" << std::endl;
    window->addBufferToRender(vertices);
}