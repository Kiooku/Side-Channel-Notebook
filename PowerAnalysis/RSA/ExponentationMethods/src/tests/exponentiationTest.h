#ifndef EXPONENTIATIONTEST_H
#define EXPONENTIATIONTEST_H

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "../exponentation.h"

void test_left_to_right_square_and_multiply(void);
void test_right_to_left_square_and_multiply(void);
void test_left_to_right_square_and_multiply_always(void);
void test_left_to_right_square_and_multiply_always_v2(void);
void test_right_to_left_square_and_multiply_always(void);
void test_right_to_left_square_and_multiply_always_v2(void);
void test_montgomery_ladder(void);
void test_joye_ladder(void);
void test_multiply_always_atomic(void);

#endif //EXPONENTIATIONTEST_H
