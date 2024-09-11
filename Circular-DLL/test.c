#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct
{
  Node *head;
} CircularDoublyLinkedList;

void initList(CircularDoublyLinkedList *list)
{
  list->head = NULL;
}

bool isEmpty(CircularDoublyLinkedList *list)
{
  return list->head == NULL;
}

void insertAtBeginning(CircularDoublyLinkedList *list, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  if (isEmpty(list))
  {
    newNode->next = newNode->prev = newNode;
    list->head = newNode;
  }
  else
  {
    Node *last = list->head->prev;
    newNode->next = list->head;
    newNode->prev = last;
    list->head->prev = newNode;
    last->next = newNode;
    list->head = newNode;
  }
}

void insertAtEnd(CircularDoublyLinkedList *list, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  if (isEmpty(list))
  {
    newNode->next = newNode->prev = newNode;
    list->head = newNode;
  }
  else
  {
    Node *last = list->head->prev;
    newNode->next = list->head;
    newNode->prev = last;
    last->next = newNode;
    list->head->prev = newNode;
  }
}

void insertAtMiddle(CircularDoublyLinkedList *list, int data, int position)
{
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

int deleteFromBeginning(CircularDoublyLinkedList *list)
{
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
  }
  else
  {
    Node *last = list->head->prev;
    list->head = temp->next;
    list->head->prev = last;
    last->next = list->head;
  }

  free(temp);
  return data;
}

int deleteFromEnd(CircularDoublyLinkedList *list)
{
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return -1;
  }

  Node *last = list->head->prev;
  int data = last->data;

  if (list->head->next == list->head)
  {
    list->head = NULL;
  }
  else
  {
    Node *prev = last->prev;
    prev->next = list->head;
    list->head->prev = prev;
  }

  free(last);
  return data;
}

int deleteFromMiddle(CircularDoublyLinkedList *list, int position)
{
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
  for (int i = 0; i < position && curr->next != list->head; i++)
  {
    curr = curr->next;
  }

  if (curr == list->head)
  {
    printf("Position out of bounds\n");
    return -1;
  }

  int data = curr->data;
  Node *prev = curr->prev;
  Node *next = curr->next;
  prev->next = next;
  next->prev = prev;

  free(curr);
  return data;
}

void printList(CircularDoublyLinkedList *list)
{
  if (isEmpty(list))
  {
    printf("List is empty\n");
    return;
  }

  Node *curr = list->head;
  do
  {
    printf("%d <-> ", curr->data);
    curr = curr->next;
  } while (curr != list->head);
  printf("(circular back to head)\n");
}

int main()
{
  CircularDoublyLinkedList myList;
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
