#pragma once
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"

class Tool {
    public:
        Tool();
        Tool(int key);
        ~Tool();
        bool IsToolKeyPressed(int key);
        virtual void Use(Screen* screen,int pos_X,int pos_y, Color* color);
    private:
        int key;
};