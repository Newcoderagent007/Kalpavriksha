#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int id;
    char name[50];
    int age;
} User;

int isValidNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int isUniqueId(const char *filename, int id) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 1; // File doesn't exist, so ID is unique
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        User user;
        sscanf(line, "%d,%[^,],%d", &user.id, user.name, &user.age);
        if (user.id == id) {
            fclose(file);
            return 0; // ID is not unique
        }
    }

    fclose(file);
    return 1; // ID is unique
}

void createUser(const char *filename, User user) {
    if (!isUniqueId(filename, user.id)) {
        printf("Error: User ID %d already exists.\n", user.id);
        return;
    }

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
    FILE *file = fopen(filename, "r");
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
    FILE *file = fopen(filename, "r");
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

int getIntegerInput() {
    char input[10];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    if (!isValidNumber(input)) {
        return -1;
    }
    return atoi(input);
}

void getStringInput(char *str, int length) {
    fgets(str, length, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
}

int main() {
    const char *filename = "users.txt";
    int choice, id, age;
    char name[50];
    User user;

    while (1) {
        printf("\n1. Add User\n2. Display Users\n3. Update User\n4. Delete User\n5. Exit\nEnter your choice: ");
        choice = getIntegerInput();
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                user.id = getIntegerInput();
                if (user.id <= 0) {
                    printf("Invalid ID. Please enter a positive integer.\n");
                    continue;
                }

                printf("Enter Name: ");
                getStringInput(user.name, sizeof(user.name));

                printf("Enter Age: ");
                user.age = getIntegerInput();
                if (user.age <= 0) {
                    printf("Invalid Age. Please enter a positive integer.\n");
                    continue;
                }

                createUser(filename, user);
                break;

            case 2:
                readUsers(filename);
                break;

            case 3:
                printf("Enter ID to update: ");
                id = getIntegerInput();
                if (id <= 0) {
                    printf("Invalid ID. Please enter a positive integer.\n");
                    continue;
                }

                printf("Enter new ID: ");
                user.id = getIntegerInput();
                if (user.id <= 0) {
                    printf("Invalid ID. Please enter a positive integer.\n");
                    continue;
                }

                printf("Enter new Name: ");
                getStringInput(user.name, sizeof(user.name));

                printf("Enter new Age: ");
                user.age = getIntegerInput();
                if (user.age <= 0) {
                    printf("Invalid Age. Please enter a positive integer.\n");
                    continue;
                }

                updateUser(filename, id, user);
                break;

            case 4:
                printf("Enter ID to delete: ");
                id = getIntegerInput();
                if (id <= 0) {
                    printf("Invalid ID. Please enter a positive integer.\n");
                    continue;
                }

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
