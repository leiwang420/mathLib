#include <tut/tut.hpp>
#include "Vector2.h"

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
}