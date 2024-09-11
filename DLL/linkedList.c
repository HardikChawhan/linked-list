#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
  Node *newNode = (Node*)malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  newNode->prev = NULL;
  
  if (isEmpty(list))
  {
    newNode->next = NULL;
    list->head = newNode;
  } else {
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
  }
}

void insertAtEnd(linkedList *list, int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty(list))
  {
    newNode->prev = NULL;
    list->head = newNode;
  } else {
    Node *curr = list->head;

    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
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
    insertAtBeginning(list,data);
    return;
  }

  Node *newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;

  Node *curr = list->head;
  Node *prev = NULL;

  for (int i = 0; i < position && curr != NULL; i++)
  {
    prev = curr;
    curr = curr->next;
  }

  newNode->next = curr;
  newNode->prev = prev;

  if (curr != NULL)
  {
    curr->prev = newNode;
  }

  if (prev != NULL)
  {
    prev->next = newNode;
  }
}

int deleteFromBeginning(linkedList *list){
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }

  Node *temp = list->head;
  int data = temp->data;
  list->head = temp->next;

  if (list->head != NULL)
  {
    list->head->prev = NULL;
  }
  
  free(temp);
  return data;
}

int deleteFromEnd(linkedList *list){
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }

  Node *curr = list->head;
  Node *prev = NULL;

  while (curr->next != NULL)
  {
    prev = curr;
    curr = curr->next;
  }
  
  int data = curr->data;
  if (prev != NULL)
  {
    prev->next = NULL;
  } else {
    list->head = NULL;
  }
  
  free(curr);
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
    printf("List is empty\n");
    return -1;
  }

  Node *curr = list->head;
  Node *prev = NULL;

  for (int i = 0; i < position && curr != NULL; i++)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL)
  {
    printf("Position out of bounds\n");
    return -1;
  }

  int data = curr->data;
  if (prev != NULL)
  {
    prev->next = curr->next;
  }
  if (curr->next != NULL)
  {
    curr->next->prev = prev;
  }
  
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
  while (curr != NULL)
  {
    printf("%d <-> ",curr->data);
    curr = curr->next;
  }
  printf("Null\n");
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