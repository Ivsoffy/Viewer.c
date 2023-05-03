#ifndef SRC_OBJ_READER_H_
#define SRC_OBJ_READER_H_

typedef struct vector {
  double x;
  double y;
  double z;
} vector;

typedef struct surface_dot {
  int *v;
  int number_dot_surface;
} surface_dot;

extern int obj_read(const char *filename, vector **vectors, surface_dot **surface,
                     int *count_vector, int *count_surface);

void counting_v_f(char *filename, int *count_vector, int *count_surface);
void parcing_file(char *filename, vector **vectors, surface_dot **surface,
                  int count_vector, int count_surface);

void print_vector(vector *mas, int count_vector);
void print_surface(surface_dot *surface, int count_surface);

#endif  // SRC_OBJ_READER_H_
