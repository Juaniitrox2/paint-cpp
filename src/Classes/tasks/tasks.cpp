#include "tasks.hpp"
#include "glad.h"
#include "Classes/screen/screen.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Classes/color/color.hpp"

Tasks::Tasks() {}
Tasks::Tasks(Screen* screen){
    this->active_screen = screen;
}

void Tasks::start() {
    this->connectEvents();
}


void Tasks::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    Color* red = new Color(255, 0, 0, 0);

    std::cout << "X:  " << xpos << " Y: " << ypos << std::endl;
    //this.active_screen.setPixelColor(int(xpos), int(ypos), red);
}

void Tasks::connectEvents() {
    glfwSetCursorPosCallback(this->active_screen->window , this->cursor_position_callback);
}

Tasks::~Tasks() {}