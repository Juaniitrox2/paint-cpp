#include "Classes/tool/tool.hpp"
#include "Classes/window/window.hpp"
#include "Classes/color/color.hpp"
#include "Classes/vector2/vector2.hpp"

class Brush : public Tool {

    public:

    Brush();
    Brush(int size);
    ~Brush();
    void Use(Window* window, Vector2* position, Color* color) override;

    private:
    int brush_size;
};