
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
  input="";
  type=0;
  enc_dec=0;
  output="ABCD";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt2)
{
  key=4;
  input="ASFSABassagASFA";
  type=1;
  enc_dec=0;
  output="DEFG";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt3)
{
  key=4;
  input="I@#%";
  type=2;
  enc_dec=0;
  output="I@#%";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt4)
{
  key=4;
  input="TESte$&*(";
  type=3;
  enc_dec=0;
  output="TEST";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt5)
{
  key=4;
  input="XUXUzinho123";
  type=4;
  enc_dec=0;
  output="XUXU";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt6)
{
  key=4;
  input="A123_asf(-";
  type=5;
  enc_dec=0;
  output="A123";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt7)
{
  key=4;
  input="12341001001";
  type=6;
  enc_dec=0;
  output="1234";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt8)
{
  key=4;
  input="*&#%&&|]";
  type=-1;
  enc_dec=0;
  output="*&#%";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt9)
{
  key=4;
  input="";
  type=0;
  enc_dec=1;
  output="ABCD";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt10)
{
  key=4;
  input="ASFSABassagASFA";
  type=1;
  enc_dec=1;
  output="DEFG";
  
  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt11)
{
  key=4;
  input="I@#%";
  type=2;
  enc_dec=1;
  output="I@#%";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt12)
{
  key=4;
  input="TESte$&*(";
  type=3;
  enc_dec=1;
  output="TEST";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt13)
{
  key=4;
  input="XUXUzinho123";
  type=4;
  enc_dec=1;
  output="XUXU";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt14)
{
  key=4;
  input="A123_asf(-";
  type=5;
  enc_dec=1;
  output="A123";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt15)
{
  key=4;
  input="12341001001";
  type=6;
  enc_dec=1;
  output="1234";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt16)
{
  key=4;
  input="*&#%&&|]";
  type=-1;
  enc_dec=1;
  output="*&#%";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt17)
{
  key=6;
  input="";
  type=0;
  enc_dec=0;
  output="ABCDDD";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt18)
{
  key=6;
  input="ASFSABassagASFA1010";
  type=1;
  enc_dec=0;
  output="DEFG!$";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt19)
{
  key=6;
  input="I123#%%%#*&";
  type=2;
  enc_dec=0;
  output="I@#%__";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt20)
{
  key=6;
  input="TESte$&*(##&#";
  type=3;
  enc_dec=0;
  output="TEST12";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt21)
{
  key=6;
  input="XUXUzinho123#$##";
  type=4;
  enc_dec=0;
  output="XUXU";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt22)
{
  key=6;
  input="A123_asf(-AaBc#$";
  type=5;
  enc_dec=0;
  output="A12390";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt23)
{
  key=6;
  input="1234100100110100000";
  type=6;
  enc_dec=0;
  output="123450";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt24)
{
  key=6;
  input="*&#%&&|]}{[]))";
  type=-1;
  enc_dec=0;
  output="*&#%$(";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt25)
{
  key=6;
  input="";
  type=0;
  enc_dec=1;
  output="ABCDDD";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt26)
{
  key=6;
  input="ASFSABassagASFA1010";
  type=1;
  enc_dec=1;
  output="DEFG!$";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt27)
{
  key=6;
  input="I123#%%%#*&";
  type=2;
  enc_dec=1;
  output="I@#%__";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt28)
{
  key=6;
  input="TESte$&*(##&#";
  type=3;
  enc_dec=1;
  output="TEST12";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt29)
{
  key=6;
  input="XUXUzinho123#$##";
  type=4;
  enc_dec=1;
  output="XUXU";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt30)
{
  key=6;
  input="A123_asf(-AaBc#$";
  type=5;
  enc_dec=1;
  output="A12390";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt31)
{
  key=6;
  input="1234100100110100000";
  type=6;
  enc_dec=1;
  output="123450";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt32)
{
  key=6;
  input="*&#%&&|]}{[]))";
  type=-1;
  enc_dec=1;
  output="*&#%$(";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt33)
{
  key=8;
  input="";
  type=0;
  enc_dec=0;
  output="ABCDDDEF";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt34)
{
  key=8;
  input="ASFSABassagASFA1010911";
  type=1;
  enc_dec=0;
  output="DEFG!$%#";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt35)
{
  key=8;
  input="I123#%%%#*&911";
  type=2;
  enc_dec=0;
  output="I@#%__!#";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt36)
{
  key=8;
  input="TESte$&*(##&#911";
  type=3;
  enc_dec=0;
  output="TEST1200";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt37)
{
  key=8;
  input="XUXUzinho123#$##SoS911";
  type=4;
  enc_dec=0;
  output="XUXU";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt38)
{
  key=8;
  input="A123_asf(-AaBc#$Sos911";
  type=5;
  enc_dec=0;
  output="A1239000";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt39)
{
  key=8;
  input="123410010011099000";
  type=6;
  enc_dec=0;
  output="12345023";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt40)
{
  key=8;
  input="*&#%&&|]}{[]))!!!!&&&&";
  type=-1;
  enc_dec=0;
  output="*&#%$()!";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt41)
{
  key=8;
  input="ABCDDDEFaabbccddeeff";
  type=0;
  enc_dec=1;
  output="ABCDDDEF";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt42)
{
  key=8;
  input="DEFG!$%#defgh12345";
  type=1;
  enc_dec=1;
  output="DEFG!$%#";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt43)
{
  key=8;
  input="I@#%__!#())!Assa><";
  type=2;
  enc_dec=1;
  output="I@#%__!#";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt44)
{
  key=8;
  input="TEST1200xix_iaIA";
  type=3;
  enc_dec=1;
  output="TEST1200";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt45)
{
  key=8;
  input="CONFIDENCIAL_g14";
  type=4;
  enc_dec=1;
  output="XUXU";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt46)
{
  key=8;
  input="A1239000abecedefg";
  type=5;
  enc_dec=1;
  output="A1239000";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt47)
{
  key=8;
  input="1234502399";
  type=6;
  enc_dec=1;
  output="12345023";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}

TEST(Crypt, TestCrypt48)
{
  key=8;
  input="*&#%$()!!!<<>>&&&";
  type=-1;
  enc_dec=1;
  output="*&#%$()!";

  TEST_ASSERT_EQUAL(0, crypt(key, input, type, enc_dec, output));
}