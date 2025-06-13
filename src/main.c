#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <resource_dir.h>
#include <rcamera.h>
#include <raymath.h>
#define R_LIGHTS_IMPLEMENTATION
// #include <rlights.h>

#include "window_init.h"
#include "title_screen.h"
#include "loadage.h"
#include "model.h"
#include "camera_init.h"
#include "colors.h"
#include "speech.h"
#include "savegame.h"

int main() {
	// srand(time(NULL));
	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(GetScreenWidth(), GetScreenHeight(), TITLE);
	SetTargetFPS(DEFAULT_FPS);
	FontsLoadage();

	Font mainFont = Haettenschweiler;
	char *screentext = ChooseDefaultDialogue();

	Camera3D camera = {0};
	camera.position = (Vector3){0, 2.5f, 2.5f};
	camera.target = (Vector3){0, 0.0f, 0};
	camera.up = (Vector3){0, 1.0f, 0};
	camera.fovy = DEFAULT_FOVY;
	camera.projection = CAMERA_PERSPECTIVE;

	Shader shader = LoadShader(0, TextFormat(
		"resources/shaders/bloom.fs", GLSL_VERSION));

	ModelDef crustle = CreateModel("nowhere", shader, (Vector3){0.0f, 0.0f, 0.0f}, GLB);
	unsigned int siz = sizeof(SaveGame);

	while (!WindowShouldClose()) {
		UpdateCamera(&camera, DEFAULT_MODE);

		if (IsKeyPressed(KEY_R)) mainFont = DokChampa;
		if (IsKeyPressed(KEY_T)) screentext = ChooseDefaultDialogue();

		BeginDrawing();
			ClearBackground(MALACHITE);
			
			BeginMode3D(camera);

				BeginShaderMode(shader);
					DrawGrid(10, 1.0f);

					crustle.draw(crustle.model, crustle.position, 1.0f, WHITE);
				EndShaderMode();
				
			EndMode3D();

			DrawTextEx(mainFont, TextFormat("%u", siz), (Vector2){24, 24}, 48, 1, VERMILION);

		EndDrawing();
	}

	UnloadModel(crustle.model);
	UnloadShader(shader);
	CloseWindow();

	return 0;
}