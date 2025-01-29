#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    int roll_number;
    struct Node* next;
} Node;

Node* create_node(const char* name, int roll_number) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->roll_number = roll_number;
    new_node->next = NULL;
    return new_node;
}

void append(Node** head, const char* name, int roll_number) {
    Node* new_node = create_node(name, roll_number);
    if (!(*head)) {
        *head = new_node;
        return;
    }
    Node* last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
}

Node* linear_search(Node* head, int roll_number) {
    Node* current = head;
    while (current) {
        if (current->roll_number == roll_number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_list(Node* head) {
    Node* current = head;
    while (current) {
        printf("Name: %s, Roll Number: %d -> ", current->name, current->roll_number);
        current = current->next;
    }
    printf("None\n");
}

int main() {
    Node* student_list = NULL;
    append(&student_list, "Alice", 101);
    append(&student_list, "Bob", 102);
    append(&student_list, "Charlie", 103);
    append(&student_list, "David", 104);
    append(&student_list, "Eve", 105);

    int target_roll_number = 103;
    Node* result = linear_search(student_list, target_roll_number);

    if (result != NULL) {
        printf("Student found: Name: %s, Roll Number: %d\n", result->name, result->roll_number);
    } else {
        printf("Student with Roll Number %d not found.\n", target_roll_number);
    }

    return 0;
}
