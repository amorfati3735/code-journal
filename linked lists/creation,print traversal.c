
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    // first construct a normal ll
    struct node *head, *l1, *l2;
    l1 = malloc(sizeof(struct node));
    l2 = malloc(sizeof(struct node));

    l1->data = 20;
    l1->next = l2;

    l2->data = 30;
    l2->next = NULL;

    head = l1;
    return 0;

    // now traverse and print everything
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next; // this is moving forward
    }
    // now insert a new node bw l1, l2 that has data=30
    struct node *new = malloc(sizeof(struct node));
    new->data = 30;
    l1->next = new;
    new->next = l2; // this is supposedly unsafe, whatever fuck it

    return 0;
}
