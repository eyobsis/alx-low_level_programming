#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary
 * Return: 0
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
int flag = 0;
while (mask > 0)
{
if ((n & mask) == 0 && flag == 1)
printf('0');
else if ((n & mask) != 0)
{
printf('1');
flag = 1;
}
mask = mask >> 1;
}
if (flag == 0)
printf('0');
}
