#include "Classes/tool/tool.hpp"
#include "Classes/screen/screen.hpp"
#include "Classes/color/color.hpp"

class Brush : public Tool {

    public:

    Brush();
    Brush(int size);
    ~Brush();
    void Use(Screen* screen, int pos_x, int pos_y, Color* color) override;

    private:
    int brush_size;
};