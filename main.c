#include <stdio.h>
#include "matrix.h"
int main() {
    Matrix_t matr = {0, NULL};
    if (input_M(&matr) == 0){
        printf("%s\n", "End of file occured");
        return 1;
    }
    output_M("Source matrix", matr);
    output_vec("Created vector", matr);
    mem_free(&matr);
    return 0;
}
