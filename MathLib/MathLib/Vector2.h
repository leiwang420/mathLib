#pragma once

#include <string>

#include "Vector3.h"

class Vector2
{
public:
	//Constructors
	Vector2() :x(0), y(0){}
	Vector2(float _x, float _y):x(_x),y(_y){}
	Vector2(const Vector2& v) :x(v.x), y(v.y){}
	Vector2(const Vector3& v) :x(v.x), y(v.y){}
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
	static Vector2 max(const Vector2& a, const Vector2& b);
	static Vector2 min(const Vector2& a, const Vector2& b);
	static Vector2 moveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta);
	static Vector2 Reflect(const Vector2& inDir, const Vector2& inNormal);
	static Vector2 Scale(const Vector2& a, const Vector2& b);
	static Vector2 SmoothDamp(const Vector2& current, const Vector2& target, Vector2& currentVelocity, 
		float smoothTime, float maxSpeed, float deltaTime);

	//operators
	Vector2 operator-(const Vector2& rhl) const;
	Vector2 operator+(const Vector2& rhl) const;
	Vector2 operator*(float d) const;
	Vector2 operator/(float d) const;
	bool operator==(const Vector2& rhl) const ;
	bool operator!=(const Vector2& rhl) const;

	//static variables
	static Vector2 down;
	static Vector2 left;
	static Vector2 one;
	static Vector2 right;
	static Vector2 up;
	static Vector2 zero;
};

Vector2 operator*(float d, const Vector2& rhl);

