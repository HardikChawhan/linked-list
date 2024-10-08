# Linked List Implementation in C

This project is a basic implementation of a Linked List in the C programming language. The aim is to understand how linked lists operate at a low level and how different operations such as insertion and deletion are performed.

## Features

- Initialize the linked list.
- Insert elements at the beginning, middle, and end of the list.
- Delete elements from the beginning, middle, and end of the list.
- Check if the list is empty.
- Print the contents of the list.

## Prerequisites

- C compiler (GCC recommended)

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/HardikChawhan/linked-list.git
    ```

2. Navigate to the project directory:

    ```bash
    cd linked-list
    ```

3. Compile the code:

    ```bash
    gcc linkedList.c -o linkedList
    ```

4. Run the executable:

    ```bash
    ./linkedList
    ```

## Example

### Linked List Initialization
```c
   linkedList myList;
   initList(&myList);
```

### Inserting Elements

### Insert at End
```c
    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 30);
```

### Insert at Beginning
```c
    insertAtBeginning(&myList, 5);
```

### Insert at Middle
```c
    insertAtMiddle(&myList, 25, 3);
```

## Deleting Elements

### Delete from Beginning
```c
   printf("Delete from beginning: %d\n", deleteFromBeginning(&myList));
```

### Delete from Middle
```c
   printf("Delete from middle: %d\n", deleteFromMiddle(&myList, 2));
```

### Delete from End
```c
   printf("Delete from end: %d\n", deleteFromEnd(&myList));
```

## Printing the Linked List
```c
   printList(&myList);
```

## Checking if List is Empty
```c
   if (isEmpty(&myList)) {
      printf("List is empty\n");
   } else {
      printf("List is not empty\n");
   }
```

## Video Explanation - Click to watch
### Linked List PlayList 👇
[![Watch the video](https://img.youtube.com/vi/I8B13fY3izQ/hqdefault.jpg)](https://youtu.be/I8B13fY3izQ?si=E0F7g-Uxb0vGstXj)


## 🔗 Profile Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hardikchawhan)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/ChawhanHardik)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/hardik_chawhan_10/)