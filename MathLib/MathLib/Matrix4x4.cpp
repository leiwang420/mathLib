#include <string.h>
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

const Matrix4x4 Matrix4x4::Identity(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f );

const Matrix4x4 Matrix4x4::Zero(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f);

Matrix4x4::Matrix4x4(float _m11, float _m12, float _m13, float _m14,
	float _m21, float _m22, float _m23, float _m24,
	float _m31, float _m32, float _m33, float _m34,
	float _m41, float _m42, float _m43, float _m44)
{
	m11 = _m11; m12 = _m12; m13 = _m13; m14 = _m14;
	m21 = _m21; m22 = _m22; m23 = _m23; m24 = _m24;
	m31 = _m31; m32 = _m32; m33 = _m33; m34 = _m34;
	m41 = _m41; m42 = _m42; m43 = _m43; m44 = _m44;
}

Matrix4x4::Matrix4x4()
{
	memset(&m[0], 0, sizeof(m));
}

Matrix4x4::Matrix4x4(float* _m)
{
	memcpy(&m[0], _m, sizeof(_m));
}

//ÐÐÁÐÊ½
float Matrix4x4::determinant() const
{
	return m11*( m22*(m33*m44 - m34*m43) - m23*(m32*m44-m34*m42) + m24*(m32*m43-m42*m33) )
		- m12*( m21*(m33*m34 - m34*m43) - m23*(m22*m44-m23*m34) + m24*(m22*m43*m23*m33) )
		+ m13*( m21*(m32*m44-m42*m34) - m22*(m22*m44-m23*m34) + m24*(m22*m42-m23*m32) )
		- m14*( m21*(m32*m43-m42-m33) - m22*(m22*m43-m23*m33) + m23*(m22*m42-m23*m32) );
}

Matrix4x4 Matrix4x4::inverse() const
{
	return Zero;
}

bool Matrix4x4::isIdentity() const
{
	return *this == Identity;
}

Matrix4x4 Matrix4x4::transpose() const
{
	return Matrix4x4();
}

Vector4 Matrix4x4::getColumn(int i) const
{
	return Vector4(c[0][i],c[1][i],c[2][i],c[3][i]);
}

Vector4 Matrix4x4::getRow(int i) const
{
	return Vector4(c[i][0], c[i][1], c[i][2], c[i][3]);
}

Vector3 Matrix4x4::multiplyPoint(const Vector3& v)
{
	return Vector3();
}
Vector3 Matrix4x4::multiplyPoint3x4(const Vector3& v)
{
	return Vector3();
}
Vector3 Matrix4x4::multiplyVector(const Vector3& v)
{
	return Vector3();
}

void Matrix4x4::setColumn(int i, const Vector4& v)
{
	c[0][i] = v.x;
	c[1][i] = v.y;
	c[2][i] = v.z; 
	c[3][i] = v.w;
}

void Matrix4x4::setRow(int i, const Vector4& v)
{
	c[i][0] = v.x;
	c[i][1] = v.y;
	c[i][2] = v.z;
	c[i][3] = v.w;
}

void Matrix4x4::setTRS(const Vector3& pos, const Quaternion& q, const Vector3& s)
{
	//todo:
}

std::string Matrix4x4::toString() const
{
	char buf[512];
	sprintf(buf,"Matrix4x4(%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f)",m11,m12,m13,m14,m21,m22,m23,m24,
		m31,m32,m33,m34,m41,m42,m43,m44);
	return buf;
}

Matrix4x4 Matrix4x4::ortho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::perspective(float fov, float aspect, float zNear, float zFar)
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::scale(const Vector3& v)
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::trs(const Vector3& pos, const Quaternion& q, const Vector3& s)
{
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rhs) const
{
	float _m11 = m11*rhs.m11 + m12*rhs.m21 + m13*rhs.m31 + m14*rhs.m41;
	float _m12 = m11*rhs.m12 + m12*rhs.m22 + m13*rhs.m32 + m14*rhs.m42;
	float _m13 = m11*rhs.m13 + m12*rhs.m23 + m13*rhs.m33 + m14*rhs.m43;
	float _m14 = m11*rhs.m14 + m12*rhs.m24 + m13*rhs.m34 + m14*rhs.m44;

	float _m21 = m21*rhs.m11 + m22*rhs.m21 + m23*rhs.m31 + m24*rhs.m41;
	float _m22 = m21*rhs.m12 + m22*rhs.m22 + m23*rhs.m32 + m24*rhs.m42;
	float _m23 = m21*rhs.m13 + m22*rhs.m23 + m23*rhs.m33 + m24*rhs.m43;
	float _m24 = m21*rhs.m14 + m22*rhs.m24 + m23*rhs.m34 + m24*rhs.m44;

	float _m31 = m31*rhs.m11 + m32*rhs.m21 + m33*rhs.m31 + m34*rhs.m41;
	float _m32 = m31*rhs.m12 + m32*rhs.m22 + m33*rhs.m32 + m34*rhs.m42;
	float _m33 = m31*rhs.m13 + m32*rhs.m23 + m33*rhs.m33 + m34*rhs.m43;
	float _m34 = m31*rhs.m14 + m32*rhs.m24 + m33*rhs.m34 + m34*rhs.m44;

	float _m41 = m41*rhs.m11 + m42*rhs.m21 + m43*rhs.m31 + m44*rhs.m41;
	float _m42 = m41*rhs.m12 + m42*rhs.m22 + m43*rhs.m32 + m44*rhs.m42;
	float _m43 = m41*rhs.m13 + m42*rhs.m23 + m43*rhs.m33 + m44*rhs.m43;
	float _m44 = m41*rhs.m14 + m42*rhs.m24 + m43*rhs.m34 + m44*rhs.m44;
	
	return	Matrix4x4(
		_m11, _m12, _m13, _m14,
		_m21, _m22, _m23, _m24,
		_m31, _m32, _m33, _m34,
		_m41, _m42, _m43, _m44);
}

Vector4 Matrix4x4::operator*(const Vector4& rhs) const
{
	float x = m11*rhs.x + m12*rhs.y + m13*rhs.z + m14*rhs.w;
	float y = m21*rhs.x + m22*rhs.y + m23*rhs.z + m24*rhs.w;
	float z = m31*rhs.x + m32*rhs.y + m33*rhs.z + m34*rhs.w;
	float w = m41*rhs.x + m42*rhs.y + m43*rhs.z + m44*rhs.w;

	return Vector4(x,y,z,w);
}

bool Matrix4x4::operator==(const Matrix4x4& rhs) const
{
	for (int i = 0; i < 16; ++i)
	{
		if (m[i] != rhs.m[16])
			return false;
	}

	return true;
}

bool Matrix4x4::operator!=(const Matrix4x4& rhs) const
{
	return !operator==(rhs);
}

std::ostream& operator<<(std::ostream& o, const Matrix4x4& m)
{
	o << m.toString();
	return o;
}