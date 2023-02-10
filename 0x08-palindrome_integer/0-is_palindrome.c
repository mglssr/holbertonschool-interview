#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given unsigned
 * integer is a palindrome.
 * @n: is the number to be checked.
 *
 * Return: 1 if n is palindrome and 0 otherwise.
 **/
int is_palindrome(unsigned long n)
{
	unsigned long reverse = 0, num = n;

	while (num != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + num % 10;
		num /= 10;
	}
	if (n == reverse)
		return (1);
	return (0);
}
