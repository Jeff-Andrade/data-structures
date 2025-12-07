#ifndef LIST_H
#define LIST_H

#include "listnode.h"

typedef struct LinkedList{
    ListNode* head;
    int length;
}LinkedList;

LinkedList* initialize_list(void* data);

void list_insert(LinkedList* list,void* data,int index); //done

void list_remove(LinkedList* list,int index);

ListNode* list_get(LinkedList* list, int index); //done

void list_iterate(LinkedList* list);

int list_length(LinkedList* list);

#endif //LIST_H
