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
  char vetor[20] = "VTF\n";
  int out;
  out = identifier(vetor);
  TEST_ASSERT_EQUAL_INT(out,0);
}

