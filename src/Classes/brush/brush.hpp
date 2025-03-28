#include "Classes/tool/tool.hpp"
#include "Classes/window/window.hpp"
#include "Classes/color/color.hpp"

class Brush : public Tool {

    public:

    Brush();
    Brush(int size);
    ~Brush();
    void Use(Window* window, int pos_x, int pos_y, Color* color) override;

    private:
    int brush_size;
};