#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

void printlist(node_t *head)
{
    node_t *temporary = head;
    int i = 1;

    while (temporary != NULL)
    {
        printf("Node: %3d    Value: %3d    Address: %p    Next: %p\n", i, temporary->value, temporary, temporary->next);
        temporary = temporary->next;
        i++;
    }
}

int searchlist(node_t *head, int value)
{
    node_t *temporary = head;
    int i = 1;

    while (temporary != NULL)
    {
        if (temporary->value == value)
        {
            printf("Value: %d found at node: %d\n", temporary->value, i);
            return i;
        }
        temporary = temporary->next;
        i++;
    }
    printf("Value not found\n");
    return 0;
}

node_t *create_new_node(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

node_t *new_head(node_t *head_old, node_t *head_new)
{
    head_new->next = head_old;
    return head_new;
}

node_t *append_start(node_t *head_old, int value)
{
    node_t *node_new = create_new_node(value);
    node_t *head_new = new_head(head_old, node_new);
    return head_new;
}

void append_end(node_t *head, int value)
{
    node_t *temporary = head;

    while (temporary->next != NULL)
    {
        temporary = temporary->next;
    }

    node_t *node_new = create_new_node(value);

    temporary->next = node_new;
}

node_t *new_list(int len)
{
    node_t *temp;
    node_t *head;

    head = create_new_node(len);

    for (int i = (len - 1); i > 0; i--)
    {
        temp = create_new_node(i);
        head = new_head(head, temp);
    }
    return head;
}

int main()
{

    node_t *head;

    // // create new list
    // head = new_list(15);

    // // print list
    // printlist(head);

    // // search list from using input
    // int searchVal;
    // printf("\nEnter value to search list\n");
    // scanf("%d", &searchVal);
    // searchlist(head, searchVal);

    // head = create_new_node(2);
    // printlist(head);
    // printf("\n");

    // head = append_start(head, 1);
    // printlist(head);
    // printf("\n");

    // append_end(head, 3);
    // printlist(head);

    head = create_new_node(rand() % 100);
    for (int i = 0; i < 19; i++)
        append_end(head, rand() % 10);

    printlist(head);

    for (int i = 0; i < 20; i++)
        head = append_start(head, rand() % 100);

    printlist(head);

    searchlist(head, 60);

    return 0;
}