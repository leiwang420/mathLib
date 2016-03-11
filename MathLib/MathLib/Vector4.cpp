#include <cmath>
#include <climits>

#include "Mathf.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

Vector4::Vector4(const Vector2& v2) :x(v2.x), y(v2.y), z(0), w(0){}
Vector4::Vector4(const Vector3& v3) : x(v3.x), y(v3.y), z(v3.z), w(0){}

const Vector4 Vector4::One(1,1,1,1);
const Vector4 Vector4::Zero(0,0,0,0);

float Vector4::magnitude() const
{
	return sqrt(sqrMagnitude());
}

Vector4 Vector4::normalized() const
{
	float m = this->magnitude();
	if (m == 0)
		return Zero;
	return Vector4(x / m, y / m, z / m,w/m);
}

float Vector4::sqrMagnitude() const
{
	return x*x + y*y + z*z + w*w;
}

void Vector4::normalize()
{
	float m = this->magnitude();
	if (m != 0)
	{
		x = x / m;
		y = y / m;
		z = z / m;
	}
}

void Vector4::set(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

std::string Vector4::toString() const
{
	char buf[256];
	sprintf(buf, "Vector4(%f,%f,%f,%f)", x, y, z,w);
	return std::string(buf);
}


float Vector4::distance(const Vector4& a, const Vector4& b)
{
	float xx = a.x - b.x;
	float yy = a.y - b.y;
	float zz = a.z - b.z;
	float ww = a.w - b.w;
	return sqrt(xx*xx + yy*yy + zz*zz + ww*ww);
}

float Vector4::dot(const Vector4& a, const Vector4& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

Vector4 Vector4::lerp(const Vector4& a, const Vector4& b, float t)
{
	t = fmaxf(t, 0);
	t = fminf(t, 1);
	return Vector4(b.x*t + a.x*(1 - t), b.y*t + a.y*(1 - t), b.z*t + a.z*(1 - t), b.w*t + a.w*(1 - t));
}

Vector4 Vector4::lerpUnclamped(const Vector4& a, const Vector4& b, float t)
{
	return Vector4(b.x*t + a.x*(1 - t), b.y*t + a.y*(1 - t), b.z*t + a.z*(1 - t), b.w*t + a.w*(1 - t));
}

Vector4 Vector4::max(const Vector4& a, const Vector4& b)
{
	return Vector4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
}

Vector4 Vector4::min(const Vector4& a, const Vector4& b)
{
	return Vector4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
}

Vector4 Vector4::moveTowards(const Vector4& current, const Vector4& target, float maxDistanceDelta)
{
	auto v = target - current;

	auto dis = v.magnitude();
	dis = fminf(dis, maxDistanceDelta);
	return current + v.normalized()*dis;
}

Vector4 Vector4::project(const Vector4& a, const Vector4& normal)
{
	auto n = normal.normalized();
	auto length = dot(a, n);
	return length*n;
}

Vector4 Vector4::scale(const Vector4& a, const Vector4& b)
{
	return Vector4(a.x*b.x, a.y*b.y, a.z*b.z,a.w*b.w);
}

Vector4 Vector4::operator-(const Vector4& rhl) const
{
	return Vector4(x - rhl.x, y - rhl.y, z - rhl.z,w - rhl.w);
}

Vector4 Vector4::operator+(const Vector4& rhl) const
{
	return Vector4(x + rhl.x, y + rhl.y, z + rhl.z, w + rhl.w);
}

Vector4 Vector4::operator*(float d) const
{
	return Vector4(x*d, y*d, z*d,w*d);
}

Vector4 Vector4::operator/(float d) const
{
	return Vector4(x / d, y / d, z / d,w/d);
}

bool Vector4::operator==(const Vector4& rhl) const
{
	return x == rhl.x && y == rhl.y && z == rhl.z && w == rhl.w;
}

bool Vector4::operator!=(const Vector4& rhl) const
{
	return x != rhl.x || y != rhl.y || z != rhl.z || w != rhl.w;
}

Vector4 operator*(float d, const Vector4& rhl)
{
	return Vector4(d*rhl.x, d*rhl.y, d*rhl.z, d*rhl.w);
}

std::ostream& operator<<(std::ostream& o, const Vector4& v)
{
	o << v.toString();
	return o;
}