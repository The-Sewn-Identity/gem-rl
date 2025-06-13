#include <stdlib.h>
#include <raylib.h>
#include "model.h"

void SetShader(Model model, Shader shader) {
    for (int i=0; i < model.materialCount; i++) {
        model.materials[i].shader = shader;
    }
}

ModelDef CreateModel(char * name, Shader shader, Vector3 pos, char * format) {
    Model model_ = LoadModel(TextFormat("%s%s%s", "resources/models/Castle/", name, format));
    Shader shader_ = shader;
    Vector3 pos_ = pos;

    SetShader(model_, shader_);
    ModelDef *retable = (ModelDef*)malloc(sizeof(ModelDef));

    return (ModelDef){model_, pos_, &DrawModel};
}