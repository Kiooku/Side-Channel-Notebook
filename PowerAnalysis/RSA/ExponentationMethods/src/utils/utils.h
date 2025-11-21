#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include "gmp.h"

typedef struct {
    int* bin;
    int length;
} BIN_ARR;

BIN_ARR int_to_bin(int x);
BIN_ARR mpz_to_bin(mpz_t x);

#endif //UTILS_H