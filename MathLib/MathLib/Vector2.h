#pragma once

#include <string>

class Vector2
{
public:
	//Constructors
	Vector2(float _x, float _y):x(_x),y(_y){}

	// Variables
	float x, y;
	float magnitude() const;
	Vector2 normalized() const;
	float sqrMagnitude() const;

	//public functions
	void normalize();
	void set(float _x, float _y);
	std::string toString();

	//static functions
	static float angle(const Vector2& from, const Vector2& to);
	static Vector2 clampMagnitude(const Vector2& v,float maxLength);
	static float distance(const Vector2& a, const Vector2& b);
	static float dot(const Vector2& a, const Vector2& b);
	static Vector2 lerp(const Vector2& a, const Vector2& b, float t);
	static Vector2 lerpUnclamped(const Vector2& a, const Vector2& b, float t);

	//static variables
	static Vector2 down;
	static Vector2 left;
	static Vector2 one;
	static Vector2 right;
	static Vector2 up;
	static Vector2 zero;
};

