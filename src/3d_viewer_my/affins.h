#ifndef SRC_AFFINS_H_
#define SRC_AFFINS_H_

#include "obj_reader.h"

extern vector* move_xyz(vector* vectors, int count_vector, double x_move,
                        double y_move, double z_move);
extern vector* size_xyz(vector* vectors, int count_vector, double x_size,
                        double y_size, double z_size);
extern vector* rotation_x(vector* vectors, int count_vector, double alpha);
extern vector* rotation_y(vector* vectors, int count_vector, double alpha);
extern vector* rotation_z(vector* vectors, int count_vector, double alpha);
#endif  // SRC_AFFINS_H_
