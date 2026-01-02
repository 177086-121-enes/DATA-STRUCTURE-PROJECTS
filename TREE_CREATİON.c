#include <stdio.h>

int main() {
    int tree[] = {10, 20, 30, 40, 50};
    int n = 5, i;

    for (i = 0; i < n; i++) {
        printf("Node: %d ", tree[i]);
        if (2*i+1 < n)
            printf("Left: %d ", tree[2*i+1]);
        if (2*i+2 < n)
            printf("Right: %d ", tree[2*i+2]);
        printf("\n");
    }
    return 0;
}

