#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Create a new node */
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* Insert at beginning */
void insertBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head != NULL)
    {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}

/* Insert at end */
void insertEnd(int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* Insert after a given node */
void insertAfter(int key, int data)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/* Delete node with given key */
void deleteNode(int key)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

/* Traverse forward */
void traverseForward()
{
    struct Node *temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Traverse backward */
void traverseBackward()
{
    struct Node *temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward Traversal: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

/* Reverse the doubly linked list */
void reverseList()
{
    struct Node *temp = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}

/* Count nodes */
int countNodes()
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/* Main function */
int main()
{
    int choice, data, key;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete a Node\n");
        printf("5. Traverse Forward\n");
        printf("6. Traverse Backward\n");
        printf("7. Reverse List\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertBeginning(data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(data);
            break;

        case 3:
            printf("Enter key and data: ");
            scanf("%d %d", &key, &data);
            insertAfter(key, data);
            break;

        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteNode(key);
            break;

        case 5:
            traverseForward();
            break;

        case 6:
            traverseBackward();
            break;

        case 7:
            reverseList();
            printf("List reversed successfully\n");
            break;

        case 8:
            printf("Number of nodes = %d\n", countNodes());
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}