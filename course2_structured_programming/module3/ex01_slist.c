/* 
    The ADT List
    April 6, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {
    int data;
    struct list *next;
} list;

// Return 1 if the list is empty
int is_empty(const list *l) {
    return (l == NULL);
}

list* create_list(int d) {
    list* head = malloc(sizeof(list));
    if (head == NULL) {
        fprintf(stderr, "Error: malloc\n");
        exit(EXIT_FAILURE);
    }
    head -> data = d;
    head -> next =  NULL;
    return head;
}

list* add_to_front(int d, list* h) {
    list* head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(const int d[], int size) {
    if (d == NULL || size <= 0) return NULL;

    list* head = create_list(d[0]);
    int i;
    for(i=1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(const list *h, const char *title) {
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d", h->data);
        if (h->next != NULL) {
            printf(" -> ");
        }
        h = h->next;
    }
    printf("\n");
}

void free_list(list *h) {
    while (h != NULL) {
        list *temp = h;
        h = h->next;
        free(temp);
    }
}

int main() {
    int data[8] = {1,3,5,7,9,11,13,15};
    list* head = array_to_list(data, 8);
    print_list(head, "Array into list");
    
    free_list(head);
    
    return 0;
}