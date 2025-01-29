#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

Node* get_tail(Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node* partition(Node* head, Node* end, Node** new_head, Node** new_end) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* curr = head;
    Node* tail = pivot;

    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*new_head == NULL) {
                *new_head = curr;
            }
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) {
                prev->next = curr->next;
            }
            Node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*new_head == NULL) {
        *new_head = pivot;
    }
    *new_end = tail;
    return pivot;
}

Node* quick_sort_recursive(Node* head, Node* end) {
    if (!head || head == end) {
        return head;
    }

    Node* new_head = NULL;
    Node* new_end = NULL;

    Node* pivot = partition(head, end, &new_head, &new_end);

    if (new_head != pivot) {
        Node* temp = new_head;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;

        new_head = quick_sort_recursive(new_head, temp);

        temp = get_tail(new_head);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recursive(pivot->next, new_end);

    return new_head;
}

void quick_sort(Node** head_ref) {
    (*head_ref) = quick_sort_recursive(*head_ref, get_tail(*head_ref));
}

void print_list(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* list = NULL;

    append(&list, 3);
    append(&list, 6);
    append(&list, 8);
    append(&list, 10);
    append(&list, 1);
    append(&list, 4);
    append(&list, 7);

    printf("Original List: \n");
    print_list(list);

    quick_sort(&list);

    printf("Sorted List: \n");
    print_list(list);

    return 0;
}
