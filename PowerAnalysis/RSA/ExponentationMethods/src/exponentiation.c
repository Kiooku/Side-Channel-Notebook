#include "exponentiation.h"

// TODO compile without compiler optimization

void  left_to_right_square_and_multiply(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t a;
    mpz_init_set_ui(a, 1);

    for (int i = 0; i < k; i++) {
        mpz_mul(a, a, a);
        mpz_mod(a, a, n);
        if (d[i] == 1) {
            mpz_mul(a, a, m);
            mpz_mod(a, a, n);
        }
    }

    mpz_init_set(res, a);
}

void right_to_left_square_and_multiply(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t a, b;
    mpz_init_set_ui(a, 1);
    mpz_init_set(b, m);

    for (int i = k-1; i >= 0; i--) {
        if (d[i] == 1) {
            mpz_mul(a, a, b);
            mpz_mod(a, a, n);
        }
        mpz_mul(b, b, b);
        mpz_mod(b, b, n);
    }

    mpz_init_set(res, a);
}

// int* get_naf_representation(mpz_t d);
// mpz_t signed_digit_exponentiation(mpz_t m, mpz_t n, int* d, int k);

void left_to_right_square_and_multiply_always(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t a, b;
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(b, 1); // Trash

    for (int i = 0; i < k; i++) {
        mpz_mul(a, a, a);
        mpz_mod(a, a, n);
        if (d[i] == 1) {
            mpz_mul(a, a, m);
            mpz_mod(a, a, n);
        } else {
            mpz_mul(b, a, m);
            mpz_mod(b, b, n);
        }
    }

    mpz_init_set(res, a);
}

void left_to_right_square_and_multiply_always_v2(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t r[2]; // r0, r1
    mpz_init_set_ui(r[0], 1);
    mpz_init_set_ui(r[1], 1);

    for (int i = 0; i < k; i++) {
        mpz_mul(r[0], r[0], r[0]);
        mpz_mod(r[0], r[0], n);

        mpz_mul(r[1-d[i]], r[0], m);
        mpz_mod(r[1-d[i]], r[1-d[i]], n);
    }

    mpz_init_set(res, r[0]);
}

void right_to_left_square_and_multiply_always(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t a, b, c;
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(b, 1);
    mpz_init_set(c, m);

    for (int i = k-1; i >= 0; i--) {
        if (d[i] == 1) {
            mpz_mul(a, a, c);
            mpz_mod(a, a, n);
        } else {
            mpz_mul(b, b, c);
            mpz_mul(b, b, n);
        }
        mpz_mul(c, c, c);
        mpz_mod(c, c, n);
    }

    mpz_init_set(res, a);
}

void right_to_left_square_and_multiply_always_v2(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t r[2];
    mpz_init_set_ui(r[0], 1);
    mpz_init_set_ui(r[1], 1);
    mpz_t r2;
    mpz_init_set(r2, m);

    for (int i = k-1; i >= 0; i--) {
        mpz_mul(r[1-d[i]], r[1-d[i]], r2);
        mpz_mod(r[1-d[i]], r[1-d[i]], n);
        
        mpz_mul(r2, r2, r2);
        mpz_mod(r2, r2, n);
    }

    mpz_init_set(res, r[0]);
}

void montgomery_ladder(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t r[2];
    mpz_init_set_ui(r[0], 1);
    mpz_init_set(r[1], m);

    for (int i = 0; i < k; i++) {
        mpz_mul(r[1-d[i]], r[0], r[1]);
        mpz_mod(r[1-d[i]], r[1-d[i]], n);
        
        mpz_mul(r[d[i]], r[d[i]], r[d[i]]);
        mpz_mod(r[d[i]], r[d[i]], n);
    }

    mpz_init_set(res, r[0]);
}

void joye_ladder(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t r[2];
    mpz_init_set_ui(r[0], 1);
    mpz_init_set(r[1], m);

    for (int i = k-1; i >= 0; i--) {
        mpz_mul(r[1-d[i]], r[1-d[i]], r[1-d[i]]);
        mpz_mul(r[1-d[i]], r[1-d[i]], r[d[i]]);
        mpz_mod(r[1-d[i]], r[1-d[i]], n);
    }

    mpz_init_set(res, r[0]);
}

void multiply_always_atomic(mpz_t res, mpz_t m, mpz_t n, int* d, int k) {
    mpz_t r[2];
    mpz_init_set_ui(r[0], 1);
    mpz_init_set(r[1], m); 
    int i = 0;
    int t = 0;

    while (i < k) {
        mpz_mul(r[0], r[0], r[t]);
        mpz_mod(r[0], r[0], n);
        t ^= d[i];
        i = i + 1 - t;
    }

    mpz_init_set(res, r[0]);
}


// mpz_t left_to_right_two_t_ary_square_and_multiply(mpz_t m, mpz_t n, int* d, int k);