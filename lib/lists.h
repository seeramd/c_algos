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

node_t * init_linked_list(int arr[], int len) {
    node_t * head = create_node(arr[0]);
    for (int i = 1;i < len;i++) {
        append_node(&head, arr[i]);
    }
    return head;
}

void destroy_node(node_t * node, node_t** head) {
    if (*head == NULL)
        return;
    node_t * ptr = *head;
    while(ptr->next != node)
        ptr = ptr->next;
    ptr->next = node->next;
    node->next->prev = ptr;
    free(node);
}

node_t * create_node(int value) {
    node_t * node = (node_t *) malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void append_node(node_t** head, int value) {
    node_t * new_node = create_node(value);
    node_t * ptr;
    if (*head == NULL)
        *head = new_node;
    else {
        ptr = *head;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}
node_t * prepend_node(node_t** head, int value) {
    node_t * new_node = create_node(value);
    node_t * ptr;
    if (*head == NULL)
        return new_node;
    else {
        ptr = *head;
        new_node->next = ptr;
        ptr->prev = new_node;
        return new_node;
    }
}

void print_linked_list(node_t** start, int direction) {
    node_t * ptr = *start;
    if (direction == 0) {
        printf("%d\n", ptr->value);
        while(ptr->next) {
            ptr = ptr->next;
            printf("%d\n", ptr->value);
        }
    }
    else {
        printf("%d\n", ptr->value);
        while(ptr->prev) {
            ptr = ptr->prev;
            printf("%d\n", ptr->value);
        }
    }
}

int linked_list_len(node_t** head) {
    node_t * ptr = *head;
    int counter = 1;
    while(ptr->next) {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

node_t * get_tail(node_t** head) {
    node_t * ptr = *head;
    while(ptr->next)
        ptr = ptr->next;
    return ptr;
}

