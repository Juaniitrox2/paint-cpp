#include <iostream> 
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"

int main() {
    Color* white = new Color(255, 255, 255, 120);
    Color* red = new Color(255, 0, 0, 0);
    Screen test_screen(1000, 1000);
    //test_screen.setColor(white);

    test_screen.setAreaColor(0, 100, 250, 250, white);
    test_screen.setAreaColor(0, 95, 100, 100, red);

    test_screen.start();

    return 1;
}