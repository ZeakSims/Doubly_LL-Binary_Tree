#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list node 
struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev; 
};

struct node *head = NULL;
struct node *last = NULL;
 
  
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    new_node->prev = NULL;
   
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    (*head_ref) = new_node; 
} 
  
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
    new_node->prev = prev_node; 
  
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
} 
  
void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* last = *head_ref; 
    new_node->data = new_data; 
    new_node->next = NULL; 
  
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
    new_node->prev = last; 
  
    return; 
} 
  
// This function prints contents of linked list starting from the given node 
void printList(struct Node* node) 
{ 
    struct Node* last; 
    printf("\nTraversal in forward direction \n"); 
    while (node != NULL) { 
        printf(" %d ", node->data); 
        last = node; 
        node = node->next; 
    } 
  
    printf("\nTraversal in reverse direction \n"); 
    while (last != NULL) { 
        printf(" %d ", last->data); 
        last = last->prev; 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
    push(&head, 1);
    push(&head, 2);
    push(&head, 3); 
    push(&head, 4); 
    printf("Created DLL is: "); 
    printList(head); 
  
    getchar(); 
    return 0; 
} 
