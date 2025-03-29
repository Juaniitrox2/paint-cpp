#pragma once
#include "Classes/vector2/vector2.hpp"
#include "Classes/screen/screen.hpp"
#include <vector>
using namespace std;

/**
* Base class from which the rest of the UI components extend
* - Contains a size and a position vector for the rect on screen, can include children of the same root
*/
class UIComponent {
    public:
        Vector2 size;
        Vector2 position;

        // Empty constructor
        UIComponent();

        /// @brief Create a UIComponent rect at stablished position with stablished size
        /// @param position (in PX) the location of the rect's top left corner
        /// @param size (in PX) the extension of the rect from the position, right and down
        UIComponent(Vector2 position, Vector2 size);
        ~UIComponent();

        /// @brief Check whether or not the given position is inside the components rect
        /// @param position 
        /// @return whether or not the position is inside the UIComponent 
        bool isPositionInRect(Vector2* position);

        /// @brief Add a child component to the parent UIComponent, last component is the one on top of the rest in layers
        /// @param child
        void addComponent(UIComponent* child);
        
        /// @brief Update the ui components design 
        /// @param screen 
        void update(Screen* screen);
    private:
        vector<UIComponent*> children_instances;
};