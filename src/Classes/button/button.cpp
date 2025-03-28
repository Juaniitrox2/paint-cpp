#include "button.hpp"
#include "Classes/vector2/vector2.hpp"
#include "Classes/screen/screen.hpp"

using namespace std;
using Callback = void(*)(Screen*, int);

Button::Button() {}
Button::~Button() {}
Button::Button(Vector2 position, Vector2 size) {
    this->position = position;
    this->size = size;
    this->clicked_callback = NULL;
}

bool Button::isPositionInButton(Vector2* position) {
    if (position->x < this->position.x 
        || position->x > this->position.x + this->size.x 
        || position->y < this->position.y 
        || position->y > this->position.y + this->size.y) {
            return false;
        }

    return true;
}

void Button::setCallback(Callback new_callback) {
    clicked_callback = new_callback;
}

void Button::trigger(Screen* screen, int mouse_button) {
    cout << mouse_button << " pressed!" << endl;

    if (clicked_callback && clicked_callback != NULL) {
        clicked_callback(screen, mouse_button);
    }
}