#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int marks;
    struct Node *next;
} Node;

Node* createNode(int marks) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

void swapMarks(Node *a, Node *b) {
    int tempMarks = a->marks;
    a->marks = b->marks;
    b->marks = tempMarks;
}

void bubbleSortLinkedList(Node* head) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (head == NULL || head->next == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->marks > ptr1->next->marks) {
                swapMarks(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void displayMarks(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->marks);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    Node* head = NULL; 
    Node* tail = NULL; 

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter marks for each student:\n");
    for (int i = 0; i < n; i++) {
        int marks;

        printf("Student %d: ", i + 1);
        scanf("%d", &marks);

        Node* newNode = createNode(marks);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bubbleSortLinkedList(head);

    printf("\nSorted marks (ascending order):\n");
    displayMarks(head);

    int middle = n / 2;
    Node* current = head;
    for (int i = 0; i < middle; i++) {
        current = current->next;
    }

    printf("\nMiddle student/node mark(s):\n");
    if (n % 2 == 0) { 
        Node* prevMiddle = head;
        for (int i = 0; i < middle - 1; i++) {
            prevMiddle = prevMiddle->next;
        }
        printf("%d (Position: %d)\n", prevMiddle->marks, middle);
        printf("%d (Position: %d)\n", current->marks, middle + 1);
    } else {
        printf("%d (Position: %d)\n", current->marks, middle + 1);
    }
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
