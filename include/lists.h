#ifndef LISTS_H
#define LISTS_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node * next;
    struct node * prev;
} node_t;

node_t * create_node(int value);
void append_node(node_t** head, int value);
void destroy_node(node_t * node, node_t** head);
void print_linked_list(node_t** start, int direction);
node_t * prepend_node(node_t** head, int value);
node_t * init_linked_list(int arr[], int len);
node_t * get_tail(node_t** head);
int linked_list_len(node_t** head);
#endif
