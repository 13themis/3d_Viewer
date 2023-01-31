#include <stdlib.h>

#include "../affine_transfomation_.h"
#include "../parser_.h"
#include "viewer_tst.h"

START_TEST(parser_test1) {
  int status = 0;
  DynamicArrayVex vertexes;
  DynamicArrayTrg faces;
  DynamicArrayLine lines;
  status = init_v(&vertexes);
  ck_assert_int_eq(0, status);

  status = init_t(&faces);
  ck_assert_int_eq(0, status);

  status = init_line(&lines);
  ck_assert_int_eq(0, status);

  status = parser("./models/bunny.obj", &vertexes, &faces, &lines);
  ck_assert_int_eq(0, status);

  translation(&vertexes, 2, 2, 2);
  rotation(&vertexes, 2, 2, 2);
  scaling(&vertexes, 2, 2, 2);

  remove_line(&lines);
  remove_v(&vertexes);
  remove_t(&faces);
}
END_TEST

Suite* parser_ste(void) {
  Suite* s = suite_create("parser");
  TCase* tc = tcase_create("Core");
  tcase_add_test(tc, parser_test1);
  suite_add_tcase(s, tc);

  return s;
}
