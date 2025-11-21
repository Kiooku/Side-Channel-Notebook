#include "rsaTest.h"

int coeffsP1[] = {1, 0, 1, 1, 0, 1, 1};
int coeffsP2[] = {0, 1, 0, 1, 0, 0, 1};
int coeffsP3[] = {1, 0, 4};
int coeffsP4[] = {1, 2, 0, 1};

void test_rsa_encryption(void) {
  int m = 35411;
  int e = 65537; // 2^16 + 1
  int p = 0;
  int q = 0;
  int N = p * q;
  int d = 0;
  RSA current_rsa = {p, q, N, e, d};


      int p;
    int q;
    int N;
    int e;
    int d;


  int res = rsa_encryption(m, current_rsa);

  CU_ASSERT_TRUE(res == 0);
}

void test_rsa_decryption(void) {

}