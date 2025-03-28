#pragma once
#include <iostream>
#include "Classes/vector2/vector2.hpp"
#include "Classes/screen/screen.hpp"

class Button {
    public:
        using Callback = void(*)(Screen*, int);

        Vector2 size;
        Vector2 position;

        bool held;

        // Methods
        Button();
        Button(Vector2 position, Vector2 size);
        ~Button();

        bool isPositionInButton(Vector2* position);
        void setCallback(Callback new_callback);
        void trigger(Screen* screen, int mouse_button);

    private:
        Callback clicked_callback;
};