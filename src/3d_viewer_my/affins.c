#include "affins.h"

#include <math.h>
#include <stdio.h>

void recalculation(vector* vectors, int count_vector, vector* result,
                   difference diff) {
  for (int i = 0; i < count_vector; i++) {
    result[i].x = (vectors[i].x + diff.x_move) * diff.size;
    result[i].y = (vectors[i].y + diff.y_move) * diff.size;
    result[i].z = (vectors[i].z + diff.z_move) * diff.size;

    double x = result[i].x;
    double y = result[i].y;
    double z = result[i].z;
    double A = diff.x_alpha;
    double B = diff.y_alpha;
    double C = diff.z_alpha;

    result[i].x = (x * cos(B + C) + x * cos(B - C) + 2 * z * sin(B) -
                   y * sin(B + C) + y * sin(B - C)) /
                  2;
    result[i].y =
        (2 * y * cos(A + C) - x * cos(A + B + C) + x * cos(A - B + C) +
         2 * y * cos(A - C) - x * cos(A + B - C) + x * cos(A - B - C) -
         2 * z * sin(A + B) - 2 * z * sin(A - B) + 2 * x * sin(A + C) +
         y * sin(A + B + C) - y * sin(A - B + C) - 2 * x * sin(A - C) -
         y * sin(A + B - C) + y * sin(A - B - C)) /
        4;
    result[i].z =
        (2 * z * cos(A + B) + 2 * z * cos(A - B) - 2 * x * cos(A + C) -
         y * cos(A + B + C) + y * cos(A - B + C) + 2 * x * cos(A - C) +
         y * cos(A + B - C) - y * cos(A - B - C) + 2 * y * sin(A + C) -
         x * sin(A + B + C) + x * sin(A - B + C) + 2 * y * sin(A - C) -
         x * sin(A + B - C) + x * sin(A - B - C)) /
        4;
  }
}
