#include "list.h"
#include "listnode.h"

#include <stdlib.h>
#include <stdio.h>

LinkedList* initialize_list(void* data) {
    LinkedList* list = malloc(sizeof(LinkedList));
    ListNode* node = malloc(sizeof(ListNode));

    node->data = data;
    node->next = NULL;

    list->head = node;
    list->length = 1;

    return list;
}

ListNode* list_get(LinkedList* list, int index) {

    if (index > list->length - 1 || list->length <= 0) {
        return NULL;
    }

    if (index == 0) {
        return list->head;
    }

    ListNode* current_node = list->head;

    for (int i = 0; i < index; i ++) {
        current_node = current_node->next;
    }
    return current_node;

}


void list_insert(LinkedList* list,void* data,int index) {

    if (index > list->length || index < 0) {
        return;
    }

    ListNode* node = malloc(sizeof(ListNode));

    node->data = data;

    if (index == 0) {
        node->next = list->head;
        list->head = node;
        list->length++;
    }

    else if (index == list->length) {
        ListNode* current_node = list_get(list, list->length -1);
        node->next = NULL;
        current_node -> next = node;
        list->length++;
    }

    else if (index > 0){
        ListNode* previous_node = list_get(list, index-1);
        ListNode* current_node = previous_node->next;
        previous_node->next = node;
        node->next = current_node;
        list->length++;
    }

}

void list_remove(LinkedList* list,int index) {
    if (index >= list->length || index < 0) {
        return;
    }

    if (index == 0) {
        if (list->length == 1) {
            destroy_node(list->head);
            list->head = NULL;
            list->length--;

        }
        else {
            ListNode* previous_head = list->head;
            list->head = previous_head->next;
            destroy_node(previous_head);
            list->length--;
        }
    }


    else if (index == list->length - 1) {
        ListNode* previous_node = list_get(list, index - 1);
        ListNode* current_node = previous_node->next;
        previous_node->next = NULL;
        destroy_node(current_node);
        list->length--;
    }

    else if (index > 0) {
        ListNode* previous_node = list_get(list, index - 1);
        ListNode* current_node = previous_node->next;
        ListNode* next_node = current_node->next;
        previous_node->next = next_node;
        destroy_node(current_node);
        list->length--;

    }
}


void list_iterate(LinkedList* list) {

    ListNode* current_node = list->head;

    for (int i = 0; i < list->length; i ++) {
        int* value = node_get_data(current_node);
        printf("Element at index [%d] has value %d\n", i, *value);
        current_node = current_node->next;
    }
}


int list_length(LinkedList* list) {
    return list->length;
}