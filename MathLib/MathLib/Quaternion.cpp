#include "Vector3.h"
#include "Quaternion.h"

Quaternion Quaternion::Identity;

Vector3 Quaternion::eulerAngles() const{ return Vector3(); }
void Quaternion::setEulerAngles(const Vector3& e){}
void Quaternion::set(float _x, float _y, float _z, float _w){}
void Quaternion::setFromToRotation(const Vector3& from, const Vector3& to){}
void Quaternion::setLookRotation(const Vector3& view, const Vector3& up){}

void Quaternion::ToAngleAxis(float& angle, Vector3& axis){}

std::string Quaternion::toString(){ return ""; }

//static 
float Quaternion::angle(const Quaternion& a, const Quaternion& b){ return 0; }
Quaternion Quaternion::angleAxis(float angle, Vector3 axis){ return Quaternion(); }
float Quaternion::dot(const Quaternion& a, const Quaternion& b){ return 0; }
Quaternion Quaternion::euler(const Vector3& eular){ return Quaternion(); }
Quaternion Quaternion::euler(float x, float y, float z){ return Quaternion(); }
Quaternion Quaternion::fromToRotation(const Vector3& fromDir, const Vector3& toDir){ return Quaternion(); }
Quaternion Quaternion::inverse(const Quaternion& a){ return Quaternion(); }
Quaternion Quaternion::lerp(const Quaternion& a, const Quaternion& b, float t){ return Quaternion(); }
Quaternion Quaternion::lerpUnclamped(const Quaternion& a, const Quaternion& b, float t){ return Quaternion(); }
Quaternion Quaternion::lookRotation(const Vector3& forward, const Vector3& up){ return Quaternion(); }
Quaternion Quaternion::rotateTowards(const Quaternion& from, const Quaternion& to, float maxDegreesDelta){ return Quaternion(); }
Quaternion Quaternion::slerp(const Quaternion& a, const Quaternion& b, float t){ return Quaternion(); }
Quaternion Quaternion::slerpUnclamped(const Quaternion& a, const Quaternion& b, float t){ return Quaternion(); }

//operators
Quaternion Quaternion::operator*(const Quaternion& rhs) const
{
	return Quaternion();
}

Vector3 Quaternion::operator*(const Vector3& point) const
{
	return Vector3();
}

bool Quaternion::operator==(const Quaternion& rhs) const
{
	return x == rhs.x && rhs.y == y && rhs.z == z && rhs.w == w;
}

bool Quaternion::operator!=(const Quaternion& rhs) const
{
	return !Quaternion::operator==(rhs);
}