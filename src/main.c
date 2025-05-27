#include <raylib.h>
#include <resource_dir.h>
#include <rcamera.h>
#include <raymath.h>
#define R_LIGHTS_IMPLEMENTATION
// #include <rlights.h>

#include "window_init.h"
#include "title_screen.h"
#include "loadage.h"
#include "camera_init.h"
#include "colors.h"

#define GLSL_VERSION 330

int main() {
	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(GetScreenWidth(), GetScreenHeight(), TITLE);
	SetTargetFPS(DEFAULT_FPS);
	FontsLoadage();

	Camera3D camera = {0};
	camera.position = (Vector3){0, 2.5f, 2.5f};
	camera.target = (Vector3){0, 0.0f, 0};
	camera.up = (Vector3){0, 1.0f, 0};
	camera.fovy = DEFAULT_FOVY;
	camera.projection = CAMERA_PERSPECTIVE;

	Shader shader = LoadShader(0, TextFormat(
		"resources/shaders/grayscale.fs", GLSL_VERSION));

	Model model = LoadModel("resources/models/Earth/earth.obj");
	Vector3 pos = {-0.1f, 0, 0};

	for (int i=0; i < model.materialCount; i++) {
		model.materials[i].shader = shader;
	}

	while (!WindowShouldClose()) {
		UpdateCamera(&camera, DEFAULT_MODE);

		BeginDrawing();
			ClearBackground(RAYWHITE);
			
			BeginMode3D(camera);

				BeginShaderMode(shader);
					DrawGrid(10, 1.0f);

					DrawModel(model, pos, 1.0f, WHITE);
				EndShaderMode();
				
			EndMode3D();

			DrawTextEx(Haettenschweiler, "Hey there", (Vector2){24, 24}, 48, 1, MALACHITE);

		EndDrawing();
	}

	UnloadModel(model);
	UnloadShader(shader);
	CloseWindow();

	return 0;
}