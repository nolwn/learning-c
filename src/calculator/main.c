#include <stdio.h>
#include "../lib/lib.h"

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define NUM '0'

#define MAX_OPS 64

int pop(),
	ops[MAX_OPS];
int *p_ops = ops;
char get_op(const char *);
void push(int);

int main(int argc, char *argv[])
{
	int i, r_op;

	i = 0;

	while (--argc)
	{
		switch (get_op(argv[++i]))
		{
		case ADD:
			push(pop() + pop());
			break;
		case SUB:
			r_op = pop();
			push(pop() - r_op);
			break;
		case MUL:
			push(pop() * pop());
			break;
		case DIV:
			r_op = pop();
			push(pop() / r_op);
			break;
		case NUM:
			push(atoi(argv[i]));
			break;
		default:
			printf("Error: invalid operation!\n");
			break;
		}
	}

	printf("%d\n", pop());

	return 0;
}

void push(int i)
{
	*p_ops = i;
	p_ops++;
}

int pop()
{
	if (p_ops == ops)
	{
		printf("Error: you tried to pop an empty stack!\n");

		return 0;
	}

	return *(--p_ops);
}

char get_op(const char *s)
{
	switch (s[0])
	{
	case ADD:
	case SUB:
	case MUL:
	case DIV:
		if (s[1] != '\0')
		{
			printf("Error: unknown symbol: %s!\n", s);
		}
		return s[0];
	default:
		return NUM;
	}
}
