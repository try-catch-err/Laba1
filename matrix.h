//
// Created by cracky on 23.03.2022.
//
typedef struct Line_t{
    int items_num;
    double* items;
} Line_t;

typedef struct Matrix_t{
    int lines_num;
    Line_t* lines;
} Matrix_t;

int is_EOF_int(int *);
int is_EOF_double(double *);
int input_M(struct Matrix_t *mx);
void output_M(const char *msg, struct Matrix_t mx);
void output_vec(const char *msg, struct Matrix_t mx);
void mem_free(struct Matrix_t *mx);
double maxavg(struct Matrix_t mx);
double vec_max(double vec[], int sz);
double vec_avg(double vec[], int sz);
