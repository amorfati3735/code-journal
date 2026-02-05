#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int x);
int pop(struct Node **top);
int peek(struct Node *top);
void display(struct Node *top);

int main() {
    struct Node *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    display(top);

    printf("Popped: %d\n", pop(&top));
    printf("Top element: %d\n", peek(top));

    display(top);

    return 0;
}

void push(struct Node **top, int x) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}
int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = *top;
    int popped = temp->data;

    *top = temp->next;
    free(temp);

    return popped;
}
int peek(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}
void display(struct Node *top) {
    if (top == NULL)    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


