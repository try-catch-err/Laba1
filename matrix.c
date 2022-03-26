//
// Created by cracky on 23.03.2022.
//

#include "matrix.h"
#include <stdio.h>
#include <malloc.h>

int is_EOF_int(int* a)
{
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0) {
            return 1;
        }
        if (n == 0){       // wrong input
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (n == 0);
    return 0;
}

int is_EOF_double(double* a)
{
    int n;
    do{
        n = scanf("%lf", a);
        if (n < 0)
            return 1;
        if (n == 0){       // wrong input
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (n == 0);
    return 0;
}

int input_M(Matrix_t *matr)
{
    const char *err_msg = "";
    int lines_num;
    int i, j;
    double *items;
    do{
        printf("%s\n", err_msg);
        printf("Enter number of lines: --> ");
        err_msg = "You are wrong; repeat, please!";
        if(is_EOF_int(&lines_num))
            return 0;

    } while (lines_num < 1);
    matr->lines_num = lines_num;

    matr->lines = (Line_t* )calloc(lines_num, sizeof(Line_t));
    for (i = 0; i < matr->lines_num; ++i){
        err_msg = "";
        do{
            printf("%s\n", err_msg);
            printf("Enter number of items in line %d: --> ", i + 1);
            err_msg = "You are wrong; repeat, please!";
            if (is_EOF_int(&lines_num)){
                matr->lines_num = i;
                mem_free(matr);
                return 0;
            }
        } while (lines_num < 1);
        matr->lines[i].items_num = lines_num;
        items = (double *)malloc(sizeof(double)* lines_num);
        matr->lines[i].items = items;
        printf("Enter items for matrix line #%d:\n", i + 1);
        for (j = 0; j < lines_num; ++j, ++items)
            if (is_EOF_double(items)){
                matr->lines_num = i + 1;
                mem_free(matr);
                return 0;
            }
    }
    return 1;
}

void output_M(const char *msg, Matrix_t mx)
{
    int i, j;
    double *items;
    printf("%s:\n", msg);
    for (i = 0; i < mx.lines_num; ++i){
        items = mx.lines[i].items;
        for (j = 0; j < mx.lines[i].items_num; ++j, ++items)
            printf("%10lf ", *items);
        printf("\n");
    }
}

void output_vec(const char *msg, Matrix_t mx)
{
    printf("%s:\n", msg);
    for (int i = 0; i < mx.lines_num; ++i)
        printf("%10lf ", vec_avg(mx.lines[i].items, mx.lines[i].items_num) / maxavg(mx));
    printf("\n");
}

void mem_free(Matrix_t *matrix)
{
    int i;
    for (i = 0; i < matrix->lines_num; ++i)
        free(matrix->lines[i].items);
    free(matrix->lines);
    matrix->lines = 0;
    matrix->lines = NULL;
}

double maxavg(Matrix_t mx)
{
    double *avgg = (double *)malloc(sizeof(double)* mx.lines_num);
    double res;
    double* avgg_1 = avgg;
    int i;
    for (i = 0; i < mx.lines_num; ++i)
        *avgg_1++ = vec_avg(mx.lines[i].items, mx.lines[i].items_num);
    res = vec_max(avgg, mx.lines_num);
    free(avgg);
    return res;
}

double vec_max(double vec[], int sz)
{
    double res = *vec;
    for (; sz-- > 0; ++vec)
        if (*vec > res)
            res = *vec;
    return res;
}

double vec_avg(double vec[], int sz)
{
    double res = *vec;
    for (int i = 0; i++ < sz; ++vec)
        res = (res + *vec)/(i + 2);
    return res;
}



