/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
    {
        return (-1); /* Empty list, nothing to delete */
    }

    dlistint_t *current = *head;
    unsigned int i = 0;

    /* Traverse to the node at the given index */
    while (i < index && current != NULL)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        return (-1); /* Index out of range */
    }

    /* If the node to delete is the head node */
    if (current == *head)
    {
        *head = current->next; /* Update head to the next node */
        if (*head != NULL)
        {
            (*head)->prev = NULL; /* Update the new head's prev pointer to NULL */
        }
    }
    else
    {
        current->prev->next = current->next; /* Update the next pointer of the previous node */
        if (current->next != NULL)
        {
            current->next->prev = current->prev; /* Update the prev pointer of the next node */
        }
    }

    free(current); /* Free the deleted node */
    return (1);
}

