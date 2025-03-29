#include "uicomponent.hpp"
#include "Classes/color/color.hpp"
#include <vector>
using namespace std;

// Basic constructors
UIComponent::UIComponent() {}
UIComponent::~UIComponent() {}
UIComponent::UIComponent(Vector2 position, Vector2 size) {
    this->position = position;
    this->size = size;
}

void UIComponent::addComponent(UIComponent* child) {
    this->children_instances.push_back(child);
}

void UIComponent::update(Screen* screen) {
    Color* red = new Color(255, 0, 0, 0);

    screen->getFocusedWindow()->setAreaColor(this->position.x, this->position.y, this->size.x, this->size.y, red);
}

bool UIComponent::isPositionInRect(Vector2* position) {
    if (position->x < this->position.x 
        || position->x > this->position.x + this->size.x 
        || position->y < this->position.y 
        || position->y > this->position.y + this->size.y) {
            return false;
        }

    return true;
}
