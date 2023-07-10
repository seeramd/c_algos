#include <string.h>
#include "../include/lists.h"
#include "../include/my_search.h"
#include "../include/my_sort.h"
#include "../include/my_recurse.h"

int main(int argc, char** argv) {
    int numbers[8] = {20, 30, 127, 11, 320, 50, 99, 100};

    // creating linked list from array and printing
    node_t * head = init_linked_list(numbers, 8);
    print_linked_list(&head, 0);
    printf("Length of linked list: %d\n", linked_list_len(&head));

    putchar('\n');

    // printing a linked list backwards
    node_t * tail = get_tail(&head);
    print_linked_list(&tail, 1);
    printf("Length of linked list: %d\n", linked_list_len(&head));

    putchar('\n');

    // sorting linked list with selection sort (moving data values)
    selection_sort_data(&head);
    print_linked_list(&head, 0);
    printf("Length of linked list: %d\n", linked_list_len(&head));

    putchar('\n');

    // printing sorted linked list backwards
    print_linked_list(&tail, 1);
    printf("Length of linked list: %d\n", linked_list_len(&head));

    putchar('\n');

    // sorting int array with selection sort
    selection_sort_array(numbers, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}
