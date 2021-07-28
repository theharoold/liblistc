#ifndef LIBLISTC_H
#define LIBLISTC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct listc {
    int data;
    struct listc *next;
} List;

List* list_init(int data);
int list_add(List* head, int data);
int list_remove_by_index(List** head, int position);
int stack_push(List **head, int data);
int stack_pop(List **head);

#define stack_init(x) list_init(x)

#endif