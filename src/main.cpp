#include <iostream> 
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"

int main() {
    Color white(255, 255, 255, 120);
    Screen test_screen(500, 500);
    test_screen.setColor(white);
    test_screen.start();

    return 1;
}