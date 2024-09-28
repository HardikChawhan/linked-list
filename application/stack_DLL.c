#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next; // Use both next and prev pointers for doubly linked list
  struct Node *prev;
} Node;

typedef struct
{
  Node *top;
} Stack;

void initStack(Stack *stack)
{
  stack->top = NULL;
}

bool isEmpty(Stack *stack)
{
  return stack->top == NULL; // Fixed: Use '==' instead of '='
}

void push(Stack *stack, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->prev = NULL;       // For doubly linked list
  newNode->next = stack->top; // Link new node to the top
  if (stack->top != NULL)
  {
    stack->top->prev = newNode; // Set the previous pointer of the old top
  }
  stack->top = newNode; // Update the top to the new node
}

int pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    return -1;
  }
  Node *temp = stack->top;
  int data = temp->data;
  stack->top = temp->next; // Update the top to the next node
  if (stack->top != NULL)
  {
    stack->top->prev = NULL; // Update the previous pointer of the new top
  }
  free(temp); // Free the memory
  return data;
}

int peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    return -1;
  }
  return stack->top->data; // Return the top data
}

void printStack(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    return;
  }
  Node *temp = stack->top;
  while (temp != NULL)
  {
    printf("%d <-> ", temp->data); // Changed to '<->' for doubly linked list
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{
  Stack stack;
  initStack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printStack(&stack);

  printf("Popped: %d\n", pop(&stack));
  printStack(&stack);

  printf("Top element: %d\n", peek(&stack));

  return 0;
}
