#include "affins.h"

#include <math.h>
#include <stdio.h>

void recalculation(vector* vectors, int count_vector, vector* result, difference diff) {
    double buf_x = 0, buf_y = 0, buf_z = 0;
    for (int i = 0; i < count_vector; i++) {

        result[i].x = (vectors[i].x + diff.x_move)* diff.size;
        result[i].y = (vectors[i].y + diff.y_move)* diff.size;
        result[i].z = (vectors[i].z + diff.z_move)* diff.size;

          double x = result[i].x;
          double y = result[i].y;
          double z = result[i].z;
          double A = diff.x_alpha;
          double B = diff.y_alpha;
          double C = diff.z_alpha;

          result[i].x = (x*cos(B+C)+x*cos(B-C)+2*z*sin(B)-y*sin(B+C)+y*sin(B-C))/2;
          result[i].y = (2*y*cos(A+C)-x*cos(A+B+C)+x*cos(A-B+C)+2*y*cos(A-C)-x*cos(A+B-C)+x*cos(A-B-C)-2*z*sin(A+B)-2*z*sin(A-B)+2*x*sin(A+C)+y*sin(A+B+C)-y*sin(A-B+C)-2*x*sin(A-C)-y*sin(A+B-C)+y*sin(A-B-C))/4;
          result[i].z = (2*z*cos(A+B)+2*z*cos(A-B)-2*x*cos(A+C)-y*cos(A+B+C)+y*cos(A-B+C)+2*x*cos(A-C)+y*cos(A+B-C)-y*cos(A-B-C)+2*y*sin(A+C)-x*sin(A+B+C)+x*sin(A-B+C)+2*y*sin(A-C)-x*sin(A+B-C)+x*sin(A-B-C))/4;
    }
}

vector* move_xyz(vector* vectors, int count_vector, double x_move,//
                        double y_move, double z_move, vector* result) {
  for (int i = 0; i < count_vector; i++) {
    result[i].x = vectors[i].x + x_move;
    result[i].y = vectors[i].y + y_move;
    result[i].z = vectors[i].z + z_move;
  }
  return result;
}

vector* size_xyz(vector* vectors, int count_vector, double x_size,//
                        double y_size, double z_size, vector* result) {
  for (int i = 0; i < count_vector; i++) {
    result[i].x = vectors[i].x * x_size;
    result[i].y = vectors[i].y * y_size;
    result[i].z = vectors[i].z * z_size;
  }
  return result;
}

vector* rotation_x(vector* vectors, int count_vector, double alpha, vector* result) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
//    buf = vectors[i].y;
    result[i].y = vectors[i].y * cos(alpha) + vectors[i].z * sin(alpha);
    result[i].z = -vectors[i].y * sin(alpha) + vectors[i].z * cos(alpha);
  }
  return result;
}

vector* rotation_y(vector* vectors, int count_vector, double alpha, vector* result) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].x;
    result[i].x = vectors[i].x * cos(alpha) + vectors[i].z * sin(alpha);
    result[i].z = -vectors[i].x * sin(alpha) + vectors[i].z * cos(alpha);
  }
  return result;
}

vector* rotation_z(vector* vectors, int count_vector, double alpha, vector* result) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].x;
    result[i].x = vectors[i].x * cos(alpha) + vectors[i].y * sin(alpha);
    result[i].y = -vectors[i].x * sin(alpha) + vectors[i].y * cos(alpha);
  }
  return result;
}
