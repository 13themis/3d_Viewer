#ifndef _SRC_DYNAMIC_ARRAY_H_
#define _SRC_DYNAMIC_ARRAY_H_
#include "vertex_.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct DynamicArrayVex {
  Vertex* arr;
  unsigned long int over_mem;
  unsigned long int total_mem;
} DynamicArrayVex;

typedef struct DynamicArrayTrg {
  Triangle* arr;
  unsigned long int over_mem;
  unsigned long int total_mem;
} DynamicArrayTrg;

typedef struct DynamicArrayLine {
  Line* arr;
  unsigned long int over_mem;
  unsigned long int total_mem;
} DynamicArrayLine;

enum status { OK, MEM_FAIL };

int init_v(DynamicArrayVex* dym_arr);
int add_v(DynamicArrayVex* dym_arr, Vertex vex);
void remove_v(DynamicArrayVex* dym_arr);

int init_t(DynamicArrayTrg* dym_arr);
int add_t(DynamicArrayTrg* dym_arr, Triangle trg);
void remove_t(DynamicArrayTrg* dym_arr);

int init_line(DynamicArrayLine* dym_arr);
int add_line(DynamicArrayLine* dym_arr, Line line);
void remove_line(DynamicArrayLine* dym_arr);

#ifdef __cplusplus
}
#endif

#endif  //_SRC_DYNAMIC_ARRAY_H_
