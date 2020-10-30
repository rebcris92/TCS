#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, Test1) //Test if the function doesn't returns null
{
  char vetor[20] = "seila";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,0);
}

TEST(Identifier, Test2) //Test if the function doesn't returns null
{
  char vetor[20] = "asd89";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,0);
}

TEST(Identifier, Test3) //Test if the function doesn't returns null
{
  char vetor[20] = "774ad";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}

TEST(Identifier, Test4) //Test if the function doesn't returns null
{
  char vetor[20] = "asdadd";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}

TEST(Identifier, Test5) //Test if the function doesn't returns null
{
  char vetor[20] = "jaa$";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}

TEST(Identifier, Test6) //Test if the function doesn't returns null
{
  char vetor[20] = "d";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,0);
}

TEST(Identifier, Test7) //Test if the function doesn't returns null
{
  char vetor[20] = "!@##$@#";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}

TEST(Identifier, Test8) //Test if the function doesn't returns null
{
  char vetor[20] = "afnjqhfkqfqbfqfo";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}