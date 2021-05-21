
#pragma once

#define PI 3.14159265359

struct Vec2 {
	float X;
	float Y;
};

struct Vec3 {
	float X;
	float Y;
	float Z;
};

struct Vec3i {
	u32 X;
	u32 Y;
	u32 Z;
};

struct Rect {
	float left;
	float bottom;
	float right;
	float top;
};


typedef float Mtx[3][4];
