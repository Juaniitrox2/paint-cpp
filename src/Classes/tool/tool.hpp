#pragma once
#include "Classes/window/window.hpp"
#include "Classes/color/color.hpp"
#include "Classes/vector2/vector2.hpp"

class Tool {
    public:
        Tool();
        Tool(int key);
        ~Tool();
        bool IsToolKeyPressed(int key);
        virtual void Use(Window* window, Vector2* position, Color* color);
    private:
        int key;
};