#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* splitLinkedList(Node* head) { 
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

Node* merge(Node* first, Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

Node* MergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* second = splitLinkedList(head); // Use the new function name

    head = MergeSort(head);
    second = MergeSort(second);

    return merge(head, second);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = MergeSort(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
