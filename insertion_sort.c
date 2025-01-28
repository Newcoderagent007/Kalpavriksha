#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node *selectionsort(Node *head){
    for(Node* start = head; start != NULL; start = start->next){
        Node *min = start;
        for(Node *current = start->next; current != NULL; current = current->next){
            if(current->data < min->data){
                min  = current;
            }
        }
        if(min != start){
            int temp = start->data;
            start->data = min->data;
            min->data = temp;
        }
    }
    return head;
}

void printlist(Node* node){
    Node *temp = node;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node * createnode(int val){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

int main() {
    int n;
    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter stock value for each day:\n");
    for (int i = 0; i < 7; i++) {
        int value;
        printf("value for week %d: ", i + 1);
        scanf("%d", &value);

        Node* newNode = createnode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    selectionsort(head);

    printf("\nSORTED VALUE OF STOCK IS (ascending order):\n");
    printlist(head);

    // Find the minimum value after sorting
    int min_val = head->data; // Assume the first node is the minimum initially
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data < min_val) {
            min_val = temp->data;
        }
        temp = temp->next;
    }

    printf("Stock was least priced is : %d\n", min_val); 
    return 0;
}
