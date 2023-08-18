#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to a pointer to the head of the list.
 * @index: Index to be deleted.
 *
 * Return: 1 on succeeded, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current = *head;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;

if (*head != NULL)
(*head)->prev = NULL;
free(current);

return (1);
}

while (index > 0 && current != NULL)
{
current = current->next;
index--;
}

if (current == NULL)
return (-1);

current->prev->next = current->next;

if (current->next != NULL)
current->next->prev = current->prev;

free(current);

return (1);
}
