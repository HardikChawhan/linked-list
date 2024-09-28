#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct Queue
{
  Node *front;
  Node *rear;
} Queue;

void initQueue(Queue *queue)
{
  queue->front = NULL;
  queue->rear = NULL;
}

bool isEmpty(Queue *queue)
{
  if (queue->front == NULL && queue->rear == NULL)
  {
    return true;
  }
  return false;
}

void enqueue(Queue *queue, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL; // new node is addded at the rear
  newNode->prev = queue->rear;
  if (queue->rear != NULL)
  {
    queue->rear->next = newNode;
  }
  queue->rear = newNode;
  if (queue->front == NULL)
  {
    queue->front = newNode; // If queue was empty, front is also the new node
  }
}

int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    return -1;
  }
  Node *temp = queue->front;
  int data = temp->data;
  queue->front = temp->next;
  if (queue->front != NULL)
  {
    queue->front->prev = NULL;
  }
  else
  {
    queue->rear = NULL;
  }
  free(temp);
  return data;
}

int peek(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    return -1;
  }
  return queue->front->data;
}

void printQueue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    return;
  }
  Node *temp = queue->front;
  while (temp != NULL)
  {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{
  Queue queue;
  initQueue(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  printQueue(&queue);

  printf("Dequeued: %d\n", dequeue(&queue));
  printQueue(&queue);

  printf("Front element: %d\n", peek(&queue));

  return 0;
}