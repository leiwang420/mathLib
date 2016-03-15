#include <tut/tut.hpp>
#include "MathLib.h"
#include <string>

using namespace std;

namespace tut
{
	struct dataTran
	{

	};

	typedef test_group<dataTran> tgTran;
	tgTran testgroupTran("test Transform");

	typedef tgTran::object TestObjectTran;

	template<>
	template<>
	void TestObjectTran::test<1>()
	{

	}
}