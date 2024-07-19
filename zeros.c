// Program to move zeros at end of list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void moveZeroesToEnd(struct Node* head) {
    struct Node* current = head;
    struct Node* lastNonZeroNode = head;

    while (current != NULL) {
        if (current->data != 0) {
            int temp = lastNonZeroNode->data;
            lastNonZeroNode->data = current->data;
            current->data = temp;
            lastNonZeroNode = lastNonZeroNode->next;
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original Linked List: ");
    printList(head);

    moveZeroesToEnd(head);

    printf("Linked List after moving zeroes to the end: ");
    printList(head);

    return 0;
}
