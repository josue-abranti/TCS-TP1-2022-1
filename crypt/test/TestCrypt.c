
#include "../src/crypt.h"
#include "../../src/unity.h"
#include "../../extras/fixture/src/unity_fixture.h"
#include <string.h>

struct element {
  unsigned int key[8];
  unsigned int input[4];
  int type;
  int enc_dec;
  unsigned int output[4];
};

struct element arrayElements[48];

TEST_GROUP(Crypt);

TEST_SETUP(Crypt)
{
  //struct element  temp0 = {atoi("abcdefg"), atoi("hijk"), 3, 1, NULL};
  //arrayElements[0] = temp0;
  /*
  struct element  temp1 = {(uint32_t *)4, (uint32_t *)"ASFSABassagASFA", 1, 0, (uint32_t *)"DEFG"};
  arrayElements[1] = temp1;
  struct element  temp2 = {(uint32_t *)4, (uint32_t *)"I@#%", 2, 0, (uint32_t *)"I@#%"};
  arrayElements[2] = temp2;
  struct element  temp3 = {(uint32_t *)4, (uint32_t *)"TESte$&*(", 3, 0, (uint32_t *)"TEST"};
  arrayElements[3] = temp3;
  struct element  temp4 = {(uint32_t *)4, (uint32_t *)"XUXUzinho123", 4, 0, (uint32_t *)"XUXU"};
  arrayElements[4] = temp4;
  struct element  temp5 = {(uint32_t *)4, (uint32_t *)"A123_asf(-", 5, 0, (uint32_t *)"A123"};
  arrayElements[5] = temp5;
  struct element  temp6 = {(uint32_t *)4, (uint32_t *)"12341001001", 6, 0, (uint32_t *)"1234"};
  arrayElements[6] = temp6;
  struct element  temp7 = {(uint32_t *)4, (uint32_t *)"*&#%&&|]", -1, 0, (uint32_t *)"*&#%"};
  arrayElements[7] = temp7;
  struct element  temp8 = {(uint32_t *)4, (uint32_t *)"", 0, 1, (uint32_t *)"ABCD"};
  arrayElements[8] = temp8;
  struct element  temp9 = {(uint32_t *)4, (uint32_t *)"ASFSABassagASFA", 1, 1, (uint32_t *)"DEFG"};
  arrayElements[9] = temp9;
  struct element  temp10 = {(uint32_t *)4, (uint32_t *)"I@#%", 2, 1, (uint32_t *)"I@#%"};
  arrayElements[10] = temp10;
  struct element  temp11 = {(uint32_t *)4, (uint32_t *)"TESte$&*(", 3, 1, (uint32_t *)"TEST"};
  arrayElements[11] = temp11;
  struct element  temp12 = {(uint32_t *)4, (uint32_t *)"XUXUzinho123", 4, 1, (uint32_t *)"XUXU"};
  arrayElements[12] = temp12;
  struct element  temp13 = {(uint32_t *)4, (uint32_t *)"A123_asf(-", 5, 1, (uint32_t *)"A123"};
  arrayElements[13] = temp13;
  struct element  temp14 = {(uint32_t *)4, (uint32_t *)"12341001001", 6, 1, (uint32_t *)"1234"};
  arrayElements[14] = temp14;
  struct element  temp15 = {(uint32_t *)4, (uint32_t *)"*&#%&&|]", -1, 1, (uint32_t *)"*&#%"};
  arrayElements[15] = temp15;
  struct element  temp16 = {(uint32_t *)6, (uint32_t *)"", 0, 0, (uint32_t *)"ABCDDD"};
  arrayElements[16] = temp16;
  struct element  temp17 = {(uint32_t *)6, (uint32_t *)"ASFSABassagASFA1010", 1, 0, (uint32_t *)"DEFG!$"};
  arrayElements[17] = temp17;
  struct element  temp18 = {(uint32_t *)6, (uint32_t *)"I123#%%%#*&", 2, 0, (uint32_t *)"I@#%__"};
  arrayElements[18] = temp18;
  struct element  temp19 = {(uint32_t *)6, (uint32_t *)"TESte$&*(##&#", 3, 0, (uint32_t *)"TEST12"};
  arrayElements[19] = temp19;
  struct element  temp20 = {(uint32_t *)6, (uint32_t *)"XUXUzinho123#$##", 4, 0, (uint32_t *)"XUXU"};
  arrayElements[20] = temp20;
  struct element  temp21 = {(uint32_t *)6, (uint32_t *)"A123_asf(-AaBc#$", 5, 0, (uint32_t *)"A12390"};
  arrayElements[21] = temp21;
  struct element  temp22 = {(uint32_t *)6, (uint32_t *)"1234100100110100000", 6, 0, (uint32_t *)"123450"};
  arrayElements[22] = temp22;
  struct element  temp23 = {(uint32_t *)6, (uint32_t *)"*&#%&&|]}{[]))", -1, 0, (uint32_t *)"*&#%$("};
  arrayElements[23] = temp23;
  struct element  temp24 = {(uint32_t *)6, (uint32_t *)"", 0, 1, (uint32_t *)"ABCDDD"};
  arrayElements[24] = temp24;
  struct element  temp25 = {(uint32_t *)6, (uint32_t *)"ASFSABassagASFA1010", 1, 1, (uint32_t *)"DEFG!$"};
  arrayElements[25] = temp25;
  struct element  temp26 = {(uint32_t *)6, (uint32_t *)"I123#%%%#*&", 2, 1, (uint32_t *)"I@#%__"};
  arrayElements[26] = temp26;
  struct element  temp27 = {(uint32_t *)6, (uint32_t *)"TESte$&*(##&#", 3, 1, (uint32_t *)"TEST12"};
  arrayElements[27] = temp27;
  struct element  temp28 = {(uint32_t *)6, (uint32_t *)"XUXUzinho123#$##", 4, 1, (uint32_t *)"XUXU"};
  arrayElements[28] = temp28;
  struct element  temp29 = {(uint32_t *)6, (uint32_t *)"A123_asf(-AaBc#$", 5, 1, (uint32_t *)"A12390"};
  arrayElements[29] = temp29;
  struct element  temp30 = {(uint32_t *)6, (uint32_t *)"1234100100110100000", 6, 1, (uint32_t *)"123450"};
  arrayElements[30] = temp30;
  struct element  temp31 = {(uint32_t *)6, (uint32_t *)"*&#%&&|]}{[]))", -1, 1, (uint32_t *)"*&#%$("};
  arrayElements[31] = temp31;
  struct element  temp32 = {(uint32_t *)8, (uint32_t *)"", 0, 0, (uint32_t *)"ABCDDDEF"};
  arrayElements[32] = temp32;
  struct element  temp33 = {(uint32_t *)8, (uint32_t *)"ASFSABassagASFA1010911", 1, 0, (uint32_t *)"DEFG!$%#"};
  arrayElements[33] = temp33;
  struct element  temp34 = {(uint32_t *)8, (uint32_t *)"I123#%%%#*&911", 2, 0, (uint32_t *)"I@#%__!#"};
  arrayElements[34] = temp34;
  struct element  temp35 = {(uint32_t *)8, (uint32_t *)"TESte$&*(##&#911", 3, 0, (uint32_t *)"TEST1200"};
  arrayElements[35] = temp35;
  struct element  temp36 = {(uint32_t *)8, (uint32_t *)"XUXUzinho123#$##SoS911", 4, 0, (uint32_t *)"XUXU"};
  arrayElements[36] = temp36;
  struct element  temp37 = {(uint32_t *)8, (uint32_t *)"A123_asf(-AaBc#$Sos911", 5, 0, (uint32_t *)"A1239000"};
  arrayElements[37] = temp37;
  struct element  temp38 = {(uint32_t *)8, (uint32_t *)"123410010011099000", 6, 0, (uint32_t *)"12345023"};
  arrayElements[38] = temp38;
  struct element  temp39 = {(uint32_t *)8, (uint32_t *)"*&#%&&|]}{[]))!!!!&&&&", -1, 0, (uint32_t *)"*&#%$()!"};
  arrayElements[39] = temp39;
  struct element  temp40 = {(uint32_t *)8, (uint32_t *)"ABCDDDEFaabbccddeeff", 0, 1, (uint32_t *)"ABCDDDEF"};
  arrayElements[40] = temp40;
  struct element  temp41 = {(uint32_t *)8, (uint32_t *)"DEFG!$%#defgh12345", 1, 1, (uint32_t *)"DEFG!$%#"};
  arrayElements[41] = temp41;
  struct element  temp42 = {(uint32_t *)8, (uint32_t *)"I@#%__!#())!Assa><", 2, 1, (uint32_t *)"I@#%__!#"};
  arrayElements[42] = temp42;
  struct element  temp43 = {(uint32_t *)8, (uint32_t *)"TEST1200xix_iaIA", 3, 1, (uint32_t *)"TEST1200"};
  arrayElements[43] = temp43;
  struct element  temp44 = {(uint32_t *)8, (uint32_t *)"CONFIDENCIAL_g14", 4, 1, (uint32_t *)"XUXU"};
  arrayElements[44] = temp44;
  struct element  temp45 = {(uint32_t *)8, (uint32_t *)"A1239000abecedefg", 5, 1, (uint32_t *)"A1239000"};
  arrayElements[45] = temp45;
  struct element  temp46 = {(uint32_t *)8, (uint32_t *)"1234502399", 6, 1, (uint32_t *)"12345023"};
  arrayElements[46] = temp46;
  struct element  temp47 = {(uint32_t *)8, (uint32_t *)"*&#%$()!!!<<>>&&&", -1, 1, (uint32_t *)"*&#%$()!"};
  arrayElements[47] = temp47;
  */
}

TEST_TEAR_DOWN(Crypt)
{
}

TEST(Crypt, TestCrypt1)
{
  unsigned int key[8] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
  };

  unsigned int input[4] = {'a', 'b', 'c', 'd'};

  int type = 3;

  int enc_dec = 1;

  unsigned int output[4];

  int result = crypt(key, input, type, enc_dec, output);//arrayElements[0].key, arrayElements[0].input, arrayElements[0].type, arrayElements[0].enc_dec, arrayElements[0].output);
  printf("Resultado teste: %d", result);
  TEST_ASSERT_EQUAL(0, result);
}


/*
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
*/