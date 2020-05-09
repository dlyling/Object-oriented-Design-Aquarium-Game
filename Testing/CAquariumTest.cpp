#include "pch.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "FishBeta.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}
		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2,
				L"Choosing the fish on the top of it");

			Assert::IsTrue(aquarium.HitTest(200, 300) == nullptr,
				L"Testing where there is no image");
		}

		TEST_METHOD(TestCAquariumEmptyTest)
		{
			CAquarium aquarium;

			//Assert::IsTrue(aquarium.HitTest(item.GetX(), item.GetY()) == nullptr,
			//	L"Testing empty aquarium");
		}
	};
}
