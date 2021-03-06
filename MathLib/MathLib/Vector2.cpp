#include <cmath>
#include <climits>
#include "Mathf.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Vector2.h"


using namespace std;

const Vector2 Vector2::Down(0, -1);
const Vector2 Vector2::Left(-1, 0);
const Vector2 Vector2::One(1, 1);
const Vector2 Vector2::Right(1, 0);
const Vector2 Vector2::Up(0, 1);
const Vector2 Vector2::Zero(0, 0);

Vector2::Vector2(const Vector3& v3) :x(v3.x), y(v3.y){}
Vector2::Vector2(const Vector4& v4) : x(v4.x), y(v4.y){}

float Vector2::magnitude() const
{
	return sqrt(x*x + y*y);
}

Vector2 Vector2::normalized() const
{
	float m = this->magnitude();
	if (m == 0)
		return Zero;
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

std::string Vector2::toString() const
{
	char buf[256];
	sprintf(buf, "Vector2(%f,%f)", x, y);
	return string(buf);
}

float Vector2::angle(const Vector2& from, const Vector2& to)
{
	auto normalizedFrom = from.normalized();
	auto normalizedTo = to.normalized();
	auto dotValue = dot(normalizedFrom, normalizedTo);
	auto r = acos(dotValue);
	return r * Mathf::Rad2Deg;
}

Vector2 Vector2::clampMagnitude(const Vector2& v, float maxLength)
{
	auto m = v.magnitude();
	if (m > maxLength)
	{
		auto c = maxLength / m;
		return Vector2(v.x*c, v.y*c);
	}

	return v;
}

float Vector2::distance(const Vector2& a, const Vector2& b)
{
	float xx = a.x - b.x;
	float yy = a.y - b.y;
	return sqrt(xx*xx + yy*yy);
}

float Vector2::dot(const Vector2& a, const Vector2& b)
{
	return a.x*b.x + a.y*b.y;
}

Vector2 Vector2::lerp(const Vector2& a, const Vector2& b, float t)
{
	t = fmaxf(t, 0);
	t = fminf(t, 1);
	return Vector2(b.x*t + a.x*(1 - t), b.y*t + a.y*(1 - t));
}

Vector2 Vector2::lerpUnclamped(const Vector2& a, const Vector2& b, float t)
{
	return Vector2(b.x*t + a.x*(1 - t), b.y*t + a.y*(1 - t));
}

Vector2 Vector2::max(const Vector2& a, const Vector2& b)
{
	return Vector2(fmaxf(a.x,b.x),fmaxf(a.y,b.y));
}

Vector2 Vector2::min(const Vector2& a, const Vector2& b)
{
	return Vector2(fminf(a.x, b.x), fminf(a.y, b.y));
}

Vector2 Vector2::moveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta)
{
	auto v = target - current;

	auto dis = v.magnitude();
	dis = fminf(dis, maxDistanceDelta);
	return current + v.normalized()*dis;
}

Vector2 Vector2::projectToNormal(const Vector2& a, const Vector2& normal)
{
	auto n = normal.normalized();
	auto length = dot(a, n);
	return length*n;
}

Vector2 Vector2::reflect(const Vector2& inDir, const Vector2& inNormal)
{
	Vector2 proj = projectToNormal(inDir, inNormal);
	return proj * 2 - inDir;
}

Vector2 Vector2::scale(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x*b.x,a.y*b.y);
}

Vector2 Vector2::smoothDamp(const Vector2& current, const Vector2& target, Vector2& currentVelocity,
	float smoothTime, float maxSpeed, float deltaTime)
{
	//TODO:
	Vector2 newPos = current;
	if (smoothTime > deltaTime)
	{
		Vector2 dis = target - current;//����
		Vector2 averageVelocity = dis / smoothTime;//ƽ���ٶ�
		Vector2 acc = (averageVelocity - currentVelocity) / smoothTime;
		currentVelocity = currentVelocity + acc*deltaTime;
		Vector2 newPos = current + currentVelocity*deltaTime + 0.5f*acc*deltaTime*deltaTime;
	}
	else
	{
		newPos = target;
	}
	return newPos;
}

Vector2 Vector2::operator-(const Vector2& rhl) const
{
	return Vector2(x - rhl.x, y - rhl.y);
}

Vector2 Vector2::operator+(const Vector2& rhl) const
{
	return Vector2(x + rhl.x, y + rhl.y);
}

Vector2 Vector2::operator*(float d) const
{
	return Vector2(x*d, y*d);
}

Vector2 Vector2::operator/(float d) const
{
	return Vector2(x /d, y/d);
}

bool Vector2::operator==(const Vector2& rhl) const
{
	return x == rhl.x && y == rhl.y;
}

bool Vector2::operator!=(const Vector2& rhl) const
{
	return x != rhl.x || y != rhl.y;
}

Vector2 operator*(float d, const Vector2& rhl)
{
	return Vector2(d*rhl.x, d*rhl.y);
}

std::ostream& operator<<(std::ostream& o, const Vector2& v)
{
	o << v.toString();
	return o;
}