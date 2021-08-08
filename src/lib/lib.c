#define SPACE ' '
#define TAB '\t'
#define NEW_LINE '\n'

#include "lib.h"

int is_space(char c);
int get_digit(char c);

int atoi(const char *pc)
{
	int value, d;

	value = 0;

	while (is_space(*pc))
		pc++;

	while (*pc != '\0')
		if ((d = get_digit(*pc++)) < 0)
			return value;
		else
			value = value * 10 + d;

	return value;
}

int strcmp(const char *cs, const char *ct)
{
	while (*cs == *ct)
	{
		cs++, ct++;
		if (*cs == '\0')
			return 0;
	}

	return *cs - *ct;
}

int is_space(char c)
{
	if (c == SPACE || c == TAB || c == NEW_LINE)
		return 1;
	else
		return 0;
}

int get_digit(char c)
{
	if (c < '0' || c - '0' > 9)
		return -1;
	else
		return c - '0';
}
