#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Node
// {
//     char* data;
//     struct Node* next;
// }node_t;

// node_t* list_init(char* data)
// {
//     node_t *head;
//     head = malloc(sizeof(node_t));
//     head->data = malloc(sizeof(char)*(strlen(data)+1));
//     head->next = NULL;
//     strcpy(head->data, data);
//     printf("First Node data: %s", head->data);
//     return head;
// }

// void push(node_t **head, char* data)
// {
//     node_t* tmp = malloc(sizeof(node_t));
//     tmp->data = malloc(sizeof(char)*(strlen(data)+1));
//     strcpy(tmp->data, data);
//     printf("Pushed data: %s", tmp->data);
//     tmp->next = *head;
//     *head = tmp;
// }

// void 

// void print_list(node_t* head)
// {
//     node_t* current = head;
//     while(current)
//     {
//         printf("%s", current->data);
//         current = current->next;
//     }
// }

//Doubly-Linked List
typedef struct Node
{
    char *data;
    struct Node* prev;
    struct Node* next;
}

struct DoublyLinkedList
{
    struct Node* head;
    struct Node* tail;
}

void create_list()
{

}

DoublyLinkedList* sort(struct DoublyLinkedList* list)
{
    tmp_list;
    if(!list)
    {
        return list;
    }
    //selection sort
    for(struct Node* it = list->head; it != list->tail; it = it->next)
    {
        for(struct Node* init = it; init != list->tail; init = init->next)
        {
            if(strcmp(it->data, init->data))
            {
                struct Node* tmp;
                tmp->data = it->data;
                it->data = init->data;
                init->data = tmp->data;
            }
        }
    }
    return list;
}

void push(struct DoublyLinkedList* list, char* data)
{
    struct Node* newNode =  malloc(sizeof(struct Node));
    newNode->data = malloc(sizeof(char)*(strlen(data)+1));
    strcpy(newNode->data, data);
    newNode->next = list->head;
    newNode->prev = NULL;
    if(list->head)
    {
        list->head->prev = newNode;
    }
    list->head = newNode;
}

int main()
{
    //singly-linked list
    // node_t* head;
    // int max_len = 10;
    // char a[max_len], b[max_len];
    // printf("Enter the first phrase you want to add: ");
    // fgets(a, sizeof(a), stdin);
    // head = list_init(a);
    // printf("Enter the second phrase you want to add: ");
    // fgets(b, sizeof(b), stdin);
    // push(&head, b);
    // print_list(head);
}

