#ifndef MODEL_H
#define MODEL_H

#define GLB ".glb"

typedef struct ModelDef {
    Model model;
    Vector3 position;
    void (*draw)(Model, Vector3, float, Color);
} ModelDef;

ModelDef CreateModel(char * name, Shader shader, Vector3 pos, char * format);

#endif