#include <raylib.h>
#include <resource_dir.h>
#include <rcamera.h>

#include "window_init.h"

int main() {
	InitWindow(848, 480, TITLE);
	SetTargetFPS(DEFAULT_FPS);

	Camera3D camera = {0};
	camera.position = (Vector3){0, 10.0f, 10.0f};
	camera.target = (Vector3){0, 0.0f, 0};
	camera.up = (Vector3){0, 1.0f, 0};
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			
			BeginMode3D(camera);
				DrawGrid(10, 1.0f);
			EndMode3D();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}