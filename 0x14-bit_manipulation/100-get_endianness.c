#include "main.h"
/**
 * get_endianness - Entry Point
 * Return: 0
 */

int get_endianness(void)
{
unsigned int x = 1;
char *c = (char *) &x;
return (*c);
}
