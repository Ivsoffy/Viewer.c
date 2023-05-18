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

void recalculation(vector* vectors, int count_vector, vector* result,
                   difference diff);

#endif  // SRC_AFFINS_H_
