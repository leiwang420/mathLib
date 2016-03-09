#include <cmath>
#include "Vector2.h"

using namespace std;

Vector2 Vector2::down(0,-1);
Vector2 Vector2::left(-1,0);
Vector2 Vector2::one(1,1);
Vector2 Vector2::right(1,0);
Vector2 Vector2::up(0,1);
Vector2 Vector2::zero(0,0);


float Vector2::magnitude() const
{
	return sqrt(x*x + y*y);
}

Vector2 Vector2::normalized() const
{
	float m = this->magnitude();
	if (m == 0)
		return zero;
	return Vector2(x/m,y/m);
}

float Vector2::sqrMagnitude() const
{
	return x*x + y*y;
}

void Vector2::normalize()
{
	float m = this->magnitude();
	if (m != 0)
	{
		x = x / m;
		y = y / m;
	}
}

void Vector2::set(float _x, float _y)
{
	x = _x;
	y = _y;
}

std::string Vector2::toString()
{
	char buf[256];
	sprintf_s(buf, "Vector2(%f,%f)", x, y);
	return string(buf);
}

//static functions
float Vector2::angle(const Vector2& from, const Vector2& to)
{

}
Vector2 Vector2::clampMagnitude(const Vector2& v, float maxLength)
{

}
float Vector2::distance(const Vector2& a, const Vector2& b)
{

}
float Vector2::dot(const Vector2& a, const Vector2& b)
{

}
Vector2 Vector2::lerp(const Vector2& a, const Vector2& b, float t)
{

}
Vector2 Vector2::lerpUnclamped(const Vector2& a, const Vector2& b, float t)
{

}