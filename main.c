#include <stdio.h>
#include <stdlib.h>

unsigned __int128 my_pow(unsigned int a, unsigned int b)
{
	unsigned __int128 ret = 1;

	for (ret = a; b; --b)
		ret *= a;

	return (ret);
}

int main(int argc, char **argv)
{
	unsigned __int128 a = 0, i, p, p_s, foo;
	unsigned int dig, len;
	FILE *fd;
	char *buf = malloc(sizeof(char) * 1024);

	foo = 45;
	putchar(((a / 10)) + '0');
	putchar('\n');

	if (argc != 2)
	{
		printf("Incorrect number of args\n");
		exit(1);
	}

	fd = fopen(argv[1], "r");

	while (fgets(buf, 1024, fd))
	{
		for (len = 0; buf[len]; ++len)
			;

		for (; len > 0; --len)
		{
			a *= 10;
			a += buf[len - 1] - '0';
		}

		for (i = 2; i < a/2; ++i)
		{
			if (a % i == 0)
			{
				p = a;
				for (p_s = 0; p > 0; ++p_s)
					p /= 10;

				for (dig = 0; p_s; --p_s, ++dig)
					putchar(((a / my_pow(10, dig)) % 10) + '0');
				putchar('\n');

				break;
			}
		}
	}

	free(buf);
	return (0);
}

int is_prime(int n)
{
	int i = 2;
	
	for (; i < n/2; ++i)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}
