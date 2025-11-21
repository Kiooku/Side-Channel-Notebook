//#include "./utils/Logger.h"
//#include "RSA.h"
//#include "exponentation.h"
#include "./utils/utils.h"
#include "exponentiation.h"
#include <stdio.h>
#include "utils/Logger.h"
#include "gmp.h"

int main() {
    mpz_t test, m, d, n, res, res_1, res_2, res_3, res_4, res_5, res_6, res_7, res_8, res_9;

    mpz_init_set_ui(test, 113);
    BIN_ARR bin_value = mpz_to_bin(test);

    gmp_printf("Length bin(%Zd): %d\n", test, bin_value.length);
    for (int i = 0; i < bin_value.length; i++) {
        printf("%d", bin_value.bin[i]);
    }
    printf("\n");

    mpz_init_set_ui(m, 35);
    mpz_init_set_ui(d, 3441);
    mpz_init_set_ui(n, 34511);
    mpz_init_set_ui(res, 6163);
    BIN_ARR d_bin = mpz_to_bin(d);

    gmp_printf("Length bin(%Zd): %d\n", d, d_bin.length);
    for (int i = 0; i < d_bin.length; i++) {
        printf("%d", d_bin.bin[i]);
    }
    printf("\n");

    left_to_right_square_and_multiply(res_1, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result left-to-right square and multiply (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_1);

    right_to_left_square_and_multiply(res_2, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result right-to-left square and multiply (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_2);

    left_to_right_square_and_multiply_always(res_3, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result left-to-right square and multiply always (version 1) (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_3);

    left_to_right_square_and_multiply_always_v2(res_4, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result left-to-right square and multiply always (version 2) (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_4);

    right_to_left_square_and_multiply_always(res_5, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result right-to-left square and multiply always (version 1) (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_5);

    right_to_left_square_and_multiply_always_v2(res_6, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result right-to-left square and multiply always (version 2) (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_6);

    montgomery_ladder(res_7, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result Montgomery ladder (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_7);

    joye_ladder(res_8, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result Joye ladder (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_8);

    multiply_always_atomic(res_9, m, n, d_bin.bin, d_bin.length);
    gmp_printf("Result multiply always atomic (m: %Zd; d: %Zd; n: %Zd): %Zd\n", m, d, n, res_9);

    return 0;
}

// gcc -o main main.o exponentiation.o utils.o -I$(brew --prefix gmp)/include -L$(brew --prefix gmp)/lib -lgmp