#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int id;
    char name[50];
    int age;
} User;

void createUser(const char *filename, User user) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

void readUsers(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("ID\tName\tAge\n");
    while (fgets(line, sizeof(line), file)) {
        User user;
        sscanf(line, "%d,%[^,],%d", &user.id, user.name, &user.age);
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void updateUser(const char *filename, int id, User newUser) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        User user;
        sscanf(line, "%d,%[^,],%d", &user.id, user.name, &user.age);
        if (user.id == id) {
            fprintf(tempFile, "%d,%s,%d\n", newUser.id, newUser.name, newUser.age);
            found = 1;
        } else {
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);
        rename("temp.txt", filename);
        printf("User updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

void deleteUser(const char *filename, int id) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        User user;
        sscanf(line, "%d,%[^,],%d", &user.id, user.name, &user.age);
        if (user.id != id) {
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);
        rename("temp.txt", filename);
        printf("User deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

int main() {
    const char *filename = "users.txt";
    int choice, id, age;
    char name[50];
    User user;

    while (1) {
        printf("\n1. Add User\n2. Display Users\n3. Update User\n4. Delete User\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &user.id);
                printf("Enter Name: ");
                scanf("%s", user.name);
                printf("Enter Age: ");
                scanf("%d", &user.age);
                createUser(filename, user);
                break;
            case 2:
                readUsers(filename);
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new ID: ");
                scanf("%d", &user.id);
                printf("Enter new Name: ");
                scanf("%s", user.name);
                printf("Enter new Age: ");
                scanf("%d", &user.age);
                updateUser(filename, id, user);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteUser(filename, id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
