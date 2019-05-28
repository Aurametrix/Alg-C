#include "msdfgen.h"
#include "msdfgen-ext.h"

using namespace msdfgen;

int main() {
    FreetypeHandle *ft = initializeFreetype();
    if (ft) {
        FontHandle *font = loadFont(ft, "C:\\Windows\\Fonts\\arialbd.ttf");
        if (font) {
            Shape shape;
            if (loadGlyph(shape, font, 'A')) {
                shape.normalize();
                //                      max. angle
                edgeColoringSimple(shape, 3.0);
                //           image width, height
                Bitmap<FloatRGB> msdf(32, 32);
                //                     range, scale, translation
                generateMSDF(msdf, shape, 4.0, 1.0, Vector2(4.0, 4.0));
                savePng(msdf, "output.png");
            }
            destroyFont(font);
        }
        deinitializeFreetype(ft);
    }
    return 0;
}
