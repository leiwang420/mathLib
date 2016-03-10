#pragma once

#include <string>
#include <iostream>

#include "Mathf.h"
#include "MTime.h"


class Vector3;
class Vector4;

class Vector2
{
public:
	//Constructors
	Vector2() :x(0), y(0){}
	Vector2(float _x, float _y):x(_x),y(_y){}
	Vector2(const Vector2& v) :x(v.x), y(v.y){}
	Vector2(const Vector3& v);
	Vector2(const Vector4& v);
	// Variables
	union
	{
		struct{
			float x, y;
		};

		float v[2];
	};

	float magnitude() const;
	Vector2 normalized() const;
	float sqrMagnitude() const;
	float operator[](int index) const { return v[index]; }

	//public functions
	void normalize();
	void set(float _x, float _y);
	std::string toString() const;

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
	static Vector2 reflect(const Vector2& inDir, const Vector2& inNormal);
	static Vector2 scale(const Vector2& a, const Vector2& b);
	static Vector2 smoothDamp(const Vector2& current, const Vector2& target, Vector2& currentVelocity, 
		float smoothTime, float maxSpeed = Mathf::Infinity, float deltaTime=Time::defaultDeltaTime);

	//返回a在normal上的投影
	static Vector2 projectToNormal(const Vector2& a, const Vector2& normal);

	//operators
	Vector2 operator-(const Vector2& rhl) const;
	Vector2 operator+(const Vector2& rhl) const;
	Vector2 operator*(float d) const;
	Vector2 operator/(float d) const;
	bool operator==(const Vector2& rhl) const ;
	bool operator!=(const Vector2& rhl) const;

	//static variables
	static const Vector2 Down;
	static const Vector2 Left;
	static const Vector2 One;
	static const Vector2 Right;
	static const Vector2 Up;
	static const Vector2 Zero;
};

Vector2 operator*(float d, const Vector2& rhl);

std::ostream& operator<<(std::ostream& o,const Vector2& v);