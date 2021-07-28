#include "include/list.h"

// Returns 0 on success, -1 on failure
int stack_push(List **head, int data) {
    List *new_node = malloc(sizeof(List));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = *head;
        *head = new_node;
        return 0;
    }
    return -1;
}

int stack_pop(List **head) {
    int data = (*head)->data;
    List *temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}
