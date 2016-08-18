#ifndef CARTESIAN_PLANE_STRUCT
#define CARTESIAN_PLANE_STRUCT

typedef struct point {
  int x;
  int y;
} Point;

struct triangle {
  Point pointA;
  Point pointB;
  Point pointC;
} Triangle;

#endif
