#include <raylib.h>
#include <resource_dir.h>

int main() {
	InitWindow(848, 480, "raylib Window");
	SetTargetFPS(120);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(WHITE);

		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}