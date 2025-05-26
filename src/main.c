#include <raylib.h>
#include <resource_dir.h>
#include <rcamera.h>

#include "window_init.h"
#include "title_screen.h"
#include "loadage.h"
#include "camera_init.h"
#include "colors.h"

int main() {
	InitWindow(GetScreenWidth(), GetScreenHeight(), TITLE);
	SetTargetFPS(DEFAULT_FPS);
	FontsLoadage();

	Camera3D camera = {0};
	camera.position = (Vector3){0, 5.0f, 10.0f};
	camera.target = (Vector3){0, 0.0f, 0};
	camera.up = (Vector3){0, 1.0f, 0};
	camera.fovy = DEFAULT_FOVY;
	camera.projection = CAMERA_PERSPECTIVE;

	Model model = LoadModel("resources/models/Earth/earth.obj");
	Vector3 pos = {-0.1f, 0, 0};

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			
			BeginMode3D(camera);
				DrawGrid(10, 1.0f);

				DrawModel(model, pos, 1.0f, WHITE);
			EndMode3D();

			DrawTextEx(Haettenschweiler, "Hey there", (Vector2){24, 24}, 48, 1, MALACHITE);

		EndDrawing();
	}

	UnloadModel(model);
	CloseWindow();

	return 0;
}