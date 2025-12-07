#include <stdlib.h>

#include "listnode.h"

ListNode* node_get_next(ListNode* node) {
    return node->next;
}

void* node_get_data(ListNode* node) {
    return node->data;
}

void destroy_node(ListNode* node) {
    free(node->data);
    free(node);
}