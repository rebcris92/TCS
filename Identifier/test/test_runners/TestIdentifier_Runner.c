#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Identifier)
{
  RUN_TEST_CASE(Identifier, Test1);
  RUN_TEST_CASE(Identifier, Test2);
  RUN_TEST_CASE(Identifier, Test3);
  RUN_TEST_CASE(Identifier, Test4);
}
