#include "main.h"
/**
 * get_bit - Entry Point
 * @n: input
 * @index: index
 * Return: 0
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int mybits;

	mybits = (n >> index) & 1;

	if ((mybits == 1) || (mybits == 0))
		return (mybits);
	else
		return (-1);
}
