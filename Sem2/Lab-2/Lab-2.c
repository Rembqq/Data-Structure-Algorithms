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
}node_t;

node_t* init_list(char* data)
{
    node_t *newNode =  malloc(sizeof(node_t));
    newNode->data = malloc(sizeof(char)*(strlen(data)+1));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// void swap_p(node_t** str1, node_t** str2)
// {
//     // node_t** tmp;

//     // tmp = str1;
//     // str1 = str2;
//     // str2 = tmp;
//     node_t* tmp;
    
//     tmp->data = (*str1)->data;
//     (*str1)->data = (*str2)->data;
//     (*str2)->data = tmp->data;
// }

void swap_p(node_t **head, node_t *node1, node_t *node2) {
    // if (node1 == node2) return;

    // if (node1->prev != NULL) {
    //     node1->prev->next = node2;
    // } else {
    //     *head = node2;
    // }

    // if (node2->prev != NULL) {
    //     node2->prev->next = node1;
    // } else {
    //     *head = node1;
    // }

    // node_t *temp = node1->prev;
    // node1->prev = node2->prev;
    // node2->prev = temp;

    // temp = node1->next;
    // node1->next = node2->next;
    // node2->next = temp;

    char *tempData = node1->data;
    node1->data = node2->data;
    node2->data = tempData;
}

void sort_list(node_t **head)
{
    if (*head == NULL || (*head)->next == NULL) return;
    node_t* min_node;
    //selection sort
    for(node_t* it = *head; it->next != NULL; it = it->next)
    {
        min_node = it;
        for(node_t* init = it->next; init != NULL; init = init->next)
        {
            if((strcmp(min_node->data, init->data) > 0 && 
                strlen(min_node->data) == strlen(init->data)) ||
                strlen(min_node->data) > strlen(init->data))
            {
                min_node = init;
            }
        }
        if(min_node != it)
        {
            swap_p(head, min_node, it);
        }
    }
}

//adds on the first place
void push(node_t** head, char* data)
{   
    node_t* newNode =  malloc(sizeof(node_t));
    newNode->data = malloc(sizeof(char)*(strlen(data)+1));
    strcpy(newNode->data, data);
    if(*head != NULL)
    {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    newNode->prev = NULL;
    *head = newNode;
}

void print_list(node_t* head)
{
    node_t* current = head;
    while(current)
    {
        printf("%s<->", current->data);
        current = current->next;
    }printf("\n");
}
void free_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
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
    //doubly-linked-list


    //We later wont be able to change our data if it is not initialized on heap 
    //So Firstly I try to create a static array for more comfortable initialization 

    // The ten in the first[] is the amount of words while eleven
    // in the second []is the amount of 
    // symbols in each word + 1(\0) 

    // char st_keys[10][11] = {"Hi", "My", "Name", "Is", "Marcus", "Aurelius", 
    // "I", "Live", "At", "JustKidding"};

    // char st_keys[10][11] = {"88888888", "333", "7777777", "666666", "1", "22", 
    // "1010101010", "999999999", "4444", "55555"};
    

    // char**keys;
    // // here I create an array on heap
    // keys = malloc(sizeof(char*) * words);
    // for(int i = 0; i < words; ++i)
    // {
    //     keys[i] = malloc(sizeof(char) * (word_max_len+1));
    //     strcpy(keys[i], st_keys[i]);
    // }
    
    // here the dynamic array is passed to the linked list
    // for(int i = 1; i < words; ++i)
    // {
    //     push(&f_node, st_keys[i]);
    // }

    node_t* f_node;
    const int word_max_len = 10;
    int n;
    printf("Enter the amount of words in list: ");
    scanf_s("%d", &n, word_max_len);
    
    for (int i = 0; i < n; i++) {
        char* key;
        do
        {
            printf("Enter the string value of element(below 10 symbols) %d: ", i + 1);
            scanf("%s", key);
        } while (strlen(key) > word_max_len);
        if(i == 0)
        {
            f_node = init_list(key);
            continue;
        }
        push(&f_node, key);
    }


    printf("Unsorted list: ");
    print_list(f_node);
    sort_list(&f_node);
    printf("Sorted list: ");
    print_list(f_node);
    //free unnsecessary data as we created copies in Doubly-Linked List
    free_list(f_node);
}

