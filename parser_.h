#ifndef _SRC_PARSER_H_
#define _SRC_PARSER_H_
#include "Dynamic_Array_.h"

#ifdef __cplusplus
extern "C" {
#endif

int parser(const char* path, DynamicArrayVex* vex, DynamicArrayTrg* trg,
           DynamicArrayLine* line);

#ifdef __cplusplus
}
#endif

#endif  //_SRC_PARSER_H_
