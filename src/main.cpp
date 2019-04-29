///-------------------------------------------------------------------------------------------------
/// 
/// \file main.cpp
/// \brief main file.
/// \author Thibaut Monseigne.
/// \version 1.0.
/// \date 29/04/2019.
/// \copyright <a href="https://choosealicense.com/licenses/agpl-3.0/">GNU Affero General Public License v3.0</a>.
/// 
///-------------------------------------------------------------------------------------------------

#include "gtest/gtest.h"

#include "CHelloClass.hpp"

using namespace std;

//---------------------------------------------------------------------------------------------------
class Test_HelloClass : public testing::Test
{
protected:
	CHelloClass obj;

	void SetUp() override { obj.a = 10; }
};
//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------
TEST_F(Test_HelloClass, HelloTest)
{
	cout << "Value is : " << obj.a << endl;
	EXPECT_TRUE(obj.a == 10) << "Error a != 10 : a = " << obj.a << std::endl;
	obj.add(10);
	cout << "Value is : " << obj.a << endl;
	EXPECT_TRUE(obj.a == 20) << "Error a != 20 : a = " << obj.a << std::endl;
	obj.sub(5);
	cout << "Value is : " << obj.a << endl;
	EXPECT_TRUE(obj.a == 15) << "Error a != 15 : a = " << obj.a << std::endl;
}
//---------------------------------------------------------------------------------------------------

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}