#include <tut/tut.hpp>
#include "MathLib.h"
#include <string>

using namespace std;

namespace tut
{
	struct data4
	{

	};

	typedef test_group<data4> tg4;
	tg4 testgroup4("test Matrix4x4");

	typedef tg4::object Matrix4x4TestObject;

	template<>
	template<>
	void Matrix4x4TestObject::test<1>()
	{
		set_test_name("matrix construct");

		float buf[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
		Matrix4x4 m1(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
		Matrix4x4 m2(&buf[0]);
		ensure_equals(m1, m2);
	}

	template<>
	template<>
	void Matrix4x4TestObject::test<2>()
	{
		set_test_name("matrix construct");

//		Matrix4x4 m();
	}

}