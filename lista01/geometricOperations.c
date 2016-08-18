#include <stdio.h>
#include <math.h>
#include "geometricOperations.h"
#include "cartesianPlaneStruct.h"

double getSideSize(Point pointA, Point pointB){
  printf("a PointX = %d\n", pointA.x);
  printf("b PointY = %d\n", pointB.x);

  double differenceX = pointA.x - pointB.x;
  printf("DifferenceX = %lf\n", differenceX);
  double differenceY = pointA.y - pointB.y;
  printf("DifferenceY = %lf\n", differenceY);
  double sideSize = hypot(differenceX,differenceY);

  printf("Distance = %lf\n", sideSize);
  return sideSize;
}

int main(){

  Point pointA, pointB;

  pointA.x = 4;
  pointA.y = 5;

  pointB.x = 1;
  pointB.y = 1;

  double a;

  a = getSideSize(pointA,pointB);

  return 0;
}
