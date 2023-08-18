#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *n_node = malloc(sizeof(dlistint_t));
dlistint_t *tmp;
if (n_node == NULL)
return (NULL);
n_node->n = n;
n_node->next = NULL;
if (*head == NULL)
{
n_node->prev = NULL;
*head = n_node;
}
else
{
tmp = *head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = n_node;
n_node->prev = tmp;
}
return (n_node);
}
