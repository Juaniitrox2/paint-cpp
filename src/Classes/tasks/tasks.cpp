#include "tasks.hpp"
#include "glad.h"
#include "Classes/screen/screen.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Classes/color/color.hpp"
#include "Classes/brush/brush.hpp"
#include "Classes/vector2/vector2.hpp"
#include "Classes/button/button.hpp"

using namespace std;

Tasks::Tasks() {}
Tasks::Tasks(Screen* screen){
    this->active_tool = new Brush(8);
    this->active_screen = screen;

    Vector2 button_pos(15, 15);
    Vector2 button_size(50, 50);
    this->button = new Button(button_pos, button_size);

    this->button->setCallback([](Screen* screen, int mouse_button) {
        screen->newWindow(150, 150, "Whatsapp");
    });
}

void Tasks::start() {
    this->connectEvents();
}

// CURRENT ACTIVE TASK MANAGER
Tasks* getActiveTaskManager(GLFWwindow* window) {
    return static_cast<Tasks*>(glfwGetWindowUserPointer(window));
}

void Tasks::update(Screen* screen) {
    this->button->update(screen);
}

void Tasks::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    Tasks* tasks = getActiveTaskManager(window);

    Vector2* mouse_position = new Vector2(xpos, ypos);
    int mouse_button_state = glfwGetMouseButton(window, 0);
    int eraser_active = glfwGetMouseButton(window, 1);
    
    if (tasks->button && tasks->button->isPositionInRect(mouse_position)) {
        if (mouse_button_state == 1) {
            tasks->button->trigger(tasks->active_screen, 1);
        } else if (mouse_button_state == 0) {
            tasks->button->release();
        }
    }

    if (tasks && tasks->active_screen && (mouse_button_state == 1 || eraser_active == 1)) {
        Color* red = new Color(255, 255, 0, 0);
        Color* dark = new Color(0, 0, 0, 0);

        Color* chosen_color = red;
        if (eraser_active == 1) {
            chosen_color = dark;
        }
        
        int pos_x = static_cast<int>(xpos);
        int pos_y = static_cast<int>(ypos);

        Window* screen_window = tasks->active_screen->getWindowFromGL(window);

        //screen_window->setAreaColor(pos_x, pos_y, 4, 4, chosen_color);
        tasks->active_tool->Use(screen_window, mouse_position, chosen_color);
        //std::cout << "X:  " << xpos << " Y: " << ypos << std::endl;
        //tasks->active_screen->setAreaColor(static_cast<int>(xpos) - 2, static_cast<int>(ypos) - 2, 4, 4, chosen_color);
    }

    tasks->update(tasks->active_screen);
}

void Tasks::connectEvents() {
    if (active_screen && active_screen->getFocusedWindow()) {
        Window* focused_window = active_screen->getFocusedWindow();


        // std::cout << "FIX POINTERS" << std::endl;
        glfwSetWindowUserPointer(focused_window->getGLWindow(), this);
        glfwSetCursorPosCallback(focused_window->getGLWindow(), Tasks::cursor_position_callback);
    }
}

Tasks::~Tasks() {}