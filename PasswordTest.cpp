/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, space_in_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, space_first_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters(" ZZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("  ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, two_other_char_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("..ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, dot_between_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z.Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, different_cases_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, two_different_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, upper_first_different_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, two_same_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, two_same_case_with_space)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a a");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, longer_password_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("abcDeFGHiJKL");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, longer_password_case_false)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aabieksjao");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, other_characters_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a#ajdleJJJJ))*");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, no_caps_other_characters_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a#ajdie)*");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, empty_password_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_true_case)
{
	Password my_password;
	my_password.set("blueCanoe");
	int actual = my_password.authenticate("blueCanoe");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, set_and_auth_false_case1)
{
	Password my_password;
	my_password.set("bluecanoe");
	int actual = my_password.authenticate("bluecanoe");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_false_case2)
{
	Password my_password;
	my_password.set("blue");
	int actual = my_password.authenticate("blue");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_false_case3)
{
	Password my_password;
	my_password.set("Blue");
	int actual = my_password.authenticate("Blue");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_false_case4)
{
	Password my_password;
	my_password.set("BlueCanoe");
	my_password.set("purpleCanoe");
	my_password.set("BlueCanoe");
	int actual = my_password.authenticate("BlueCanoe");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_false_case5)
{
	Password my_password;
	my_password.set("BBBBlueCanoe");
	int actual = my_password.authenticate("BBBBlueCanoe");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_false_case6)
{
	Password my_password;
	my_password.set("bbbbluecanoe");
	int actual = my_password.authenticate("bbbblueCanoe");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_and_auth_false_case7)
{
	Password my_password;
	my_password.set("bbblueCanoe");
	int actual = my_password.authenticate("bbblueCanoe");
	ASSERT_EQ(true, actual);
}


TEST(PasswordTest, constructor_auth_case_true)
{
	Password my_password;
	int actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, constructor_auth_case_false)
{
	Password my_password;
	int actual = my_password.authenticate("NOPE");
	ASSERT_EQ(false, actual);
}