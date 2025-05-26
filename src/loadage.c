#include <raylib.h>
#include <resource_dir.h>
#include "loadage.h"

void InitLoadFonts(Font * hat) {
    *hat = LoadFontEx("fonts/HATTEN.ttf", 96, 0, 0);
}