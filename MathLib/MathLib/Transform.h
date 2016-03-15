#pragma once

#include <vector>

#include "Vector3.h"
#include "Quaternion.h"

class Transform
{
public:
	Transform();
	~Transform();

	//�Ӷ������
	int childCount() const;

	//ŷ���Ǳ�����ת����λ���ȣ�, ��ת˳��Ϊz,x,y
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
	void setPosition(const Vector3& v);//������������ϵλ��

	void detachChildren();
	int getSiblingIndex() const;//�����Լ���parent���Ӷ����е�������, û�ҵ�����-1
	bool isChildOf(const Transform* t);//�Ƿ���t���Ӷ���
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
	Transform* mParent;//������
	std::vector<Transform*> mChildren;//�Ӷ���

	Vector3 mLocalPosition;
	Quaternion mLocalRotation;
	Vector3 mLocalScale;

	Vector3 mPosition;
	Vector3 mEuler;

	bool mHasChanged;
};

