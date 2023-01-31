#ifndef _SRC_VERTEX_H_
#define _SRC_VERTEX_H_

typedef struct vertex {
  float x;
  float y;
  float z;
  float u;
  float v;
} Vertex;

typedef struct triangle {
  int vx;
  int vy;
  int vz;
} Triangle;

typedef struct line {
  int a;
  int b;
} Line;

#endif  //_SRC_VERTEX_H_
