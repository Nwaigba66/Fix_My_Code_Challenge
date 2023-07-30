#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/* Function to print the doubly linked list */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;
    while (h != NULL)
    {
        printf("%d ", h->n);
        h = h->next;
        count++;
    }
    printf("\n");
    return count;
}

/* Function to add a node at the end of the doubly linked list */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
    {
        return NULL; /* Memory allocation failed */
    }
    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        dlistint_t *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
    return new_node;
}

/* Function to delete a node at a specific index from the doubly linked list */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    /* Implementation of delete_dnodeint_at_index function goes here
    */ ...
    return 0; /* Placeholder return value */
}

/* Function to free the memory used by the doubly linked list */
void free_dlistint(dlistint_t *head)
{
    while (head != NULL)
    {
        dlistint_t *temp = head;
        head = head->next;
        free(temp);
    }
}
