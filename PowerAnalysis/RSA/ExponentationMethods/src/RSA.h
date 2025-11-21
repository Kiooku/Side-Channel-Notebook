#ifndef RSA_H
#define RSA_H

#include <stdio.h>
#include <math.h>
#include "./utils/Logger.h"
#include "./exponentation.h"
#include "gmp.h"

typedef struct  {
    mpz_t N;
    mpz_t e;
} PublicKey;

typedef struct {
    mpz_t p;
    mpz_t q;
    mpz_t d;
} PrivateKey;

typedef struct {
    mpz_t p;
    mpz_t q;
    mpz_t dp;
    mpz_t dq;
    mpz_t ip;
} PrivateKeyCRT;

typedef struct {
    PublicKey pk;
    PrivateKey sk;
} RSA;

typedef struct {
    PublicKey pk;
    PrivateKeyCRT sk;
} RSA_CRT;

// https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c

mpz_t rsa_encryption(mpz_t m, PublicKey params);
mpz_t rsa_decryption(mpz_t c, RSA params, void (*exp_func)(mpz_t, mpz_t, mpz_t, int*, int));
mpz_t rsa_crt_decryption(mpz_t c, RSA_CRT params, void (*exp_func)(mpz_t, mpz_t, mpz_t, int*, int));
/*
mpz_t rsa_decryption_exponent_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
mpz_t rsa_decryption_modulus_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
mpz_t rsa_decryption_message_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
mpz_t rsa_decryption_exponent_modulus_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
mpz_t rsa_decryption_exponent_message_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
mpz_t rsa_decryption_modulus_message_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
mpz_t rsa_decryption_exponent_modulus_message_blinding(mpz_t c, RSA params, mpz_t (*exp_func)(mpz_t, mpz_t, int*, int));
*/
#endif //RSA_H