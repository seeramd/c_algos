#include "my_recurse.h"

int recursive_sum(int arr[], int len) {
    if (len == 0)
        return 0;
    else
        return recursive_sum(arr, len - 1) + arr[len - 1]; 
}

int recursive_max(int arr[], int len) {
    if (len == 1)
        return arr[len - 1]; 
    else {
        int tail = arr[len - 1]; 
        int head = recursive_max(arr,len - 1); 
        if (tail > head)
            return tail;
        else
            return head;
    }   
}
