#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
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
  if (stack->top == NULL)
  {
    return true;
  }
  return false;
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
  newNode->next = stack->top;
  stack->top = newNode;
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
  stack->top = temp->next;
  free(temp);
  return data;
}

int peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty\n");
    return -1;
  }
  return stack->top->data;
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
    printf("%d -> ", temp->data);
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
  return 0;
}