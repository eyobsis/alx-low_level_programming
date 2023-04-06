#include "main.h"
/**
 * clear_bit - Entry Point
 * @n: input
 * @index: index
 * Return: 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int eyobbits;

	if (n == NULL)
		return (-1);

	eyobbits = 1 << index;

	if ((eyobbits | *n) == *n)
		*n = *n ^ eyobbits;

	return (1);
}
