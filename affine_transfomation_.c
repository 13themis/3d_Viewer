#include "affine_transfomation_.h"

#include <math.h>

void translation(DynamicArrayVex *vex, float a, float b, float c) {
  for (long unsigned int i = 0; i < vex->over_mem; ++i) {
    vex->arr[i].x += a;
    vex->arr[i].y += b;
    vex->arr[i].z += c;
  }
}

void rotation(DynamicArrayVex *vex, float a, float b, float c) {
  for (long unsigned int i = 0; i < vex->over_mem; ++i) {
    float x = vex->arr[i].x;
    float y = vex->arr[i].y;
    float z = vex->arr[i].z;
    vex->arr[i].x = x * cos(b) * cos(c) - y * cos(b) * sin(c) + z * sin(b);
    vex->arr[i].y = -z * cos(b) * sin(a) +
                    (cos(c) * sin(a) * sin(b) + cos(a) * sin(c)) * x -
                    (sin(a) * sin(b) * sin(c) - cos(a) * cos(c)) * y;
    vex->arr[i].z = z * cos(a) * cos(b) -
                    (cos(a) * cos(c) * sin(b) - sin(a) * sin(c)) * x +
                    (cos(a) * sin(b) * sin(c) + cos(c) * sin(a)) * y;
  }
}

void scaling(DynamicArrayVex *vex, float a, float b, float c) {
  for (long unsigned int i = 0; i < vex->over_mem; ++i) {
    vex->arr[i].x *= a;
    vex->arr[i].y *= b;
    vex->arr[i].z *= c;
  }
}
