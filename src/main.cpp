#include <iostream> 
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"

int main() {
    Color* grey = new Color(0, 0, 0, 120);
    Screen test_screen(500, 500);
    //test_screen.setColor(white);

    test_screen.setAreaColor(0, 0, 499, 499, grey);

    test_screen.start();

    return 0;
}