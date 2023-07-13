#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: Index of the bit to get.
 *
 * Return: The value of the bit at index index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8)) /* Check if the index is out of range */
		return -1;

	unsigned long int mask = 1ul << index; /* Create a mask with a 1 at the index position */
	int bit = (n & mask) != 0; /* Perform bitwise AND to extract the bit and check if it is non-zero */

	return bit;
}
