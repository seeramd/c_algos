#include "my_search.h"

int bin_search(int arr[], int len, int target_value) {
    int min = 0;
    int max = len - 1;
    int mid, guess;

    while(min <= max) {
        // Quick ceiling for dividing ints by 2
        mid = (min + max + 1) / 2;
        guess = arr[mid];
        if (guess == target_value)
            return mid;
        if (guess > target_value)
            max = mid - 1;
        else
            min = mid + 1;
    }   
    return -1; 
}      
