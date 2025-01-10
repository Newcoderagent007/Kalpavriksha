#include <stdio.h>
#include <stdlib.h>

int main() {
    int total_number_of_shelves, total_number_of_queries;
    
    scanf("%d %d", &total_number_of_shelves, &total_number_of_queries);

    int *total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
 
    int **total_number_of_pages = malloc(total_number_of_shelves * sizeof(int *));
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = NULL;
    }
    
    for (int i = 0; i < total_number_of_queries; i++) {
        int query_type, x, y;
        scanf("%d", &query_type);
        
        if (query_type == 1) {
            scanf("%d %d", &x, &y);
           
            total_number_of_books[x]++;
           
            total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;
        } else if (query_type == 2) {
            scanf("%d %d", &x, &y);
            
            printf("%d\n", total_number_of_pages[x][y]);
        } else if (query_type == 3) {
            scanf("%d", &x);

            printf("%d\n", total_number_of_books[x]);
        }
    }
    
   
    for (int i = 0; i < total_number_of_shelves; i++) {
        free(total_number_of_pages[i]);
    }
    free(total_number_of_pages);
    free(total_number_of_books);
    
    return 0;
}
