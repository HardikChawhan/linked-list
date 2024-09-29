#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int coeff;         // Coefficient of the term
  int exp;           // Exponent of the term
  struct Node *next; // Pointer to the next term
} Node;

typedef struct
{
  Node *head;
} Polynomial;

// Function to create a new node for a term
Node *createNode(int coeff, int exp)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->coeff = coeff;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new term into the polynomial in descending order of exponents
void insertTerm(Polynomial *poly, int coeff, int exp)
{
  Node *newNode = createNode(coeff, exp);

  if (poly->head == NULL || poly->head->exp < exp)
  {
    // Insert at the beginning if it's the largest exponent
    newNode->next = poly->head;
    poly->head = newNode;
  }
  else
  {
    // Insert in the middle or end
    Node *temp = poly->head;
    while (temp->next != NULL && temp->next->exp >= exp)
    {
      temp = temp->next;
    }

    if (temp->exp == exp)
    {
      // If exponents match, add coefficients
      temp->coeff += coeff;
    }
    else
    {
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }
}

// Function to display the polynomial
void displayPolynomial(Polynomial *poly)
{
  if (poly->head == NULL)
  {
    printf("0\n");
    return;
  }

  Node *temp = poly->head;
  while (temp != NULL)
  {
    if (temp->coeff != 0)
    {
      if (temp->exp == 0)
      {
        printf("%d", temp->coeff); // Constant term
      }
      else if (temp->exp == 1)
      {
        printf("%dx", temp->coeff); // x term
      }
      else
      {
        printf("%dx^%d", temp->coeff, temp->exp); // x^exp term
      }

      if (temp->next != NULL && temp->next->coeff > 0)
      {
        printf(" + ");
      }
    }
    temp = temp->next;
  }
  printf("\n");
}

// Function to add two polynomials
Polynomial addPolynomials(Polynomial *poly1, Polynomial *poly2)
{
  Polynomial result;
  result.head = NULL;

  Node *p1 = poly1->head;
  Node *p2 = poly2->head;

  while (p1 != NULL && p2 != NULL)
  {
    if (p1->exp > p2->exp)
    {
      insertTerm(&result, p1->coeff, p1->exp);
      p1 = p1->next;
    }
    else if (p1->exp < p2->exp)
    {
      insertTerm(&result, p2->coeff, p2->exp);
      p2 = p2->next;
    }
    else
    {
      // Same exponent, add the coefficients
      insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
      p1 = p1->next;
      p2 = p2->next;
    }
  }

  // Add remaining terms
  while (p1 != NULL)
  {
    insertTerm(&result, p1->coeff, p1->exp);
    p1 = p1->next;
  }
  while (p2 != NULL)
  {
    insertTerm(&result, p2->coeff, p2->exp);
    p2 = p2->next;
  }

  return result;
}

// Function to multiply two polynomials
Polynomial multiplyPolynomials(Polynomial *poly1, Polynomial *poly2)
{
  Polynomial result;
  result.head = NULL;

  for (Node *p1 = poly1->head; p1 != NULL; p1 = p1->next)
  {
    for (Node *p2 = poly2->head; p2 != NULL; p2 = p2->next)
    {
      int coeff = p1->coeff * p2->coeff;
      int exp = p1->exp + p2->exp;
      insertTerm(&result, coeff, exp);
    }
  }

  return result;
}

// Function to create a polynomial by taking user input
void createPolynomial(Polynomial *poly)
{
  int n, coeff, exp;
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter coefficient and exponent for term %d: ", i + 1);
    scanf("%d %d", &coeff, &exp);
    insertTerm(poly, coeff, exp);
  }
}

int main()
{
  Polynomial poly1, poly2, sum, product;
  poly1.head = NULL;
  poly2.head = NULL;

  printf("Create first polynomial:\n");
  createPolynomial(&poly1);
  printf("First Polynomial: ");
  displayPolynomial(&poly1);

  printf("\nCreate second polynomial:\n");
  createPolynomial(&poly2);
  printf("Second Polynomial: ");
  displayPolynomial(&poly2);

  // Polynomial Addition
  sum = addPolynomials(&poly1, &poly2);
  printf("\nSum of Polynomials: ");
  displayPolynomial(&sum);

  // Polynomial Multiplication
  product = multiplyPolynomials(&poly1, &poly2);
  printf("\nProduct of Polynomials: ");
  displayPolynomial(&product);

  return 0;
}
