#include "parser_.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int parser(const char* path, DynamicArrayVex* vex, DynamicArrayTrg* trg,
           DynamicArrayLine* line) {
  int status = OK;
  char* string = NULL;
  Vertex versh;
  Triangle treug;
  Line liniya;
  size_t str_size = 0;
  FILE* file = fopen(path, "r");
  if (!file) {
    status = MEM_FAIL;
  }
  while (!status && !feof(file)) {
    getline(&string, &str_size, file);
    if (string) {
      if (string[0] == 'v') {
        if (sscanf(string, "v %f %f %f", &versh.x, &versh.y, &versh.z) != 3) {
          status = MEM_FAIL;
        }
        versh.u = 1;
        versh.v = 0;
        status = add_v(vex, versh);
      } else if (string[0] == 'f') {
        if (sscanf(string, "f %d %d %d", &treug.vx, &treug.vy, &treug.vz) !=
            3) {
          status = MEM_FAIL;
        }
        treug.vx--;
        treug.vy--;
        treug.vz--;
        status = add_t(trg, treug);
        if (!status) {
          if (fabs(vex->arr[treug.vx].u) < 1e-4) {
            if (fabs(vex->arr[treug.vy].u - 0.5) < 1e-4) {
              vex->arr[treug.vz].u = 1;
            } else {
              vex->arr[treug.vz].u = 0.5;
              vex->arr[treug.vz].v = 1;
              vex->arr[treug.vy].u = 1;
            }
          } else if (fabs(vex->arr[treug.vy].u) < 1e-4) {
            if (fabs(vex->arr[treug.vx].u - 0.5) < 1e-4) {
              vex->arr[treug.vz].u = 1;
            } else {
              vex->arr[treug.vz].u = 0.5;
              vex->arr[treug.vz].v = 1;
              vex->arr[treug.vx].u = 1;
            }
          } else if (fabs(vex->arr[treug.vz].u) < 1e-4) {
            if (fabs(vex->arr[treug.vy].u - 0.5) < 1e-4) {
              vex->arr[treug.vx].u = 1;
            } else {
              vex->arr[treug.vx].u = 0.5;
              vex->arr[treug.vx].v = 1;
              vex->arr[treug.vy].u = 1;
            }
          } else if (fabs(vex->arr[treug.vz].u - 0.5) < 1e-4) {
            if (fabs(vex->arr[treug.vy].u) < 1e-4) {
              vex->arr[treug.vx].u = 1;
            } else {
              vex->arr[treug.vx].u = 0;
              vex->arr[treug.vy].u = 1;
            }
          } else if (fabs(vex->arr[treug.vx].u - 0.5) < 1e-4) {
            if (fabs(vex->arr[treug.vy].u) < 1e-4) {
              vex->arr[treug.vz].u = 1;
            } else {
              vex->arr[treug.vz].u = 0;
              vex->arr[treug.vy].u = 1;
            }
          } else if (fabs(vex->arr[treug.vy].u - 0.5) < 1e-4) {
            if (fabs(vex->arr[treug.vx].u) < 1e-4) {
              vex->arr[treug.vz].u = 1;
            } else {
              vex->arr[treug.vz].u = 0;
              vex->arr[treug.vx].u = 1;
            }
          } else if (fabs(vex->arr[treug.vx].u - 1) < 1e-4) {
            vex->arr[treug.vy].u = 0;
            vex->arr[treug.vz].u = 0.5;
            vex->arr[treug.vz].v = 1;
          }
        }

        if (!status) {
          liniya.a = treug.vx;
          liniya.b = treug.vz;
          add_line(line, liniya);
          liniya.a = treug.vx;
          liniya.b = treug.vy;
          add_line(line, liniya);
          liniya.a = treug.vy;
          liniya.b = treug.vz;
          add_line(line, liniya);
        }
      }
    }
  }
  if (!status) {
    fclose(file);
  }
  if (string) {
    free(string);
  }
  return status;
}
