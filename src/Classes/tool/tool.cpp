#include "tool.hpp"

Tool::Tool (){};
Tool::Tool (int key){
    this->key = key;
}
Tool::~Tool (){};

bool Tool::IsToolKeyPressed(int key){
    return this->key == key;
};

void Tool::Use(Screen* screen,int pos_X,int pos_y, Color* color){
    std::cout << "el original we " << std::endl;
};