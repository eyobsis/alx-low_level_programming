#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data.
 * @head: Pointer to the head.
 *
 * Return: The sum of all the data.
 */
int sum_dlistint(dlistint_t *head)
{
dlistint_t *current = head;
int sum = 0;
while (current != NULL)
{
sum += current->n;
current = current->next;
}
return (sum);
}
