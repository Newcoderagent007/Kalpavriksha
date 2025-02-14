#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashMapEntry;

typedef struct {
    HashMapEntry *entries;
    int capacity;
    int size;
} HashMap;

HashMap *createHashMap(int capacity) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->capacity = capacity;
    map->size = 0;
    map->entries = (HashMapEntry *)malloc(sizeof(HashMapEntry) * capacity);
    return map;
}

int hash(int key, int capacity) {
    return abs(key) % capacity; 
}

void insert(HashMap *map, int key, int value) {
    int index = hash(key, map->capacity);
    while (map->entries[index].key != 0 && map->entries[index].key != key) {
        index = (index + 1) % map->capacity;
    }

    map->entries[index].key = key;
    map->entries[index].value = value;
    map->size++;
}

int search(HashMap *map, int key) {
    int index = hash(key, map->capacity);

    while (map->entries[index].key != 0) {
        if (map->entries[index].key == key) {
            return map->entries[index].value;
        }
        index = (index + 1) % map->capacity;
    }

    return -1; 
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   
    HashMap *map = createHashMap(numsSize * 2); 

    int *result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 0; 

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = search(map, complement);

        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            break; 
        }

        insert(map, nums[i], i);
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int *nums = (int *)malloc(sizeof(int) * n); 

    if (nums == NULL) { 
        perror("Memory allocation failed");
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]); 
    }

    int numsSize = n; 
    int target;
    scanf("%d", &target);
    int returnSize;

    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("[%d, %d]\n", result[0], result[1]);
    } else {
        printf("No two sum solution found.\n");
    }

    return 0;
}
