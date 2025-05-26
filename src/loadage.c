#include <raylib.h>
#include <resource_dir.h>
#include "loadage.h"

Font Haettenschweiler;
void FontsLoadage() {
    Haettenschweiler = LoadFontEx("resources/fonts/HATTEN.TTF", 96, 0, 0);
}