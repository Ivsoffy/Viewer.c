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

void fill_matrixs(matrix_t* mat, matrix_t* origin, double alpha);

extern vector* move_xyz(vector* vectors, int count_vector, double x_move,
                        double y_move, double z_move) {
  matrix_t mat;
  matrix_t origin;
  matrix_t result;
  s21_create_matrix(4, 4, &mat);
  s21_create_matrix(4, 1, &origin);
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      if (k == j) {
        mat.matrix[j][k] = 1.0;
      } else {
        mat.matrix[j][k] = 0.0;
      }
    }
  }
  mat.matrix[0][3] = x_move;
  mat.matrix[1][3] = y_move;
  mat.matrix[2][3] = z_move;
  origin.matrix[3][0] = 1.0;
  for (int i = 0; i < count_vector; i++) {
    origin.matrix[0][0] = vectors[i].x;
    origin.matrix[1][0] = vectors[i].y;
    origin.matrix[2][0] = vectors[i].z;
    s21_mult_matrix(&mat, &origin, &result);
    vectors[i].x = result.matrix[0][0];
    vectors[i].y = result.matrix[1][0];
    vectors[i].z = result.matrix[2][0];
  }
  s21_remove_matrix(&mat);
  s21_remove_matrix(&origin);
  s21_remove_matrix(&result);
  return vectors;
}

extern vector* size_xyz(vector* vectors, int count_vector, double x_size,
                        double y_size, double z_size) {
  matrix_t mat;
  matrix_t origin;
  matrix_t result;
  s21_create_matrix(4, 4, &mat);
  s21_create_matrix(4, 1, &origin);
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      mat.matrix[j][k] = 0.0;
    }
  }
  mat.matrix[0][0] = x_size;
  mat.matrix[1][1] = y_size;
  mat.matrix[2][2] = z_size;
  mat.matrix[3][3] = 1.0;
  origin.matrix[3][0] = 1.0;
  for (int i = 0; i < count_vector; i++) {
    origin.matrix[0][0] = vectors[i].x;
    origin.matrix[1][0] = vectors[i].y;
    origin.matrix[2][0] = vectors[i].z;
    s21_mult_matrix(&mat, &origin, &result);
    vectors[i].x = result.matrix[0][0];
    vectors[i].y = result.matrix[1][0];
    vectors[i].z = result.matrix[2][0];
  }
  s21_remove_matrix(&mat);
  s21_remove_matrix(&origin);
  s21_remove_matrix(&result);
  return vectors;
}

extern vector* rotation_x(vector* vectors, int count_vector, double alpha) {
  matrix_t mat;
  matrix_t origin;
  matrix_t result;
  s21_create_matrix(3, 3, &mat);
  s21_create_matrix(3, 1, &origin);
  fill_matrixs(&mat, &origin, alpha);
  for (int i = 0; i < count_vector; i++) {
    origin.matrix[0][0] = vectors[i].x;
    origin.matrix[1][0] = vectors[i].y;
    s21_mult_matrix(&mat, &origin, &result);
    vectors[i].x = result.matrix[0][0];
    vectors[i].y = result.matrix[1][0];
  }
  s21_remove_matrix(&mat);
  s21_remove_matrix(&origin);
  s21_remove_matrix(&result);
  return vectors;
}

extern vector* rotation_y(vector* vectors, int count_vector, double alpha) {
  matrix_t mat;
  matrix_t origin;
  matrix_t result;
  s21_create_matrix(3, 3, &mat);
  s21_create_matrix(3, 1, &origin);
  fill_matrixs(&mat, &origin, alpha);
  for (int i = 0; i < count_vector; i++) {
    origin.matrix[0][0] = vectors[i].z;
    origin.matrix[1][0] = vectors[i].y;
    s21_mult_matrix(&mat, &origin, &result);
    vectors[i].z = result.matrix[0][0];
    vectors[i].y = result.matrix[1][0];
  }
  s21_remove_matrix(&mat);
  s21_remove_matrix(&origin);
  s21_remove_matrix(&result);
  return vectors;
}

extern vector* rotation_z(vector* vectors, int count_vector, double alpha) {
  matrix_t mat;
  matrix_t origin;
  matrix_t result;
  s21_create_matrix(3, 3, &mat);
  s21_create_matrix(3, 1, &origin);
  fill_matrixs(&mat, &origin, alpha);
  for (int i = 0; i < count_vector; i++) {
    origin.matrix[0][0] = vectors[i].x;
    origin.matrix[1][0] = vectors[i].z;
    s21_mult_matrix(&mat, &origin, &result);
    vectors[i].x = result.matrix[0][0];
    vectors[i].z = result.matrix[1][0];
  }
  s21_remove_matrix(&mat);
  s21_remove_matrix(&origin);
  s21_remove_matrix(&result);
  return vectors;
}

void fill_matrixs(matrix_t* mat, matrix_t* origin, double alpha) {
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      mat->matrix[j][k] = 0.0;
    }
  }
  mat->matrix[0][0] = cos(alpha);
  mat->matrix[0][1] = sin(alpha);
  mat->matrix[1][0] = -sin(alpha);
  mat->matrix[1][1] = cos(alpha);
  mat->matrix[2][2] = 1.0;
  origin->matrix[2][0] = 1.0;
}
