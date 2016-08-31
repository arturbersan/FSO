#include <stdio.h>
#include <math.h>
#include "geometricOperations.h"
#include "cartesianPlaneStruct.h"

double getSideSize(Point pointA, Point pointB){

  double differenceX = pointA.x - pointB.x;
  double differenceY = pointA.y - pointB.y;
  double sideSize = hypot(differenceX,differenceY);

  return sideSize;
}

short isTriangle(Triangle triangle){
  double sideSizeA = getSideSize(triangle.pointA,triangle.pointB);
  double sideSizeB = getSideSize(triangle.pointA,triangle.pointC);
  double sideSizeC = getSideSize(triangle.pointC,triangle.pointB);

  if(sideSizeA+sideSizeB > sideSizeC && sideSizeA+sideSizeC > sideSizeB && sideSizeB+sideSizeC > sideSizeA)
    return 1;
  else
    return 0;
}

double getPerimeter(Triangle triangle){
  double sideSizeA = getSideSize(triangle.pointA,triangle.pointB);
  double sideSizeB = getSideSize(triangle.pointA,triangle.pointC);
  double sideSizeC = getSideSize(triangle.pointC,triangle.pointB);
  double result = sideSizeA + sideSizeB + sideSizeC;

  if(isTriangle(triangle)){
    printf("sideSizeA  = %lf\nsideSizeB = %lf\nsideSizeC = %lf\n",sideSizeA,sideSizeB,sideSizeC);
    printf("Perimiter = %lf\n", result);
    return result;
  }
  else
    printf("Is not a triangle\n");
}


double getArea(Triangle triangle){
  double semiPerimeter = getPerimeter(triangle)/2;
  double sideSizeA = getSideSize(triangle.pointA,triangle.pointB);
  double sideSizeB = getSideSize(triangle.pointA,triangle.pointC);
  double sideSizeC = getSideSize(triangle.pointC,triangle.pointB);

  double result = sqrt(semiPerimeter*(semiPerimeter-sideSizeA)*(semiPerimeter-sideSizeB)*(semiPerimeter-sideSizeC));

  if(isTriangle(triangle)){
    printf("Area = %lf\n", result);
    return result;
  }
  else
    return 0;
}
