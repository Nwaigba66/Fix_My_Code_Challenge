#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints a doubly linked list of integers
 *
 * @h: A pointer to the first element of a list
 *
 * Return: The number of elements printed
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t n = 0;
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
        n++;
    }
    return n;
}
#ifndef _LISTS_H_
#define _LISTS_H_

// ... (existing content of lists.h)

#endif /* _LISTS_H_ */

typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;


