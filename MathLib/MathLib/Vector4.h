#pragma once

#include <string>
class Vector2;
class Vector3;

class Vector4
{
public:
	Vector4() :x(0), y(0), z(0){}
	Vector4(float _x, float _y, float _z, float _w) :x(_x), y(_y), z(_z), w(_w){}
	Vector4(const Vector4& a) :x(a.x), y(a.y), z(a.z), w(a.w){}
	Vector4(const Vector2& v2);
	Vector4(const Vector3& v2);

	union 
	{
		struct
		{
			float x, y, z,w;
		};
		float v[4];
	};

	//static Variables
	static const Vector4 One;
	static const Vector4 Zero;

	//Variables
	float magnitude() const;
	Vector4 normalized() const;
	float sqrMagnitude() const;
	float operator[](int i){ return v[i]; }

	//public functions
	void set(float _x, float _y, float _z, float _w);
	std::string toString() const ;
	void normalize();

	//static functions
	static float distance(const Vector4& a, const Vector4& b);
	static float dot(const Vector4& a, const Vector4& b);
	static Vector4 lerp(const Vector4& a, const Vector4& b, float t);
	static Vector4 lerpUnclamped(const Vector4& a, const Vector4& b, float t);
	static Vector4 max(const Vector4& a, const Vector4& b);
	static Vector4 min(const Vector4& a, const Vector4& b);
	static Vector4 moveTowards(const Vector4& current, const Vector4& target, float maxDistanceDelta);
	static Vector4 project(const Vector4& a, const Vector4& b);
	static Vector4 scale(const Vector4& a, const Vector4& b);

	//operators
	Vector4 operator-(const Vector4& rhl) const;
	Vector4 operator+(const Vector4& rhl) const;
	Vector4 operator*(float d) const;
	Vector4 operator/(float d) const;
	bool operator==(const Vector4& rhl) const;
	bool operator!=(const Vector4& rhl) const;
};

Vector4 operator*(float d, const Vector4& rhl);

std::ostream& operator<<(std::ostream& o, const Vector4& v);

