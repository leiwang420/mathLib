#pragma once

#include <string>

struct Vector3;

struct Quaternion
{
public:
	Quaternion() :x(0), y(0), z(0), w(0){}
	Quaternion(float _x,float _y,float _z,float _w) :x(_x), y(_y), z(_z), w(_w){}
	Quaternion(const Quaternion& q) :x(q.x), y(q.y), z(q.z), w(q.w){}

	union 
	{
		struct 
		{
			float x, y, z, w;
		};
		float v[4];
	};

	//static Variables
	static Quaternion Identity;

	//Variables
	Vector3 eulerAngles() const;
	void setEulerAngles(const Vector3& e);
	void set(float _x, float _y, float _z, float _w);
	void setFromToRotation(const Vector3& from, const Vector3& to);
	void setLookRotation(const Vector3& view, const Vector3& up = Vector3::Up);

	void ToAngleAxis(float& angle, Vector3& axis);

	std::string toString();

	//static 
	static float angle(const Quaternion& a, const Quaternion& b);
	static Quaternion angleAxis(float angle, Vector3 axis);
	static float dot(const Quaternion& a, const Quaternion& b);
	static Quaternion euler(const Vector3& eular);
	static Quaternion euler(float x, float y, float z);
	static Quaternion fromToRotation(const Vector3& fromDir, const Vector3& toDir);
	static Quaternion inverse(const Quaternion& a);
	static Quaternion lerp(const Quaternion& a, const Quaternion& b, float t);
	static Quaternion lerpUnclamped(const Quaternion& a, const Quaternion& b, float t);
	static Quaternion lookRotation(const Vector3& forward, const Vector3& up = Vector3::Up);
	static Quaternion rotateTowards(const Quaternion& from, const Quaternion& to, float maxDegreesDelta);
	static Quaternion slerp(const Quaternion& a, const Quaternion& b, float t);
	static Quaternion slerpUnclamped(const Quaternion& a, const Quaternion& b, float t);

	//operators
	Quaternion operator*(const Quaternion& rhs) const;
	Vector3 operator*(const Vector3& point) const;
	bool operator==(const Quaternion& rhs) const;
	bool operator!=(const Quaternion& rhs) const;
};

