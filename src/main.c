#include <raylib.h>
#include <resource_dir.h>
#include <rcamera.h>

#include "window_init.h"
#include "title_screen.h"
#include "loadage.h"

int main() {
	InitWindow(848, 480, TITLE);
	SetTargetFPS(DEFAULT_FPS);

	Font * Haettenschweiler;
	InitLoadFonts(Haettenschweiler);

	Camera3D camera = {0};
	camera.position = (Vector3){0, 10.0f, 10.0f};
	camera.target = (Vector3){0, 0.0f, 0};
	camera.up = (Vector3){0, 1.0f, 0};
	camera.fovy = 10.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Model model = LoadModel("resources/Earth/earth.obj");
	Vector3 pos = {0, 0, 0};

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			
			BeginMode3D(camera);
				DrawGrid(10, 1.0f);

				DrawModel(model, pos, 1.0f, WHITE);
			EndMode3D();

			DrawTextEx(*Haettenschweiler, "Hey there", (Vector2){24, 24}, 48, 1, ORANGE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}