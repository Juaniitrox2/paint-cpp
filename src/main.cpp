#include <iostream> 
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"
#include <glad.h>
#include <GLFW/glfw3.h>

int main() {
    
    Color* grey = new Color(0, 0, 0, 120);
    Screen test_screen(500, 500);

    test_screen.start();

    return 0;
}