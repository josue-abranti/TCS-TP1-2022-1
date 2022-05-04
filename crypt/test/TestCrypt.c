
#include "../src/crypt.h"
#include "../../src/unity.h"
#include "../../extras/fixture/src/unity_fixture.h"

int32_t* key;
uint32_t* input, output;
uint8_t type, enc_dec;

TEST_GROUP(Crypt);

TEST_SETUP(Crypt)
{
}

TEST_TEAR_DOWN(Crypt)
{
}

TEST(Crypt, TestCrypt1)
{
  key=4;
  input="ABCD";
  type=0;
  enc_dec=0;
  output="ABCD";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt2)
{
  key = 1;
  input = "ABC";
  output = 10;
  type = 0;
  enc_dec = 0;

  TEST_ASSERT_EQUAL(1, crypt(key, input, type, enc_dec, output));
}