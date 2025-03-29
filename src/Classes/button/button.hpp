#pragma once
#include <iostream>
#include "Classes/vector2/vector2.hpp"
#include "Classes/screen/screen.hpp"
#include "Classes/uicomponent/uicomponent.hpp"

class Button : public UIComponent {
    public:
        using Callback = void(*)(Screen*, int);

        bool clicked_state;
        bool held_state;

        // Methods
        Button();
        Button(Vector2 position, Vector2 size);
        ~Button();

        void setCallback(Callback new_callback);

        /// @brief Meant to be internally called, button was pressed
        void trigger(Screen* screen, int mouse_button);

        /// @brief Meant to be internally called, button was released
        void release();

        /// @brief Meant to be internally called, marks the entrance of the mouse in the button
        void enter();
        /// @brief Meant to be internally called, marks the leave of the mouse in the button
        void leave();

    private:
        Callback clicked_callback;
};