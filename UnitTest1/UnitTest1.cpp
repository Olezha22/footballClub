#include "pch.h"
#include "CppUnitTest.h"
#include "../footballClub/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSetPlayer)
        {
            int***** f5 = nullptr;
            size_t n5 = CreateArrayAtMemory<int>(nullptr, 2, 3, 4, 5, 6);
            vector<char> a5(n5);
            f5 = (int*****)a5.data();
            CreateArrayAtMemory<int>(f5, 2, 3, 4, 5, 6);

            FootballClub club(f5);


            for (size_t i = 0; i < 11; i++)
            {
                club.setPlayer(0, i, i + 1);
            }



            for (int i = 0; i < 11; i++)
            {
                Assert::AreEqual(i + 1, (int)f5[0][0][0][0][i]);
            }
            for (size_t i = 0; i < 11; i++)
            {
                club.setPlayer(1, i, i + 5);
            }


            for (int i = 0; i < 11; i++)
            {
                Assert::AreEqual(i + 5, f5[1][0][0][0][i]);
            }
        }
        TEST_METHOD(TestSetTrainer)
        {
            int***** f5 = nullptr;
            size_t n5 = CreateArrayAtMemory<int>(nullptr, 2, 3, 4, 5, 6);
            vector<char> a5(n5);
            f5 = (int*****)a5.data();
            CreateArrayAtMemory<int>(f5, 2, 3, 4, 5, 6);

            FootballClub club(f5);


            for (size_t i = 0; i < 11; i++)
            {
                club.setTrainer(0, i, i + 1, 0);
                club.setTrainer(1, i, i + 5, 1); 
            }


            for (int i = 0; i < 11; i++)
            {
                Assert::AreEqual(i + 1, f5[0][0][0][0][i]); 
                Assert::AreEqual(i + 5, f5[1][0][0][1][i]); 
            }
        }
    };
}
