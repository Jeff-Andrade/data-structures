#ifndef LISTNODE_H
#define LISTNODE_H


typedef struct ListNode{
    void* data;
    struct ListNode* next;
}ListNode;

ListNode* node_get_next(ListNode* node);

void* node_get_data(ListNode* node);

void destroy_node(ListNode* node);


#endif //LISTNODE_H
