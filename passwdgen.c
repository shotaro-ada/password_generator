#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SIZE 65
#define MIN_CHAR 33
#define MAX_CHAR 126

int getRandomChar(int min, int max);

int main(int argc, char *argv[])
{
	int passlen = MAX_SIZE - 1;
	int opt;
	while ((opt = getopt(argc, argv, "l:n:")) != -1)
	{
		switch (opt)
		{
		case 'l':
			if (atoi(optarg) == 0 || atoi(optarg) >= MAX_SIZE)
			{
				fprintf(stderr, "Error: Invaliid password length.\n");
				return 1;
			}
			passlen = atoi(optarg);
			break;
		case 'n':
			if (!optarg)
			{
				fprintf(stderr, "Error: Invalid option argument.\n");
				return 1;
			}
			// exit(0);
		default:
			fprintf(stderr, "invalid option\n");
			return 1;
		}
	}

	char *words = (char *)malloc((passlen + 1) * sizeof(char));
	if (words == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return 1;
	}

	time_t t;
	srandom(time(&t));
	int i;
	for (i = 0; i < passlen; i++)
	{
		int c = getRandomChar(MIN_CHAR, MAX_CHAR);
		if (c == '\\')
		{
			i--;
		}
		else
		{
			words[i] = (char)c;
		}
	}
	words[passlen] = '\0';
	printf("%s\n", words);
	free(words);
	return 0;
}

int getRandomChar(int min, int max)
{
	int num = (int)((double)random() * (max + 1 - min) / (double)RAND_MAX + min);
	return num;
}
