#include "obj_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1256

// int main() {
//   vector *vectors;
//   surface_dot *surface;
//   int count_vector = 0, count_surface = 0;
//   // obj_read("Pyramids.obj", &vectors, &surface, &count_vector,
//   // &count_surface);
//   obj_read("cube.obj", &vectors, &surface, &count_vector, &count_surface);
//   print_vector(vectors, count_vector);
//   print_surface(surface, count_surface);
//   return 0;
// }

extern int obj_read(const char *filename, vector **vectors,
                    surface_dot **surface, int *count_vector,
                    int *count_surface) {
  int r = 1;
  FILE *file;

  if (file = fopen(filename, "r")) {
    fclose(file);
    counting_v_f(filename, count_vector, count_surface);
    parcing_file(filename, vectors, surface, *count_vector, *count_surface);
  } else {
    system("ls");
    r = 0;
    fprintf(stderr, "%s: No such file\n", filename);
  }
  return r;
}

void counting_v_f(const char *filename, int *count_vector, int *count_surface) {
  FILE *file;
  char str[LEN];
  int countv = 0, countf = 0, numberf = 0;
  if ((file = fopen(filename, "r"))) {
    while ((fgets(str, LEN, file)) != NULL) {
      if (str[0] == 'v' && str[1] == ' ') {
        countv++;
      }
      if (str[0] == 'f' && str[1] == ' ') {
        countf++;
      }
    }
    fclose(file);
  }
  *count_vector = countv;
  *count_surface = countf;
}

void parcing_file(const char *filename, vector **vectors, surface_dot **surface,
                  int count_vector, int count_surface) {
  FILE *file;
  vector *mas = (vector *)calloc(count_vector, sizeof(vector));
  surface_dot *sur = (surface_dot *)calloc(count_surface, sizeof(surface_dot));
  char str[LEN], bufc, bufs[LEN];
  int countv = 0, countf = 0, numberf = 0;
  if ((file = fopen(filename, "r"))) {
    while ((fgets(str, LEN, file)) != NULL) {
      if (str[0] == 'v' && str[1] == ' ') {
        sscanf(str, "%c %lf %lf %lf", &bufc, &mas[countv].x, &mas[countv].y,
               &mas[countv++].z);
      }
      if (str[0] == 'f' && str[1] == ' ') {
        strcpy(bufs, str);
        char *tmp_char = NULL;
        tmp_char = strtok(bufs, " ");
        while (tmp_char != NULL) {
          numberf++;
          tmp_char = strtok(NULL, " ");
        }
        sur[countf].v = calloc(numberf - 1, sizeof(int));
        tmp_char = strtok(str, " ");
        int i = 0, valuef;
        while (tmp_char != NULL) {
          if (i != 0) {
            sscanf(tmp_char, "%d", &valuef);
            sur[countf].v[i - 1] = valuef;
          }
          tmp_char = strtok(NULL, " ");
          i++;
        }
        sur[countf++].number_dot_surface = numberf - 1;
      }
      numberf = 0;
    }
    fclose(file);
  }
  *surface = sur;
  *vectors = mas;
}

void print_vector(vector *mas, int count_vector) {
  for (int i = 0; i < count_vector; i++) {
    printf("%lf %lf %lf\n", mas[i].x, mas[i].y, mas[i].z);
  }
}

void print_surface(surface_dot *surface, int count_surface) {
  for (int i = 0; i < count_surface; i++) {
    printf("%d\n", surface[i].number_dot_surface);
    for (int j = 0; j < surface[i].number_dot_surface; j++) {
      printf("%d ", surface[i].v[j]);
    }
    printf("\n");
  }
}
