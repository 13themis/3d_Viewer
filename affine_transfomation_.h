#ifndef _AFFINE_TRANSFORMATION_H_
#define _AFFINE_TRANSFORMATION_H_
#include "Dynamic_Array_.h"

#ifdef __cplusplus
extern "C" {
#endif

void translation(DynamicArrayVex* vex, float a, float b, float c);
void rotation(DynamicArrayVex* vex, float a, float b, float c);
void scaling(DynamicArrayVex* vex, float a, float b, float c);

#ifdef __cplusplus
}
#endif

#endif  //_AFFINE_TRANSFORMATION_H_