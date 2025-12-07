#include <stdio.h>
#include <stdlib.h>
#include "LinkedList/list.h"

void stress_test() {
    printf("=== Stress Test Start ===\n");

    // Initialize empty list with one element
    int* a = malloc(sizeof(int)); *a = 1;
    LinkedList* list = initialize_list(a); // [1]

    // Remove head repeatedly (single-element removal)
    list_remove(list, 0); // list empty now
    printf("After removing the only element, length = %d\n", list_length(list));

    // Remove from empty list (should be safe)
    list_remove(list, 0);
    list_remove(list, 10);
    printf("After removing from empty list, length = %d\n", list_length(list));

    // Insert at head, tail, middle repeatedly
    for (int i = 0; i < 5; i++) {
        int* n = malloc(sizeof(int)); *n = i*10;
        list_insert(list, n, 0); // always at head
    } // [40,30,20,10,0]

    for (int i = 5; i < 10; i++) {
        int* n = malloc(sizeof(int)); *n = i*10;
        list_insert(list, n, list->length); // always at tail
    } // [40,30,20,10,0,50,60,70,80,90]

    // Remove middle elements repeatedly
    for (int i = 0; i < 3; i++) {
        list_remove(list, 3); // remove index 3 repeatedly
    }

    // Insert at invalid indices (should be no-ops)
    int* x = malloc(sizeof(int)); *x = 999;
    list_insert(list, x, -1);
    list_insert(list, x, list->length + 5);

    // Remove at invalid indices (should be no-ops)
    list_remove(list, -2);
    list_remove(list, 100);

    // Final state
    list_iterate(list);

    // Free remaining data
    ListNode* node = list->head;
    while (node) {
        free(node->data);
        node = node->next;
    }

    printf("=== Stress Test End ===\n");
}

int main() {
    stress_test();
    return 0;
}
