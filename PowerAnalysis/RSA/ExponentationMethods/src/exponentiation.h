#ifndef EXPONENTIATION_H
#define EXPONENTIATION_H

#include "utils/Logger.h"
#include "gmp.h"

void left_to_right_square_and_multiply(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void right_to_left_square_and_multiply(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
// mpz_t* get_naf_representation(mpz_t d);
// mpz_t signed_digit_exponentiation(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void left_to_right_square_and_multiply_always(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void left_to_right_square_and_multiply_always_v2(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void right_to_left_square_and_multiply_always(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void right_to_left_square_and_multiply_always_v2(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void montgomery_ladder(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void joye_ladder(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
void multiply_always_atomic(mpz_t res, mpz_t m, mpz_t n, int* d, int k);
// mpz_t left_to_right_two_t_ary_square_and_multiply(mpz_t res, mpz_t m, mpz_t n, int* d, int k);


#endif //EXPONENTIATION_H