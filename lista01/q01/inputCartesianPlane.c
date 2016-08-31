#include <stdio.h>
#include "inputCartesianPlane.h"
#include "geometricOperations.h"
#include "cartesianPlaneStruct.h"

Point setPoint(int x, int y){
  Point point;
  point.x = x;
  point.y = y;

  return point;
}

Point setCoordinate(){
  int x,y;
  Point point;

  printf("Puts the coordinate 'x', and 'y' of triangle\n");
  scanf("%d %d",&x, &y);
  point = setPoint(x,y);

  return point;
}

Triangle setTriangle(){
  Triangle triangle;
  Point point[3];
  int x[3], y[3], i;

  for(i=1;i<=3;i++){
    printf("%d° point of triangle\n", i);
    point[i] = setCoordinate();
  }
  triangle.pointA = point[1];
  triangle.pointB = point[2];
  triangle.pointC = point[3];

  return triangle;
}

void menu(){
  char option;
  Triangle triangle;
  printf("Welcome to triangle calculater\n");
  while(1){
    printf("Do want select one more triangle?\n'y' to yes, and 'n' to no\n");
    scanf(" %c", &option);
    if(option == 'y'){
      triangle = setTriangle();
      getArea(triangle);
    }

    else if(option == 'n')
      break;
    else
      printf("Invalid chacter\n");
  }
}
