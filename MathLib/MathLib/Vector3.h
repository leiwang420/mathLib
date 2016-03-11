#pragma once

#include <string>
#include <iostream>
#include "Mathf.h"
#include "MTime.h"

struct Vector2;
struct Vector4;

struct Vector3
{
public:
	Vector3() :x(0), y(0), z(0){}
	Vector3(float _x, float _y, float _z=0) :x(_x), y(_y), z(_z){}
	Vector3(const Vector3& v) :x(v.x), y(v.y), z(v.z){}
	Vector3(const Vector2& v);
	Vector3(const Vector4& v);

	union
	{
		struct{
			float x, y, z;
		};
		
		float v[3];
	};
	

	//variables
	float magnitude() const;
	Vector3 normalized() const;
	float sqrMagnitude() const;
	float operator[](int index) const { return v[index]; }

	//public functions
	void set(float _x, float _y, float _z);
	void normalize();
	std::string toString() const;
	
	//static functions
	static float angle(const Vector3& from, const Vector3& to);
	static Vector3 clampMagnitude(const Vector3& v, float maxLength);
	static Vector3 cross(const Vector3& a, const Vector3& b);
	static float distance(const Vector3& a, const Vector3& b);
	static float dot(const Vector3& a, const Vector3& b);
	static Vector3 lerp(const Vector3& a, const Vector3& b, float t);
	static Vector3 lerpUnclamped(const Vector3& a, const Vector3& b, float t);
	static Vector3 max(const Vector3& a, const Vector3& b);
	static Vector3 min(const Vector3& a, const Vector3& b);
	static Vector3 moveTowards(const Vector3& current, const Vector3& target, float maxDistanceDelta);
	static void orthoNormalize(Vector3& normal, Vector3& tangent);
	static Vector3 project(const Vector3& v,const Vector3& onNormal);
	static Vector3 projectOnPlane(const Vector3& v, const Vector3& planeNormal);
	static Vector3 reflect(const Vector3& inDir, const Vector3& inNormal);
	static Vector3 rotateTowards(const Vector3& current, const Vector3& target, float maxRadiansDelta, float maxMagnitudeDelta);
	static Vector3 scale(const Vector3& a, const Vector3& b);
	static Vector3 slerp(const Vector3& a, const Vector3& b, float t);
	static Vector3 slerpUnclamped(const Vector3& a, const Vector3& b, float t);
	static Vector3 smoothDamp(const Vector3& current, const Vector3& target, Vector3& currentVelocity,
		float smoothTime, float maxSpeed = Mathf::Infinity, float deltaTime = Time::defaultDeltaTime);

	//operators
	Vector3 operator-(const Vector3& rhl) const;
	Vector3 operator+(const Vector3& rhl) const;
	Vector3 operator*(float d) const;
	Vector3 operator/(float d) const;
	bool operator==(const Vector3& rhl) const;
	bool operator!=(const Vector3& rhl) const;

	//static Variables
	static const Vector3 Back;
	static const Vector3 Down;
	static const Vector3 Forward;
	static const Vector3 Left;
	static const Vector3 One;
	static const Vector3 Right;
	static const Vector3 Up;
	static const Vector3 Zero;
};

Vector3 operator*(float d, const Vector3& rhl);

std::ostream& operator<<(std::ostream& o, const Vector3& v);