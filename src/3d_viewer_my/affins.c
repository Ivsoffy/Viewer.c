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
                        double y_move, double z_move) {
  for (int i = 0; i < count_vector; i++) {
    vectors[i].x = vectors[i].x + x_move;
    vectors[i].y = vectors[i].y + y_move;
    vectors[i].z = vectors[i].z + z_move;
  }
  return vectors;
}

extern vector* size_xyz(vector* vectors, int count_vector, double x_size,
                        double y_size, double z_size) {
  for (int i = 0; i < count_vector; i++) {
    vectors[i].x = vectors[i].x * x_size;
    vectors[i].y = vectors[i].y * y_size;
    vectors[i].z = vectors[i].z * z_size;
  }
  return vectors;
}

extern vector* rotation_x(vector* vectors, int count_vector, double alpha) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].y;
    vectors[i].y = vectors[i].y * cos(alpha) + vectors[i].z * sin(alpha);
    vectors[i].z = -buf * sin(alpha) + vectors[i].z * cos(alpha);
  }
  return vectors;
}

extern vector* rotation_y(vector* vectors, int count_vector, double alpha) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].x;
    vectors[i].x = vectors[i].x * cos(alpha) + vectors[i].z * sin(alpha);
    vectors[i].z = -buf * sin(alpha) + vectors[i].z * cos(alpha);
  }
  return vectors;
}

extern vector* rotation_z(vector* vectors, int count_vector, double alpha) {
  double buf = 0.0;
  for (int i = 0; i < count_vector; i++) {
    buf = vectors[i].x;
    vectors[i].x = vectors[i].x * cos(alpha) + vectors[i].y * sin(alpha);
    vectors[i].y = -buf * sin(alpha) + vectors[i].y * cos(alpha);
  }
  return vectors;
}
