#include <cmath>
#include <climits>

#include "Mathf.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Vector3.h"


const Vector3 Vector3::Back(0,0, -1);
const Vector3 Vector3::Down(0, -1,0);
const Vector3 Vector3::Forward(0, 0, 1);
const Vector3 Vector3::Left(-1, 0,0);
const Vector3 Vector3::One(1, 1,1);
const Vector3 Vector3::Right(1, 0,0);
const Vector3 Vector3::Up(0, 1,0);
const Vector3 Vector3::Zero(0, 0,0);

Vector3::Vector3(const Vector2& v2) :x(v2.x), y(v2.y), z(0){}
Vector3::Vector3(const Vector4& v4) :x(v4.x), y(v4.y), z(v4.z){}

float Vector3::magnitude() const
{
	return sqrt(sqrMagnitude());
}

Vector3 Vector3::normalized() const
{
	float m = this->magnitude();
	if (m == 0)
		return Zero;
	return Vector3(x / m, y / m, z/m);
}

float Vector3::sqrMagnitude() const
{
	return x*x + y*y + z*z;
}

void Vector3::normalize()
{
	float m = this->magnitude();
	if (m != 0)
	{
		x = x / m;
		y = y / m;
		z = z / m;
	}
}

void Vector3::set(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

std::string Vector3::toString() const
{
	char buf[256];
	sprintf_s(buf, "Vector3(%f,%f,%f)", x, y,z);
	return std::string(buf);
}

float Vector3::angle(const Vector3& from, const Vector3& to)
{
	auto normalizedFrom = from.normalized();
	auto normalizedTo = to.normalized();
	auto dotValue = dot(normalizedFrom, normalizedTo);
	auto r = acos(dotValue);
	return r * Mathf::Rad2Deg;
}

Vector3 Vector3::clampMagnitude(const Vector3& v, float maxLength)
{
	auto m = v.magnitude();
	if (m > maxLength)
	{
		auto c = maxLength / m;
		return Vector3(v.x*c, v.y*c, v.z*c);
	}

	return v;
}

Vector3 Vector3::cross(const Vector3& a, const Vector3& b)
{
	float xx = a.y*b.z - a.z*b.y;
	float yy = a.z*b.x - a.x*b.z;
	float zz = a.x*b.y - a.y*b.x;

	return Vector3(xx, yy, zz);
}

float Vector3::distance(const Vector3& a, const Vector3& b)
{
	float xx = a.x - b.x;
	float yy = a.y - b.y;
	float zz = a.z - b.z;
	return sqrt(xx*xx + yy*yy + zz*zz);
}

float Vector3::dot(const Vector3& a, const Vector3& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float t)
{
	t = fmaxf(t, 0);
	t = fminf(t, 1);
	return Vector3(b.x*t + a.x*(1 - t), b.y*t + a.y*(1 - t), b.z*t + a.z*(1-t));
}

Vector3 Vector3::lerpUnclamped(const Vector3& a, const Vector3& b, float t)
{
	return Vector3(b.x*t + a.x*(1 - t), b.y*t + a.y*(1 - t), b.z*t + a.z*(1 - t));
}

Vector3 Vector3::max(const Vector3& a, const Vector3& b)
{
	return Vector3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
}

Vector3 Vector3::min(const Vector3& a, const Vector3& b)
{
	return Vector3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
}

Vector3 Vector3::moveTowards(const Vector3& current, const Vector3& target, float maxDistanceDelta)
{
	auto v = target - current;

	auto dis = v.magnitude();
	dis = fminf(dis, maxDistanceDelta);
	return current + v.normalized()*dis;
}

Vector3 Vector3::project(const Vector3& a, const Vector3& normal)
{
	auto n = normal.normalized();
	auto length = dot(a, n);
	return length*n;
}

Vector3 Vector3::projectOnPlane(const Vector3& a, const Vector3& planeNormal)
{
	auto n = planeNormal.normalized();
	auto length = dot(a, n);
	return a - length*n;
}

Vector3 Vector3::reflect(const Vector3& inDir, const Vector3& inNormal)
{
	Vector3 proj = project(inDir, inNormal);
	return proj * 2 - inDir;
}

Vector3 Vector3::scale(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x*b.x, a.y*b.y,a.z*b.z);
}

Vector3 Vector3::smoothDamp(const Vector3& current, const Vector3& target, Vector3& currentVelocity,
	float smoothTime, float maxSpeed, float deltaTime)
{
	//TODO:
	Vector3 newPos = current;
	if (smoothTime > deltaTime)
	{
		Vector3 dis = target - current;//距离
		Vector3 averageVelocity = dis / smoothTime;//平均速度
		Vector3 acc = (averageVelocity - currentVelocity) / smoothTime;
		currentVelocity = currentVelocity + acc*deltaTime;
		Vector3 newPos = current + currentVelocity*deltaTime + 0.5f*acc*deltaTime*deltaTime;
	}
	else
	{
		newPos = target;
	}
	return newPos;
}

Vector3 Vector3::operator-(const Vector3& rhl) const
{
	return Vector3(x - rhl.x, y - rhl.y,z - rhl.z);
}

Vector3 Vector3::operator+(const Vector3& rhl) const
{
	return Vector3(x + rhl.x, y + rhl.y,z+rhl.z);
}

Vector3 Vector3::operator*(float d) const
{
	return Vector3(x*d, y*d,z*d);
}

Vector3 Vector3::operator/(float d) const
{
	return Vector3(x / d, y / d,z/d);
}

bool Vector3::operator==(const Vector3& rhl) const
{
	return x == rhl.x && y == rhl.y && z == rhl.z;
}

bool Vector3::operator!=(const Vector3& rhl) const
{
	return x != rhl.x || y != rhl.y || z != rhl.z;
}

Vector3 operator*(float d, const Vector3& rhl)
{
	return Vector3(d*rhl.x, d*rhl.y,d*rhl.z);
}

std::ostream& operator<<(std::ostream& o, const Vector3& v)
{
	o << v.toString();
	return o;
}