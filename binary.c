#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[100];
    char isbn[20];
    struct Node* next;
} Node;

Node* create_node(const char* title, const char* isbn) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->title, title);
    strcpy(new_node->isbn, isbn);
    new_node->next = NULL;
    return new_node;
}

void sorted_insert(Node** head, const char* title, const char* isbn) {
    Node* new_node = create_node(title, isbn);
    if (*head == NULL || strcmp((*head)->isbn, isbn) > 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL && strcmp(current->next->isbn, isbn) <= 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

Node* find_middle(Node* start, Node* end) {
    if (start == NULL) {
        return NULL;
    }
    Node* slow = start;
    Node* fast = start->next;
    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node* binary_search(Node* head, const char* isbn) {
    Node* start = head;
    Node* end = NULL;

    while (end != start) {
        Node* mid_node = find_middle(start, end);
        if (mid_node == NULL) {
            return NULL;
        }
        int cmp = strcmp(mid_node->isbn, isbn);
        if (cmp == 0) {
            return mid_node;
        } else if (cmp < 0) {
            start = mid_node->next;
        } else {
            end = mid_node;
        }
    }
    return NULL;
}

void print_list(Node* head) {
    Node* current = head;
    while (current) {
        printf("Title: %s, ISBN: %s -> ", current->title, current->isbn);
        current = current->next;
    }
    printf("None\n");
}

int main() {
    Node* book_list = NULL;
    sorted_insert(&book_list, "Introduction to Algorithms", "0262033844");
    sorted_insert(&book_list, "The C Programming Language", "0131103628");
    sorted_insert(&book_list, "Design Patterns", "0201633612");
    sorted_insert(&book_list, "Clean Code", "0132350882");
    sorted_insert(&book_list, "The Pragmatic Programmer", "020161622X");

    char target_isbn[] = "0132350882";
    Node* result = binary_search(book_list, target_isbn);

    if (result != NULL) {
        printf("Book found: Title: %s, ISBN: %s\n", result->title, result->isbn);
    } else {
        printf("Book with ISBN %s not found.\n", target_isbn);
    }

    return 0;
}
