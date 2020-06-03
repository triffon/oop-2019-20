#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftwareCompany/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SoftwareCompanyTests
{
	TEST_CLASS(SoftwareCompanyTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Person p("gosho", "penchev", 14);
			Assert::AreEqual(p.getAge(), 14);
		}
	};
}
