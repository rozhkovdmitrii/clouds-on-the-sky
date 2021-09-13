#include <gtest/gtest.h>
#include "Sky.h"

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestCloudsCounter, LittleSkyPatch)
{
    ASSERT_EQ(0, Sky({"-"}).getCloudsCount());
}

TEST(TestCloudsCounter, CloudInCircle)
{
    ASSERT_EQ(2, Sky({"-wwwwwwww-----",
                      "-w------w-----",
                      "-w--w---w-----",
                      "-w------w-----",
                      "-wwwwwwww-----"}).getCloudsCount());
}

TEST(TestCloudsCounter, ManyClouds)
{
    ASSERT_EQ(5, Sky({"-wwwwwwww-----",
                      "-w------w---w-",
                      "-w--w---w-----",
                      "-w------w---w-",
                      "-wwwwwwww----w"}).getCloudsCount());
}



TEST(TestCloudsCounter, HugeCloudOnTheSky)
{
    ASSERT_EQ(1, Sky({"wwwwwwwwwwwwww",
                      "wwwwwwwwwwwwww",
                      "wwwwwwwwwwwwww",
                      "wwwwwwwwwwwwww",
                      "wwwwwwwwwwwwww"}).getCloudsCount());
}


