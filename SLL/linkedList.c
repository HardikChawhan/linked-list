#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next; // here next is a node, but the entire node is itself a address
} Node;

typedef struct
{
  Node *head;
} linkedList;

void initList(linkedList *list)
{
  list->head = NULL;
}

bool isEmpty(linkedList *list)
{
  if (list->head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void insertAtBeginning(linkedList *list, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
}

void insertAtEnd(linkedList *list, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;

  if (isEmpty(list))
  {
    list->head = newNode;
  }
  else
  {
    Node *temp = list->head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void insertAtMiddle(linkedList *list, int data, int position)
{
  if (position < 0)
  {
    printf("Invalid position\n");
    return;
  }

  // If position is 0, insert at the beginning
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
  newNode->next = NULL;

  // treverse the list to find the node just before the desired position
  Node *temp = list->head;
  for (int i = 0; i < position - 1 && temp->next != NULL; i++)
  {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

int deleteFromBeginning(linkedList *list)
{
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }

  Node *temp = list->head;
  int data = temp->data;
  list->head = temp->next;
  free(temp);
  return data;
}

int deleteFromEnd(linkedList *list)
{
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }

  Node *temp = list->head;
  Node *prev = NULL;

  // If there's only one node in the list
  if (temp->next == NULL)
  {
    int data = temp->data;
    free(temp);
    list->head = NULL;
    return data;
  }

  // Traverse to the last node, keeping track of the previous node
  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }

  int data = temp->data;
  free(temp);
  prev->next = NULL; // Set the previous node's next to NULL
  return data;
}

int deleteFromMiddle(linkedList *list, int postiton)
{
  if (postiton < 0)
  {
    printf("Invalid position\n");
    return -1;
  }

  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }

  if (postiton == 0)
  {
    return deleteFromBeginning(list);
  }

  Node *temp = list->head;
  for (int i = 0; i < postiton - 1 && temp->next != NULL; i++)
  {
    temp = temp->next;
  }

  Node *toDelete = temp->next;
  int data = toDelete->data;
  temp->next = toDelete->next;
  free(toDelete);
  return data;
}

void printList(linkedList *list)
{
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return;
  }

  Node *temp = list->head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
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