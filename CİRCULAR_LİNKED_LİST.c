#include <stdio.h>
#include <stdlib.h>

/* Node yapisi */
struct node {
    int data;
    struct node *next;
};

/* Yeni node olusturma */
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode;   /* Circular */
    return newNode;
}

/* Sona ekleme */
struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp;

    if (head == NULL)
        return newNode;

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

/* Traversal */
void traverse(struct node* head) {
    struct node* temp = head;

    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    printf("Liste: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Searching */
struct node* search(struct node* head, int key) {
    struct node* temp = head;

    if (head == NULL)
        return NULL;

    do {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    } while (temp != head);

    return NULL;
}

/* Deleting */
struct node* deleteNode(struct node* head, int key) {
    struct node *curr = head, *prev = NULL;

    if (head == NULL) {
        printf("Liste bos!\n");
        return head;
    }

    do {
        if (curr->data == key) {

            /* Tek elemanli liste */
            if (curr->next == curr) {
                free(curr);
                return NULL;
            }

            /* Ilk eleman siliniyorsa */
            if (curr == head) {
                struct node* last = head;
                while (last->next != head)
                    last = last->next;

                head = curr->next;
                last->next = head;
                free(curr);
                return head;
            }

            /* Ortada veya sonda */
            prev->next = curr->next;
            free(curr);
            return head;
        }

        prev = curr;
        curr = curr->next;
    } while (curr != head);

    printf("Eleman bulunamadi!\n");
    return head;
}

int main() {
    struct node* head = NULL;
    int choice, value;

    do {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
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


