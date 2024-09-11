#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}Node;

typedef struct
{
  Node *head;
}linkedList;

void initList(linkedList *list){
  list->head = NULL;
}

bool isEmpty(linkedList *list){
  if (list->head == NULL)
  {
    return true;
  }
  else {
    return false;
  }
}

void insertAtBeginning(linkedList *list, int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    return;
  }
  
  newNode->data = data;
  if (isEmpty(list))
  {
    list->head = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    Node *last = list->head->prev;
    newNode->next = list->head;
    newNode->prev = last;
    list->head->prev = newNode;
    last->next = newNode;
    list->head = newNode;
  }
}

void insertAtEnd(linkedList *list, int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    return;
  }

  newNode->data = data;
  if (isEmpty(list))
  {
    list->head = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    Node *last = list->head->prev;
    newNode->next = list->head;
    newNode->prev = last;
    last->next = newNode;
    list->head->prev = newNode;
  }
}

void insertAtMiddle(linkedList *list, int data, int position){
  if (position < 0)
  {
    printf("Invalid position\n");
    return;
  }

  if (position == 0 || isEmpty(list))
  {
    insertAtBeginning(list, data);
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;

  Node *curr = list->head;
  for (int i = 0; i < position && curr->next != list->head; i++)
  {
    curr = curr->next;
  }
  
  Node *prev = curr->prev;
  newNode->next = curr;
  newNode->prev = prev;
  prev->next = newNode;
  curr->prev = newNode;
}

int deleteFromBeginning(linkedList *list){
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }
  
  Node *temp = list->head;
  int data = temp->data;

  if (list->head->next == list->head)
  {
    list->head = NULL;
  } else {
    Node *last = list->head->prev;
    list->head = temp->next;
    list->head->prev = last;
    last->next = list->head;
  }

  free(temp);
  return data;
}

int deleteFromEnd(linkedList *list){
  if (isEmpty(list))
  {
    printf("list is empty\n");
    return -1;
  }

  Node *last = list->head->prev;
  int data = last->data;

  if (list->head->next == list->head)
  {
    list->head = NULL;
  } else {
    Node *prev = last->prev;
    prev->next = list->head;
    list->head->prev = prev;
  }
  
  free(last);
  return data;
}

int deleteFromMiddle(linkedList *list, int position){
  if (position < 0)
  {
    printf("Invalid position\n");
    return -1;
  }

  if (position == 0)
  {
    return deleteFromBeginning(list);
  }
  
  if (isEmpty(list))
  {
    printf("list is empty\n");
    return -1;
  }

  Node *curr = list->head;
  for (int i = 0; i < position && curr->next != list->head; i++)
  {
    curr = curr->next;
  }
  
  int data = curr->data;
  Node *prev = curr->prev;
  prev->next = curr->next;
  curr->next->prev = prev;

  free(curr);
  return data;
}

void printList(linkedList *list){
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return;
  }

  Node *curr = list->head;
  do
  {
    printf("%d <-> ",curr->data);
    curr = curr->next;
  } while (curr != list->head);
  printf("(Circular back to head)\n");
}

int main(){
  linkedList myList;
  initList(&myList);

  insertAtEnd(&myList, 10);
  insertAtEnd(&myList, 20);
  insertAtEnd(&myList, 30);
  printList(&myList);

  insertAtBeginning(&myList, 5);
  printList(&myList);

  insertAtMiddle(&myList, 25, 3);
  printList(&myList);

  printf("Delete from beginning: %d\n", deleteFromBeginning(&myList));
  printList(&myList);

  printf("Delete from middle: %d\n", deleteFromMiddle(&myList, 2));
  printList(&myList);

  printf("Delete from end: %d\n", deleteFromEnd(&myList));
  printList(&myList);

return 0;
}