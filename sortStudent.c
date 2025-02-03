#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    int marks;
    int roll;
    struct node *next;
} node;

node *head = NULL;

node *createnode(char name[], int marks, int roll) {
    node *newnode = (node *)malloc(sizeof(node));
    strcpy(newnode->name, name);
    newnode->marks = marks;
    newnode->roll = roll;
    newnode->next = NULL;
    return newnode;
}

void insertnode(char name[], int marks, int roll) {
    node *newnode = createnode(name, marks, roll);
    
    if (head == NULL) {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

node* split(node *head) {
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *second = slow->next;
    slow->next = NULL;
    return second;
}

node* merge(node *first, node *second) {
    if (!first) return second;
    if (!second) return first;

    node *res = NULL;
    if (first->marks > second->marks || (first->marks == second->marks && first->roll < second->roll)) {
        res = first;
        res->next = merge(first->next, second);
    } else {
        res = second;
        res->next = merge(first, second->next);
    }
    return res;
}

node* mergesort(node *head) {
    if (!head || !head->next) return head;
    node *second = split(head);
    head = mergesort(head);
    second = mergesort(second);
    return merge(head, second);
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%s %d %d\n", temp->name, temp->marks, temp->roll);
        temp = temp->next;
    }
}

int main() {
    int n;
    char str[100];
    int marks;
    int roll;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();  
    
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s",&str);
        printf("Enter marks and roll number: ");
        scanf("%d %d", &marks, &roll);
        getchar();  
        insertnode(str, marks, roll);
    }
    
    head = mergesort(head);

    printf("\nSorted list of students:\n");
    printList(head);

    return 0;
}
