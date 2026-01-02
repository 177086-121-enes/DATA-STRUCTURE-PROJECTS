#include <stdio.h>

int main() {
    int matrix[3][3] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0}
    };

    int sparse[10][3];
    int rows = 3, cols = 3;
    int count = 0;
    int k = 1;
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
                count++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;

    printf("Row Col Value\n");
    for (i = 0; i <= count; i++) {
        printf("%d   %d   %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}


