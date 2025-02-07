#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20 

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(HashTable* ht, int key, int value) {
    int index = hash(key);
    Node* newNode = createNode(key, value);

    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        Node* current = ht->table[index];
        while (current->next != NULL && current->key != key) {
            current = current->next;
        }
        if (current->key == key) {
            current->value = value;
        } else {
            current->next = newNode;
        }
    }
}

int search(HashTable* ht, int key) {
    int index = hash(key);
    Node* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; 
}

void delete(HashTable* ht, int key) {
    int index = hash(key);
    Node* current = ht->table[index];
    Node* prev = NULL;

    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }

    if (prev == NULL) {
        ht->table[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Key %d deleted.\n", key);
}

void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        if (current != NULL) {
            printf("Index %d: ", i);
            while (current != NULL) {
                printf("(%d, %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    HashTable ht;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht.table[i] = NULL;
    }

    int choice, key, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert (Put)\n");
        printf("2. Search (Get)\n");
        printf("3. Delete (Remove)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&ht, key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(&ht, key);
                if (value != -1) {
                    printf("Value: %d\n", value);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(&ht, key);
                break;
            case 4:
                display(&ht);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
