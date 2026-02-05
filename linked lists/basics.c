
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void printer(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("newer: %d \n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    // first construct a normal ll
    struct node *head, *l1, *l2;
    l1 = malloc(sizeof(struct node));
    l2 = malloc(sizeof(struct node));

    l1->data = 20;
    l1->next = l2;

    l2->data = 500;
    l2->next = NULL;

    head = l1;

    // now traverse and print everything
    struct node *temp = head;
    printer(head);

    // now insert a new node bw l1, l2 that has data=30
    struct node *new = malloc(sizeof(struct node));
    new->data = 30;
    l1->next = new;
    new->next = l2;

    // printer(struct node * head); you did this. this is declaration, remove the type
    printer(head);
    // deletion of a node

    l1->next = l2;
    printer(head);
    free(new);
    return 0;
}
