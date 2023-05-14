#include "affins.h"

#include <math.h>
#include <stdio.h>

// int main() {
//   vector* vectors;
//   surface_dot* surface;
//   int count_vector = 0, count_surface = 0;
//   obj_read("cube.obj", &vectors, &surface, &count_vector, &count_surface);
//   print_vector(vectors, count_vector);
//   print_surface(surface, count_surface);
//   vectors = move(vectors, count_vector, 0, 2);
//   print_vector(vectors, count_vector);
//   return 0;
// }

extern vector* move_xyz(vector* vectors, int count_vector, double x_move,
                        double y_move, double z_move, vector* result) {
  for (int i = 0; i < count_vector; i++) {
    result[i].x = vectors[i].x + x_move;
    result[i].y = vectors[i].y + y_move;
    result[i].z = vectors[i].z + z_move;
  }
  return result;
}

extern vector* size_xyz(vector* vectors, int count_vector, double x_size,
                        double y_size, double z_size, vector* result) {
  for (int i = 0; i < count_vector; i++) {
    result[i].x = vectors[i].x * x_size;
    result[i].y = vectors[i].y * y_size;
    result[i].z = vectors[i].z * z_size;
  }
  return result;
}

extern vector* rotation_x(vector* vectors, int count_vector, double alpha, vector* result) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].y;
    result[i].y = vectors[i].y * cos(alpha) + vectors[i].z * sin(alpha);
    result[i].z = -buf * sin(alpha) + vectors[i].z * cos(alpha);
  }
  return result;
}

extern vector* rotation_y(vector* vectors, int count_vector, double alpha, vector* result) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].x;
    result[i].x = vectors[i].x * cos(alpha) + vectors[i].z * sin(alpha);
    result[i].z = -buf * sin(alpha) + vectors[i].z * cos(alpha);
  }
  return result;
}

extern vector* rotation_z(vector* vectors, int count_vector, double alpha, vector* result) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].x;
    result[i].x = vectors[i].x * cos(alpha) + vectors[i].y * sin(alpha);
    result[i].y = -buf * sin(alpha) + vectors[i].y * cos(alpha);
  }
  return result;
}
