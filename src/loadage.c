#include <raylib.h>
#include <resource_dir.h>
#include "loadage.h"

Font DokChampa;
Font Haettenschweiler;
void FontsLoadage() {
    DokChampa = LoadFontEx("resources/fonts/dokchampa.ttf", 96, 0, 0);
    Haettenschweiler = LoadFontEx("resources/fonts/HATTEN.TTF", 96, 0, 0);
}