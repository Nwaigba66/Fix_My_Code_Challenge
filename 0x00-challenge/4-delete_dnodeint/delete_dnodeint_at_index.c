#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (*head == NULL)
    {
        return (-1); 
    }

    current = *head;

    if (index == 0)
    {
        *head = current->next; /* Update head to the next node */
        if (*head != NULL)
        {
            (*head)->prev = NULL; /* Update the new head's prev pointer to NULL */
        }
        free(current); /* Free the deleted node */
        return (1);
    }

    /* Traverse to the node at the given index */
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return (-1); /* Index out of range */
    }

    current->prev->next = current->next; /* Update the next pointer of the previous node */
    if (current->next != NULL)
    {
        current->next->prev = current->prev; /* Update the prev pointer of the next node */
    }

    free(current); /* Free the deleted node */
    return (1);
}
