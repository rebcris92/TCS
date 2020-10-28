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
  char vetor[20] = "seila\n";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,0);
}

TEST(Identifier, Test2) //Test if the function doesn't returns null
{
  char vetor[20] = "4ola\n";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}

TEST(Identifier, Test3) //Test if the function doesn't returns null
{
  char vetor[20] = "batata\n";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}

TEST(Identifier, Test4) //Test if the function doesn't returns null
{
  char vetor[20] = "jaa$\n";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,1);
}