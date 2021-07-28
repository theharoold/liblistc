#include "include/list.h"

List* list_init(int data) {
    List* head = malloc(sizeof(List));

    // Checking if malloc failed is left to the user
    if (head != NULL) {
        head->data = data;
        head->next = NULL;
    }
    return head;
} 

// Adds a node to the list, with the given data integer
int list_add(List* head, int data) {
    List *temp = head;

    // Iterate to the last element of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Function returns -1 if malloc fails, and 0 if it finishes successfully
    temp->next = malloc(sizeof(List));
    if (temp->next == NULL) 
        return -1;

    temp = temp->next;
    temp->data = data;
    temp->next = NULL;
    return 0;
}


int list_remove_by_index(List** head, int position) {
    List *temp = *head;

    if (*head == NULL) {
        return -1;
    }

    if (position < 0)
        return -1;
    else if (position == 0) {
        *head = (*head)->next;
        free (temp);
        return 0;
    } 
    else {
        int counter = 1;
        List *previous = (*head);
        temp = (*head)->next; 
        while (counter < position && temp != NULL) {
            counter++;
            previous = previous->next;
            temp = temp->next; 
        }
        
        // If the counter is less than the position, then the temp variable is NULL
        if (counter < position && temp == NULL) {
            return -1;
        } 

        // If the counter is equal to position and temp is NULL, 
        // That means temp is the very last node in the list
        else if (counter == position && temp == NULL) {
            previous->next = NULL;
            return 0;
        }

        // In every other case, it's business as usual
        else {
            previous->next = temp->next;
            free(temp);
            return 0;
        }

    }
}