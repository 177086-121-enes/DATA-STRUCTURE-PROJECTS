#include <stdio.h>
#include <stdlib.h>

/* Node yapisi */
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

/* Yeni node olusturma */
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* Sona ekleme */
struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp;

    if (head == NULL)
        return newNode;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* Traversal */
void traverse(struct node* head) {
    printf("Liste: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Searching */
struct node* search(struct node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return head;
        head = head->next;
    }
    return NULL;
}

/* Deleting */
struct node* deleteNode(struct node* head, int key) {
    struct node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Eleman bulunamadi!\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Eleman silindi.\n");

    return head;
}

int main() {
    struct node* head = NULL;
    int choice, value;

    do {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Sona Ekle\n");
        printf("2. Traversal\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Deger giriniz: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 2:
                traverse(head);
                break;

            case 3:
                printf("Aranacak deger: ");
                scanf("%d", &value);
                if (search(head, value))
                    printf("Eleman bulundu.\n");
                else
                    printf("Eleman bulunamadi.\n");
                break;

            case 4:
                printf("Silinecek deger: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
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

