#include <tut/tut.hpp>
#include "Vector2.h"
#include <string>

using namespace std;

namespace tut
{
	struct data
	{

	};

	typedef test_group<data> tg;
	tg testgroup("test Vector2");

	typedef tg::object testobject;

	template<>
	template<>
	void testobject::test<1>()
	{
		set_test_name("sqrMagnitude");

		Vector2 v(3, 4);
		ensure_equals(v.sqrMagnitude(), 3 * 3 + 4 * 4);
	}

	template<>
	template<>
	void testobject::test<2>()
	{
		set_test_name("toString");

		Vector2 v(3, 4);
		ensure_equals(v.toString(), string("Vector2(3.000000,4.000000)"));
	}

	template<>
	template<>
	void testobject::test<3>()
	{
		set_test_name("lerp and lerpUnclamped");

		Vector2 b(4, 0);
		auto r = Vector2::lerp(Vector2::zero, b, 0.25f);
		ensure_equals(r.x,1.0f);

		auto r2 = Vector2::lerpUnclamped(Vector2::zero, b, 1.25f);
		ensure_equals(r2.x, 5.0f);
	}

	template<>
	template<>
	void testobject::test<4>()
	{
		set_test_name("angle");

		Vector2 a(0, 4);
		Vector2 b(4, 0);
		auto r = Vector2::angle(a, b);
		ensure_equals(r, 90);
	}

	template<>
	template<>
	void testobject::test<5>()
	{
		set_test_name("clampMagnitude");

		Vector2 a(9, 12);
		auto r = Vector2::clampMagnitude(a, 10);
		ensure_equals(r.magnitude(), 10);
	}

	template<>
	template<>
	void testobject::test<6>()
	{
		set_test_name("moveTowards");

		Vector2 a(0, 12);
		auto r = Vector2::moveTowards(Vector2::zero, a,13);
		ensure_equals(r.magnitude(), 12);
	}
	
}