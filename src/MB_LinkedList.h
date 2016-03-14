#ifndef MB_LINKED_LIST
#define MB_LINKED_LIST

#include<stdio.h>
#include<stdlib.h>

// typedef struct MB_LinkedListNode_t MB_LinkedListNode;
// struct MB_LinkedListNode_t{
//   void *data;
//   MB_LinkedListNode *next;
// };
//
// struct MB_LinkedList_t{
//   MB_LinkedListNode *head;
//   int size;
// }typedef MB_LinkedList;
//
//
// void MB_LinkedList_Init(MB_LinkedList *list);
//
// int MB_LinkedList_Push(MB_LinkedList *list, void *new_data, size_t data_size);

typedef struct mb_linkedlist_Node_t mb_linkedlist_Node;
struct mb_linkedlist_Node_t {
    double val;
    mb_linkedlist_Node *next;
    mb_linkedlist_Node *prev;
};

struct mb_linkedlist_t {
    int size;
    mb_linkedlist_Node *head;
    mb_linkedlist_Node *tail;
}typedef mb_linkedlist;


void mb_linkedlist_append_node(mb_linkedlist *list, mb_linkedlist_Node *append);
double mb_linkedlist_pop_head(mb_linkedlist *list);
void mb_linkedlist_print(mb_linkedlist *list);




#endif // MB_LINKED_LIST
