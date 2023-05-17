#include "affins.h"

#include <math.h>
#include <stdio.h>

void recalculation(vector* vectors, int count_vector, vector* result, difference diff) {
    double buf_x = 0, buf_y = 0, buf_z = 0;
    for (int i = 0; i < count_vector; i++) {

        result[i].x = (vectors[i].x + diff.x_move)* diff.size;
        result[i].y = (vectors[i].y + diff.y_move)* diff.size;
        result[i].z = (vectors[i].z + diff.z_move)* diff.size;

        buf_x = result[i].x;
        buf_y = result[i].y;
        buf_z = result[i].z;

//        result[i].y = buf_y * cos(diff.x_alpha) + buf_z * sin(diff.x_alpha);
//        buf_y = result[i].y;
//        result[i].z = -buf_y * sin(diff.x_alpha) + buf_z * cos(diff.x_alpha);
//        buf_z = result[i].z;

//        result[i].x = buf_x * cos(diff.y_alpha) + buf_z * sin(diff.y_alpha);
//        buf_x = result[i].x;
//        result[i].z = -buf_x * sin(diff.y_alpha) + buf_z * cos(diff.y_alpha);
//        buf_z = result[i].z;

//        result[i].x = buf_x * cos(diff.z_alpha) + buf_y * sin(diff.z_alpha);
//        buf_y = result[i].y;
//        result[i].y = -buf_x * sin(diff.z_alpha) + buf_y * cos(diff.z_alpha);
//        buf_x = result[i].x;

          //rotation x
          result[i].x = buf_x;
          result[i].y = buf_y * cos(diff.x_alpha) - buf_z * sin(diff.x_alpha);
                buf_y = result[i].y;
          result[i].z = buf_y * sin(diff.x_alpha) + buf_z * cos(diff.x_alpha);
                buf_z = result[i].z;

          //rotation y
          result[i].x = buf_x * cos(diff.y_alpha) + buf_z * sin(diff.y_alpha);
                buf_x = result[i].x;
          result[i].y = buf_y;
          result[i].z = -buf_x * sin(diff.y_alpha) + buf_z * cos(diff.y_alpha);
                buf_z = result[i].z;

          // rotation z
          result[i].x = buf_x * cos(diff.z_alpha) - buf_y * sin(diff.z_alpha);
                buf_y = result[i].y;
          result[i].y = buf_x * sin(diff.z_alpha) + buf_y * cos(diff.z_alpha);
                buf_x = result[i].x;
          result[i].z = buf_z;

    }
//    printf("<<<<<%lf %lf\n", result[0].x, vectors[0].x);
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
