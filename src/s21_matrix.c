#include "s21_matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fill_matrix(matrix_t *mat);
void my_create(matrix_t *A, matrix_t *result);

int fill_matrix(matrix_t *mat) {
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->columns; j++) {
      mat->matrix[i][j] = i + j;
    }
  }
  return 0;
}

void my_create(matrix_t *A, matrix_t *result) {
  result->rows = A->rows;
  result->columns = A->columns;
  s21_create_matrix(result->rows, result->columns, result);
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows < 1 || columns < 1) {
    error = 1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = malloc(columns * sizeof(double));
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (!(fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-7)) {
          error = FAILURE;
          break;
        }
      }
    }
  } else {
    error = FAILURE;
  }
  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1) {
    error = 1;
  } else {
    if (A->rows == B->rows && A->columns == B->columns) {
      my_create(A, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      error = 2;
    }
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1) {
    error = 1;
  } else {
    if (A->rows == B->rows && A->columns == B->columns) {
      my_create(A, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      error = 2;
    }
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (A->rows < 1 || A->columns < 1) {
    error = 1;
  } else {
    my_create(A, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A->rows < 1 || A->columns < 1 || B->rows < 1 || B->columns < 1) {
    error = 1;
  } else {
    if (A->columns == B->rows) {
      my_create(A, result);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          double buffer = 0.0;
          for (int k = 0; k < A->columns; k++) {
            buffer += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = buffer;
        }
      }
    } else {
      error = 2;
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->rows < 1 || A->columns < 1) {
    error = 1;
  } else {
    result->rows = A->columns;
    result->columns = A->rows;
    s21_create_matrix(result->rows, result->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;

  if (A->rows < 1 || A->columns < 1) {
    error = 1;
  } else {
    if (A->rows == A->columns) {
      my_create(A, result);
      if (result->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            matrix_t buffer;
            s21_create_matrix(A->rows - 1, A->rows - 1, &buffer);
            for (int n = 0; n < buffer.rows; n++) {
              for (int m = 0; m < buffer.columns; m++) {
                buffer.matrix[n][m] =
                    A->matrix[(n + 1 + i) % A->rows][(m + 1 + j) % A->rows];
              }
            }
            double x = 0.0, sign = 1.0;
            s21_determinant(&buffer, &x);
            if (A->rows % 2 == 0) {
              if ((i + j) % 2 == 0) {
                sign = 1.0;
              } else {
                sign = -1.0;
              }
            }
            result->matrix[i][j] = sign * x;
            s21_remove_matrix(&buffer);
          }
        }
      }

    } else {
      error = 2;
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;

  if (A->rows < 1 || A->columns < 1) {
    error = 1;
  } else {
    if (A->rows == A->columns) {
      *result = 0.0;
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else {
        if (A->rows == 2) {
          *result = A->matrix[0][0] * A->matrix[1][1] -
                    A->matrix[1][0] * A->matrix[0][1];
        } else {
          for (int k = 0; k < A->rows; k++) {
            matrix_t buffer;
            s21_create_matrix(A->rows - 1, A->rows - 1, &buffer);
            for (int i = 0; i < buffer.rows; i++) {
              for (int j = 0; j < buffer.columns; j++) {
                buffer.matrix[i][j] =
                    A->matrix[(i + 1) % A->rows][(j + 1 + k) % A->rows];
              }
            }
            double x, sign = 1;
            s21_determinant(&buffer, &x);
            if (A->rows % 2 == 0) {
              if (k % 2 == 0) {
                sign = 1.0;
              } else {
                sign = -1.0;
              }
            }
            *result += sign * A->matrix[0][k] * x;
            s21_remove_matrix(&buffer);
          }
        }
      }
    } else {
      error = 2;
    }
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->rows < 1 || A->columns < 1) {
    error = 1;
  } else {
    if (A->rows == A->columns) {
      matrix_t buffer1, buffer2;
      s21_calc_complements(A, &buffer1);

      s21_transpose(&buffer1, &buffer2);
      double x = 0.0;
      s21_determinant(A, &x);
      if (x != 0.0) {
        s21_mult_number(&buffer2, 1.0 / x, result);
      } else {
        error = 2;
      }
      s21_remove_matrix(&buffer1);
      s21_remove_matrix(&buffer2);
    } else {
      error = 2;
    }
  }
  return error;
}
