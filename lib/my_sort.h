#ifndef LISTS_H
#include "lists.h"
#define LISTS_H

int array_minimum(int arr[], int len);
void selection_sort_array(int arr[], int len);
void selection_sort_data(node_t** head);
void selection_sort_nodes(node_t * head);

int array_minimum(int arr[], int len) {
    int min = arr[0];
    for (int i = 1; i < len;i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void selection_sort_data(node_t** head) {
    node_t * ptr = *head;
    int temp;
    while(ptr->next) {
        node_t * min = ptr;
        node_t * r = ptr->next;
        while(r) {
            if (min->value > r->value) {
                min = r;
            }
            r = r->next;
        }
        if (min != ptr) {
            temp = min->value;
            min->value = ptr->value;
            ptr->value = temp;
        }
        ptr = ptr->next;
    }
}

void selection_sort_array(int arr[], int len) {
    int i = 0;
    int current, min, j, temp, mindex;
    while (i < len) {
        mindex = i;
        j = 1;
        min = arr[i];
        while ((i + j) < len) {
            current = arr[i + j];
            if (min > current) {
                min = current;
                mindex = i + j;
            }
            j++;
        }
        if (mindex != i) {
            temp = min; 
            arr[mindex] = arr[i];
            arr[i] = min;
        }
        i++;
    }
}
#endif
