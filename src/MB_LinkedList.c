#include "MB_LinkedList.h"

// void MB_LinkedList_Init(MB_LinkedList *list){
//   list->size = 0;
// }
//
// int MB_LinkedList_Push(MB_LinkedList *list, void *new_data, size_t data_size){
//   // Allocate memory for node
//   MB_LinkedListNode *new_node = malloc(sizeof(MB_LinkedListNode));
//
//   new_node->data = malloc(data_size);
//   new_node->next = list->head;
//
//   // Copy contents of new_data to newly allocated memory.
//   // Assumption: char takes 1 byte.
//   int i;
//   for (i=0; i < data_size; i++){
//     *(char *)(new_node->data + i) = *(char *)(new_data + i);
//   }
//
//   // Change head pointer as new node is added at the beginning
//   list->head = new_node;
//   list->size++;
// }

// #include "list.h"
#include <stdio.h>
#include <stdlib.h>

void mb_linkedlist_append_node(mb_linkedlist *list, mb_linkedlist_Node *append)
{
    if(list->head == NULL)
    {
        // Initialize the list
        list->head = append;
        list->tail = append;
        list->head->next = append;
        list->tail->prev = append;
        list->size = 1;
    }
    else
    {
        // Append node to the tail.
        list->tail->next = append;
        append->prev = list->tail;
        list->tail = append;
        list->size++;
    }
}

double mb_linkedlist_pop_head(mb_linkedlist *list)
{
    double headVal = list->head->val;
    list->head = list->head->next;
    list->size--;
    return headVal;
}


void mb_linkedlist_print(mb_linkedlist *list)
{
    if(list == NULL)
    {
        printf("List Empty!\n");
    }
    else
    {
        printf("List Size: %d\n", list->size);
        if(list->size == 1)
        {
            printf("Val: %lf\n", list->head->val);
        }
        else
        {
            mb_linkedlist_Node *curr = list->head;
            while(curr != NULL)
            {
                printf("Val: %lf\n", curr->val);
                curr = curr->next;
            }
        }
    }
}

/*

    FOR TESTING ONLY

*/
// int main(){
//     printf("Starting\n");
//     // Make list
//     struct list *my_list = malloc(sizeof(struct list));
//     // New node
//     struct node *first_node = malloc(sizeof(struct node));
//     first_node->val = 98.0;
//     list_append_node(my_list, first_node);
//
//     struct node *second_node = malloc(sizeof(struct node));
//     second_node->val = 56.0;
//     list_append_node(my_list, second_node);
//
//     struct node *third_node = malloc(sizeof(struct node));
//     third_node->val = 367.0;
//     list_append_node(my_list, third_node);
//
//     struct node *fourth_node = malloc(sizeof(struct node));
//     fourth_node->val = 726.0;
//     list_append_node(my_list, fourth_node);
//
//     list_print(my_list);
//
//     printf("Done\n");
//     return 0;
// }
