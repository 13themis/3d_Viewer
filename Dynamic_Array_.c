#include "Dynamic_Array_.h"

#include <stdlib.h>

int init_v(DynamicArrayVex* dym_arr) {
  int status = OK;
  dym_arr->over_mem = 0;
  dym_arr->total_mem = 2;
  dym_arr->arr = (Vertex*)malloc(sizeof(Vertex) * 2);
  if (!dym_arr->arr) {
    status = MEM_FAIL;
  }
  return status;
}

int add_v(DynamicArrayVex* dym_arr, Vertex vex) {
  int status = OK;
  if (dym_arr->total_mem < (dym_arr->over_mem + 1)) {
    dym_arr->arr =
        (Vertex*)realloc(dym_arr->arr, sizeof(Vertex) * dym_arr->total_mem * 2);
    status = !dym_arr->arr;
    dym_arr->total_mem *= 2;
  }
  if (!status) {
    dym_arr->arr[dym_arr->over_mem] = vex;
    dym_arr->over_mem++;
  }
  return status;
}
void remove_v(DynamicArrayVex* dym_arr) {
  if (dym_arr->total_mem) {
    free(dym_arr->arr);
  }
  dym_arr->over_mem = 0;
  dym_arr->total_mem = 0;
}

int init_t(DynamicArrayTrg* dym_arr) {
  int status = OK;
  dym_arr->over_mem = 0;
  dym_arr->total_mem = 2;
  dym_arr->arr = (Triangle*)malloc(sizeof(Triangle) * 2);
  if (!dym_arr->arr) {
    status = MEM_FAIL;
  }
  return status;
}

int add_t(DynamicArrayTrg* dym_arr, Triangle trg) {
  int status = OK;
  if (dym_arr->total_mem < (dym_arr->over_mem + 1)) {
    dym_arr->arr = (Triangle*)realloc(
        dym_arr->arr, sizeof(Triangle) * dym_arr->total_mem * 2);
    status = !dym_arr->arr;
    dym_arr->total_mem *= 2;
  }
  if (!status) {
    dym_arr->arr[dym_arr->over_mem] = trg;
    dym_arr->over_mem++;
  }
  return status;
}

void remove_t(DynamicArrayTrg* dym_arr) {
  if (dym_arr->total_mem) {
    free(dym_arr->arr);
  }
  dym_arr->over_mem = 0;
  dym_arr->total_mem = 0;
}

int init_line(DynamicArrayLine* dym_arr) {
  int status = OK;
  dym_arr->over_mem = 0;
  dym_arr->total_mem = 2;
  dym_arr->arr = (Line*)malloc(sizeof(Line) * 2);
  if (!dym_arr->arr) {
    status = MEM_FAIL;
  }
  return status;
}
int add_line(DynamicArrayLine* dym_arr, Line line) {
  int status = OK;
  if (dym_arr->total_mem < (dym_arr->over_mem + 1)) {
    dym_arr->arr =
        (Line*)realloc(dym_arr->arr, sizeof(Line) * dym_arr->total_mem * 2);
    status = !dym_arr->arr;
    dym_arr->total_mem *= 2;
  }
  if (!status) {
    dym_arr->arr[dym_arr->over_mem] = line;
    dym_arr->over_mem++;
  }
  return status;
}
void remove_line(DynamicArrayLine* dym_arr) {
  if (dym_arr->total_mem) {
    free(dym_arr->arr);
  }
  dym_arr->over_mem = 0;
  dym_arr->total_mem = 0;
}
