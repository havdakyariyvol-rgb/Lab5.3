#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.3/Lab5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab53Test
{
	TEST_CLASS(Lab53Test)
	{
	public:

		TEST_METHOD(TestH_GreaterOrEqualOne)
		{
			// Перевірка гілки |x| >= 1 (при x = 1: (cos(1) + 1) / (cos^2(1) + 1) ≈ 1.192059)
			double x = 1.0;
			double expected = (cos(1.0) + 1.0) / (pow(cos(1.0), 2) + 1.0);
			double actual = h(x);
			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(TestH_LessThanOne)
		{
			// Перевірка гілки |x| < 1 (при x = 0: сума = 1, cos(0) = 1 -> h(0) = 1)
			double x = 0.0;
			double expected = 1.0;
			double actual = h(x);
			Assert::AreEqual(expected, actual, 0.0001);
		}
	};
}