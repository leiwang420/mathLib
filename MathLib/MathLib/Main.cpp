#include <tut/tut.hpp>
#include <tut/tut_reporter.hpp>

using std::endl;
using std::cerr;
using std::exception;

namespace tut
{
	test_runner_singleton runner;
}

int main()
{
	tut::reporter reporter;
	tut::runner.get().set_callback(&reporter);
	tut::runner.get().run_tests();

	system("pause");

	return !reporter.all_ok();
}