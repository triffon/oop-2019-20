#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace std;

//Since floating point numbers have fixed precision there are special testing functions for them
TEST(DoubleDemo,DoubleWithDefaultRounding){
	ASSERT_FLOAT_EQ(0.33333333,0.33333333);
}
TEST(DoubleDemo,DoubleWithCustomRounding){
	//0.1 is the absolute error which sholdn't be exceed for the test to pass
	ASSERT_NEAR(0.33333333,0.33333333,0.1);
}
//There are special functions for checking the equality of raw strings ( char * )
TEST(StrinDemo,CompareTwoStrings){
	char * a = "example";
	char * b = "example";
	//Normal ASSERT_EQ on pointers will just compare addresses while STREQ will check the actual contents of the strings
	ASSERT_STREQ(a,b);
}
//There are assert and expect type of tests
//Assert stops the current function on the first failed assert
//Useful when the program shouldn't work if the assert fails
//Expect continues even if there is a failed expect
//Useful for finding more bugs at once
TEST(AssertVsExpect,assertStopsFurtherTests){
	//verifies that the condition is true
	ASSERT_TRUE(true);
	//verifies that the condition is false 
	ASSERT_FALSE(false);
	//performs == 
	//ASSERT_EQ(actual,expected)
	//when such test fails it tells you the values of actual and expected
	//thus it is better than ASSERT_TRUE for comparing values
	//ASSERT_EQ(a,e) is better than ASSERT_TRUE(a==e) 
	ASSERT_EQ(2,2);
	//performs !=
	ASSERT_NE(2,3);
	
	//this assert is a fail and the function terminates thus this test doesn't try the next two asserts
	//ASSERT_EQ(2,100);
	
	//performs <
	ASSERT_LT(2,3);
	//performs >
	ASSERT_GT(3,2);
}
TEST(AssertVsExpect,expectContinuesEvenAfterFail){
	//verifies that the condition is true
	EXPECT_TRUE(true);
	//verifies that the condition is false 
	EXPECT_FALSE(false);
	//performs == 
	//EXPECT_EQ(actual,expected)
	//when such test fails it tells you the values of actual and expected
	//thus it is better than EXPECT_TRUE for comparing values
	//EXPECT_EQ(a,e) is better than EXPECT_TRUE(a==e) 
	EXPECT_EQ(2,2);
	//performs !=
	EXPECT_NE(2,3);
	
	//this EXPECT is a fail but further expects are performed and we can see their mistakes/bugs
	//EXPECT_EQ(2,100);

	//performs <
	EXPECT_LT(2,3);
	//performs >
	EXPECT_GT(3,2);
}
int main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
