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
        return (-1);

    current = *head;

    /* If the head needs to be removed */
    if (index == 0)
    {
        *head = current->next; /* Change head */
        if (*head != NULL)
            (*head)->prev = NULL; /* Update the previous pointer */
        free(current);
        return (1);
    }

    /* Traverse the list to find the node to be deleted */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    /* If the node to be deleted is not found */
    if (current == NULL)
        return (-1);

    /* Unlink the node from the list */
    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);

    return (1);
}
