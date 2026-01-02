#include <stdio.h>

#define MAX 100

/* Array yazdirma */
void display(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array bos!\n");
        return;
    }

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Eleman ekleme */
void insert(int arr[], int *n, int pos, int val) {
    int i;

    if (*n >= MAX) {
        printf("Array dolu!\n");
        return;
    }

    for (i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = val;
    (*n)++;
    printf("Eleman eklendi.\n");
}

/* Eleman silme */
void delete(int arr[], int *n, int pos) {
    int i;

    if (*n == 0) {
        printf("Array bos!\n");
        return;
    }

    for (i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
    printf("Eleman silindi.\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, value, pos;

    do {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Eleman Ekle\n");
        printf("2. Eleman Sil\n");
        printf("3. Array Yazdir\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek deger: ");
                scanf("%d", &value);
                printf("Pozisyon (0-%d): ", n);
                scanf("%d", &pos);

                if (pos < 0 || pos > n)
                    printf("Gecersiz pozisyon!\n");
                else
                    insert(arr, &n, pos, value);
                break;

            case 2:
                printf("Silinecek pozisyon (0-%d): ", n - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= n)
                    printf("Gecersiz pozisyon!\n");
                else
                    delete(arr, &n, pos);
                break;

            case 3:
                display(arr, n);
                break;

            case 0:
                printf("Program sonlandi.\n");
                break;

            default:
                printf("Gecersiz secim!\n");
        }
    } while (choice != 0);

    return 0;
}

