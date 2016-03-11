#include <tut/tut.hpp>
#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include <string>

using namespace std;

namespace tut
{
	struct data3
	{

	};

	typedef test_group<data3> tg;
	tg testgroup("test Vector4");

	typedef tg::object testobject2;


	template<>
	template<>
	void testobject2::test<2>()
	{
		set_test_name("toString");

		Vector4 v(3, 4, 5,1);
		ensure_equals(v.toString(), string("Vector4(3.000000,4.000000,5.000000,1.000000)"));
	}

	template<>
	template<>
	void testobject2::test<3>()
	{
		set_test_name("lerp and lerpUnclamped");

		Vector4 b(4, 0, 0,0);
		auto r = Vector4::lerp(Vector4::Zero, b, 0.25f);
		ensure_equals(r.x, 1.0f);

		auto r2 = Vector4::lerpUnclamped(Vector4::Zero, b, 1.25f);
		ensure_equals(r2.x, 5.0f);
	}


	template<>
	template<>
	void testobject2::test<6>()
	{
		set_test_name("moveTowards");

		Vector4 a(0, 12, 0,0);
		auto r = Vector4::moveTowards(Vector4::Zero, a, 13);
		ensure_equals(r.magnitude(), 12);
	}


}