#include "main.h"
/**
 * set_bit - Entry Point
 * @n: input
 * @index: index
 * Return: 0
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int i;

	if (n == NULL)
		return (-1);

	i = 1 << index;

	*n = *n | i;

	return (1);
}
