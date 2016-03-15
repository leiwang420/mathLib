#include <assert.h>
#include "Transform.h"


Transform::Transform()
{
}


Transform::~Transform()
{
}

//子对象个数
int Transform::childCount() const
{
	return mChildren.size();
}

//欧拉角表达的旋转（单位：度）, 旋转顺序为z,x,y
Vector3 Transform::eulerAngles() const
{
	return mEuler;
}

void Transform::setEulerAngles(const Vector3& e)
{
	mEuler = e;
}

Vector3 Transform::localPosition() const
{
	return mLocalPosition;
}

void Transform::setLocalPosition(const Vector3& v)
{
	mLocalPosition = v;
}

Quaternion Transform::localRotation() const
{
	return mLocalRotation;
}

void Transform::setLocalRotation(const Quaternion& q)
{
	mLocalRotation = q;
}

Vector3 Transform::localScale() const
{
	return	mLocalScale;
}

void Transform::setLocalScale(const Vector3& s)
{
	mLocalScale = s;
}

Transform* Transform::parent() const
{
	return mParent;
}

void Transform::setParent(Transform* p)
{
	mParent = p;
}

Transform* Transform::getChild(int i) const
{
	assert(i < (int)mChildren.size());
	return mChildren[i];
}

Transform* Transform::root()
{
	Transform* r = this;
	while (r->mParent != nullptr)
	{
		r = r->mParent;
	}

	return r;
}

Vector3 Transform::position() const
{
	return mPosition;
}

void Transform::setPosition(const Vector3& v)
{
	mPosition = v;
}

void Transform::detachChildren()
{
    for(auto it = mChildren.begin();it!=mChildren.end();++it)
	{
		(*it)->setParent(nullptr);
	}
}

int Transform::getSiblingIndex() const
{
	if (mParent != nullptr)
	{
		int num = mParent->childCount();
		for (int i = 0; i < num; ++i)
		{
			auto c = mParent->getChild(i);
			if (c == this)
				return i;
		}
	}

	return -1;
}

bool Transform::isChildOf(const Transform* t)
{
	if (t == nullptr)
		return false;

	int num = t->childCount();
	for (int i = 0; i < num; ++i)
	{
		auto c = t->getChild(i);
		if (c == this)
			return true;
	}

	return false;
}

void Transform::setAsFirstSibling()
{
	auto index = getSiblingIndex();
	for (int i = index; i > 0; --i)
	{
		mChildren[i] = mChildren[i - 1];
	}
	mChildren[0] = this;
}

void Transform::setAsLastSibling()
{
	auto index = getSiblingIndex();
	auto count = mParent->childCount() - 1;
	for (int i = index; i < count; ++i)
	{
		mChildren[i] = mChildren[i + 1];
	}
	mChildren[count - 1] = this;
}

void Transform::setSiblingIndex(int index)
{
	assert(index >= 0 && index < mParent->childCount());

	auto cur = getSiblingIndex();
	int delta = index - cur;
	if (delta > 0)
	{
		for (int i = cur; i < index; ++i)
		{
			mParent->mChildren[i] = mParent->mChildren[i + 1];
		}
	}
	else if (delta < 0)
	{
		for (int i = cur; i > index; --i)
		{
			mParent->mChildren[i] = mParent->mChildren[i - 1];
		}
	}
	else
	{
		return;
	}
	
	mParent->mChildren[index] = this;
}

Vector3 Transform::forward() const
{
	return Vector3();
}