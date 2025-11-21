#include "RSA.h"

mpz_t rsa_encryption(mpz_t m, PublicKey params) {
    return ((int) pow((double) m, (double) params.e)) % params.N;
}


mpz_t rsa_decryption(mpz_t c, RSA params, void (*exp_func)(mpz_t, mpz_t, mpz_t, int*, int)) {
    return (*exp_func)(c, params.pk.N, params.sk.d);
}

mpz_t rsa_crt_decryption(mpz_t c, RSA_CRT params, void (*exp_func)(mpz_t, mpz_t, mpz_t, int*, int)) {
    int mp = ((int) pow((double) c, (double) params.sk.dp)) % params.sk.p;
    int mq = ((int) pow((double) c, (double) params.sk.dq)) % params.sk.q;
    return mp + params.sk.p * ( ((mq - mp) * params.sk.ip) % params.sk.q);
}