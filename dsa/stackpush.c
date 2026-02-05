#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}
;
int main()
{
    void push(struct Node * *top, int x);
    int n;
    scanf("%d", &n);
    struct Node *top = NULL;

    push(&top, n);
    return 0;
}

void push(struct Node **top, int x)
{
    struct Node *newN = malloc(sizeof(struct Node));
    if (newN == NULL)
    {
        printf("Stack Overflow");
        return;
    }
    newN->data = x;
    newN->next = *top;
    *top = newN;
}

int pop(struct Node *top){
    //check empty underflow
    if (*top==NULL){
        printf("Under");
        return;
    }
    //copy the value stored in temp and return it
    //we create a copy of the current top node, and copy its data to popped. then the actual top becomes the next of the temp;
    struct Node *temp=*top;
    int popped= temp ->data;
    *top=temp->next;
        free (temp);
        return popped;
}