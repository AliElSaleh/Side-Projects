/*
 * MIT License
 *
 *	Copyright (c) 2019 Ali El Saleh
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

#include <raylib.h>
#include <cmath>

void Init();
void Update();
void Draw();

float Angle = 0.0f;
float Radius = 10;

int main()
{
	Init();

	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}

	CloseWindow();
}

void Init()
{
	const unsigned short ScreenWidth = 800;
	const unsigned short ScreenHeight = 450;

	InitWindow(ScreenWidth, ScreenHeight, "Heart Curve");

	SetTargetFPS(120);
}

void Update()
{
	SetWindowTitle(FormatText("Heart Curve | FPS: %i", GetFPS()));
}

void Draw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	// Heart drawing
	for (; Angle < PI*PI; Angle += 0.01f)
	{	
		// Shape 6
		const float x = Radius * 16 * powf(sinf(Angle), 3);
		const float y = -Radius * (13 * cosf(Angle) - 5*cosf(2*Angle) - 2*cosf(3*Angle) - cosf(4*Angle));
		DrawPixel(GetScreenWidth()/2+int(x), GetScreenHeight()/2+int(y), WHITE);
	}

	Angle = 0.0f;

	EndDrawing();
}
