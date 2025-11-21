#include "utils.h"

// https://www.geeksforgeeks.org/dsa/program-decimal-binary-conversion/
BIN_ARR int_to_bin(int x) {
    int *temp, *res;
    int bit, index;
    temp = (int *)malloc(8 * sizeof(int));

    index = 0;
    while (x > 0) {
        bit = x % 2;
        temp[index++] = bit;
        x /= 2;
    }

    res = (int *)malloc(index);
    for (int i = 0; i < index; i++) {
        res[i] = temp[index-(1+i)];
    }

    BIN_ARR bin_arr = {res, index};
    return bin_arr;
}

BIN_ARR mpz_to_bin(mpz_t x) {
    size_t nbits = mpz_sizeinbase(x, 2);
    int *res = (int *)malloc(nbits * sizeof(int));

    for (size_t i = 0; i < nbits; i++) {
        res[i] = mpz_tstbit(x, nbits - 1 - i);
    }

    BIN_ARR bin_arr = {res, (int)nbits};
    return bin_arr;
}