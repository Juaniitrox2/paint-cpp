#include "tool.hpp"
#include "Classes/vector2/vector2.hpp"

Tool::Tool (){};
Tool::Tool (int key){
    this->key = key;
}
Tool::~Tool (){};

bool Tool::IsToolKeyPressed(int key){
    return this->key == key;
};

void Tool::Use(Window* window, Vector2* position, Color* color){
    std::cout << "no implementation for tool " << std::endl;
};