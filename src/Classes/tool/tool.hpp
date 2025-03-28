#pragma once
#include "Classes/window/window.hpp"
#include "Classes/color/color.hpp"

class Tool {
    public:
        Tool();
        Tool(int key);
        ~Tool();
        bool IsToolKeyPressed(int key);
        virtual void Use(Window* window, int pos_X, int pos_y, Color* color);
    private:
        int key;
};