#include <tut/tut.hpp>
#include "Vector3.h"
#include "Vector2.h"
#include <string>

using namespace std;

namespace tut
{
	struct data2
	{

	};

	typedef test_group<data2> tg;
	tg testgroup("test Vector3");

	typedef tg::object testobject2;

	template<>
	template<>
	void testobject2::test<1>()
	{
		set_test_name("cross");

		Vector3 a(1, 0,0);
		Vector3 b(0, 1, 0);
		auto c = Vector3::cross(a, b);
		ensure_equals(c, Vector3(0,0,1));
	}

	template<>
	template<>
	void testobject2::test<2>()
	{
		set_test_name("toString");

		Vector3 v(3, 4,5);
		ensure_equals(v.toString(), string("Vector3(3.000000,4.000000,5.000000)"));
	}

	template<>
	template<>
	void testobject2::test<3>()
	{
		set_test_name("lerp and lerpUnclamped");

		Vector3 b(4, 0,0);
		auto r = Vector3::lerp(Vector3::Zero, b, 0.25f);
		ensure_equals(r.x, 1.0f);

		auto r2 = Vector3::lerpUnclamped(Vector3::Zero, b, 1.25f);
		ensure_equals(r2.x, 5.0f);
	}

	template<>
	template<>
	void testobject2::test<4>()
	{
		set_test_name("angle");

		Vector3 a(0, 4,0);
		Vector3 b(4, 0,0);
		auto r = Vector3::angle(a, b);
		ensure_equals(r, 90);
	}

	template<>
	template<>
	void testobject2::test<5>()
	{
		set_test_name("clampMagnitude");

		Vector3 a(9, 12,20);
		auto r = Vector3::clampMagnitude(a, 10);
		ensure_equals(r.magnitude(), 10);
	}

	template<>
	template<>
	void testobject2::test<6>()
	{
		set_test_name("moveTowards");

		Vector3 a(0, 12,0);
		auto r = Vector2::moveTowards(Vector3::Zero, a, 13);
		ensure_equals(r.magnitude(), 12);
	}

	template<>
	template<>
	void testobject2::test<7>()
	{
		set_test_name("reflect");

		Vector3 a(3, 4,5);
		auto r = Vector3::reflect(a, Vector3::Right);
		ensure_equals(r, Vector3(3, -4,5));
	}

}