#ifndef SRC_AFFINS_H_
#define SRC_AFFINS_H_

#include "obj_reader.h"

typedef struct difference {
  double x_move;
  double y_move;
  double z_move;
  double size;
  double x_alpha;
  double y_alpha;
  double z_alpha;
} difference;

vector* move_xyz(vector* vectors, int count_vector, double x_move,
                        double y_move, double z_move, vector* result);
vector* size_xyz(vector* vectors, int count_vector, double x_size,
                        double y_size, double z_size, vector* result);
vector* rotation_x(vector* vectors, int count_vector, double alpha, vector* result);
vector* rotation_y(vector* vectors, int count_vector, double alpha, vector* result);
vector* rotation_z(vector* vectors, int count_vector, double alpha, vector* result);
#endif  // SRC_AFFINS_H_
