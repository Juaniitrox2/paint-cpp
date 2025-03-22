#include "tasks.hpp"
#include "glad.h"
#include "Classes/screen/screen.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Classes/color/color.hpp"
#include "Classes/brush/brush.hpp"


Tasks::Tasks() {}
Tasks::Tasks(Screen* screen){
    this->active_tool = new Brush(4);
    this->active_screen = screen;
}

void Tasks::start() {
    this->connectEvents();
}

// CURRENT ACTIVE TASK MANAGER
Tasks* getActiveTaskManager(GLFWwindow* window) {
    return static_cast<Tasks*>(glfwGetWindowUserPointer(window));
}

void Tasks::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    Tasks* tasks = getActiveTaskManager(window);
    int mouse_button_state = glfwGetMouseButton(window, 0);
    int eraser_active = glfwGetMouseButton(window, 1);

    if (tasks && tasks->active_screen && (mouse_button_state == 1 || eraser_active == 1)) {
        Color* red = new Color(255, 255, 0, 0);
        Color* nig = new Color(0, 0, 0, 0);

        Color* chosen_color = red;
        if (eraser_active == 1) {
            chosen_color = nig;
        }
        
        int pos_x = static_cast<int>(xpos);
        int pos_y = static_cast<int>(ypos);

        tasks->active_tool->Use(tasks->active_screen, pos_x, pos_y, chosen_color);
        //std::cout << "X:  " << xpos << " Y: " << ypos << std::endl;
        //tasks->active_screen->setAreaColor(static_cast<int>(xpos) - 2, static_cast<int>(ypos) - 2, 4, 4, chosen_color);
    }
}

void Tasks::connectEvents() {
    if (active_screen && active_screen->window) {
        glfwSetWindowUserPointer(active_screen->window, this);
        glfwSetCursorPosCallback(active_screen->window, Tasks::cursor_position_callback);
    }
}

Tasks::~Tasks() {}