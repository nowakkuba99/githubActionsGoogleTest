/* --- Includes --- */
#include <gtest/gtest.h>
#include <iostream>
/* --- User includes --- */
#include "../inc/testClass.hpp"

/* --- Main function --- */
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<TestClass::getLogo() << std::endl;
  std::cout<<"Start of tests ...\n";
  return RUN_ALL_TESTS();
}

/* 
--------------------------------------------------------------
Sample class tests
--------------------------------------------------------------
*/
// Check reading one int
TEST(AddingTest, SimpleIntAdd)
{
  int a = 2, b = 2;
  auto retVal = TestClass::functionToTest(a,b);
  EXPECT_EQ(retVal,4);  // 2+2 = 4
}