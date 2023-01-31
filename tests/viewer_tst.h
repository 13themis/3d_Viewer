#ifndef SRC_TESTS_SRC_CALC_H_
#define SRC_TESTS_SRC_CALC_H_

#include <check.h>

#include "../parser_.h"
Suite *parser_ste(void);

void run_tests(void);
void run_testcase(Suite *tc);

#endif  // SRC_TESTS_SRC_CALC_H_
