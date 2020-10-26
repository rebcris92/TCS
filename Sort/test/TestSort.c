#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

TEST(Sort, Test1) //Test if the function doesn't returns null
{
  int vetor[6] = {3,8,2,9,0,2};
  sort(vetor,6);
  TEST_ASSERT_NOT_NULL(vetor);
}

TEST(Sort, Test2) //Test if it works
{
  int vetor[6] = {3,8,2,9,0,-2};
  int corrected_vetor[6] = {-2,0,2,3,8,9};
  sort(vetor,6);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vetor,corrected_vetor,6);
}

TEST(Sort, Test3) //Test only negative numbers
{
  int vetor[6] = {-500,-23,-56,-19000,-1,0};
  int corrected_vetor[6] = {-19000,-500,-56,-23,-1,0};
  sort(vetor,6);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vetor,corrected_vetor,6);
}

TEST(Sort, Test4) //Test MAX and MIN
{
  int vetor[3] = {2147483647,-2147483648,0,};
  int corrected_vetor[3] = {-2147483648,0,2147483647};
  sort(vetor,3);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vetor,corrected_vetor,3);
}

TEST(Sort, Test5) // test multiple same numbers
{
  int vetor[7]= {5,1,0,1,0,0,0};
  int corrected_vetor[7] = {0,0,0,0,1,1,5};
  sort(vetor,7);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vetor,corrected_vetor,7);
}

TEST(Sort, Test6) // Sorting only part of the vector
{
  int vetor[7]= {5,1,0,1,0,-3,9};
  int corrected_vetor[7] = {0,1,5,1,0,-3,9};
  sort(vetor,3);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vetor,corrected_vetor,7);
}