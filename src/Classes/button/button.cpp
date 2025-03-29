#include "button.hpp"
#include "Classes/vector2/vector2.hpp"
#include "Classes/screen/screen.hpp"
#include "Classes/uicomponent/uicomponent.hpp"

using namespace std;
using Callback = void(*)(Screen*, int);

Button::Button() : UIComponent() {}
Button::~Button() {}
Button::Button(Vector2 position, Vector2 size) : UIComponent(position, size) {
    this->held_state = false;
    this->clicked_state = false;
    this->clicked_callback = NULL;
}

void Button::setCallback(Callback new_callback) {
    clicked_callback = new_callback;
}

void Button::enter() {
    this->held_state = true;
}

void Button::leave() {
    this->held_state = false;
    this->release();
}

void Button::trigger(Screen* screen, int mouse_button) {
    if (!screen) return;

    cout << mouse_button << " pressed!" << endl;

    if (clicked_callback && clicked_callback != NULL && !this->clicked_state) {
        this->clicked_state = true;
        clicked_callback(screen, mouse_button);
    }
}

void Button::release() {
    if (this->clicked_state == true) {
        this->clicked_state = false;
    }
}