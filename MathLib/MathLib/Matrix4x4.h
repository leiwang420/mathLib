#pragma once

#include <string>
//Column major
struct Vector3;
struct Vector4;
struct Quaternion;

struct Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(float _m11, float _m12, float _m13, float _m14,
	float _m21, float _m22, float _m23, float _m24,
	float _m31, float _m32, float _m33, float _m34,
	float _m41, float _m42, float _m43, float _m44);
	Matrix4x4(float* _m);

	union
	{
		float m[16];
		float c[4][4];
		struct  
		{
			float m11, m12, m13, m14;
			float m21, m22, m23, m24;
			float m31, m32, m33, m34;
			float m41, m42, m43, m44;
		};
	};

	static const Matrix4x4 Identity;
	static const Matrix4x4 Zero;

	float determinant() const;
	Matrix4x4 inverse() const;
	bool isIdentity() const;
	Matrix4x4 transpose() const;

	Vector4 getColumn(int i) const;
	Vector4 getRow(int i) const;

	Vector3 multiplyPoint(const Vector3& v);
	Vector3 multiplyPoint3x4(const Vector3& v);
	Vector3 multiplyVector(const Vector3& v);

	void setColumn(int i, const Vector4& v);
	void setRow(int i, const Vector4& v);
	void setTRS(const Vector3& pos, const Quaternion& q, const Vector3& s);

	std::string toString() const ;

	static Matrix4x4 ortho(float left, float right, float bottom, float top, float zNear, float zFar);
	static Matrix4x4 perspective(float fov, float aspect, float zNear, float zFar);
	static Matrix4x4 scale(const Vector3& v);
	static Matrix4x4 trs(const Vector3& pos, const Quaternion& q, const Vector3& s);

	Matrix4x4 operator*(const Matrix4x4& rhs) const;
	Vector4 operator*(const Vector4& rhs) const;
	bool operator==(const Matrix4x4& rhs) const;
	bool operator!=(const Matrix4x4& rhs) const;
};

std::ostream& operator<<(std::ostream& o, const Matrix4x4& m);