#include "main.h"
/**
 * set_bit - Entry Point
 * @n: input
 * @index: index
 * Return: 0
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int i = n ^ m;
unsigned int count = 0;

while (i > 0)
{
count += i & 1;
i >>= 1;
}

return (count);
}
