#pragma once

#include <vector>

#include "Vector3.h"
#include "Quaternion.h"

class Transform
{
public:
	Transform();
	~Transform();

	//子对象个数
	int childCount() const;

	//欧拉角表达的旋转（单位：度）, 旋转顺序为z,x,y
	Vector3 eulerAngles() const;
	void setEulerAngles(const Vector3& e);

	Vector3 localPosition() const;
	void setLocalPosition(const Vector3& v);

	Quaternion localRotation() const;
	void setLocalRotation(const Quaternion& q);

	Vector3 localScale() const;
	void setLocalScale(const Vector3& s);

	Transform* parent() const;
	void setParent(Transform* p);

	Transform* getChild(int i) const ;

	Transform* root();

	Vector3 position() const;
	void setPosition(const Vector3& v);//设置世界坐标系位置

	void detachChildren();
	int getSiblingIndex() const;//返回自己在parent的子对象中的索引号, 没找到返回-1
	bool isChildOf(const Transform* t);//是否是t的子对象
	void setAsFirstSibling();
	void setAsLastSibling();
	void setSiblingIndex(int index);

	void translate(const Vector3& t);
	void rotate(const Vector3& euler);

	bool hasChanged() const{ return mHasChanged; }
	void setHasChanged(bool b){ mHasChanged = b; }

	Vector3 forward() const;
	Vector3 right() const;
	Vector3 up() const;
private:
	Transform* mParent;//父对象
	std::vector<Transform*> mChildren;//子对象

	Vector3 mLocalPosition;
	Quaternion mLocalRotation;
	Vector3 mLocalScale;

	Vector3 mPosition;
	Vector3 mEuler;

	bool mHasChanged;
};

