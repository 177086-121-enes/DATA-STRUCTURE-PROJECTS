#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", source, destination);
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);
    printf("Disk %d: %c -> %c\n", n, source, destination);
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Disk sayisini giriniz: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}

