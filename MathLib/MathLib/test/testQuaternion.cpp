#include <tut/tut.hpp>
#include "MathLib.h"
#include <string>

using namespace std;

namespace tut
{
	struct dataQuat
	{

	};

	typedef test_group<dataQuat> tgQuat;
	tgQuat testgroupQuat("test Quaternion");

	typedef tgQuat::object TestObjectQuat;

	template<>
	template<>
	void TestObjectQuat::test<1>()
	{

	}
}