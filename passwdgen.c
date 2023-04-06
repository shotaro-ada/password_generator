#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 65
#define MIN_CHAR 33
#define MAX_CHAR 126

int getRandomChar(int min, int max);

int main(int argc, char *argv[])
{

	int passlen = MAX_SIZE - 1;
	char *excluded_characters;
 
	int opt;
	while ((opt = getopt(argc, argv, "l:e:")) != -1)
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
		case 'e':
			if (!optarg)
			{
				fprintf(stderr, "Error: Invalid option argument.\n");
				return 1;
			}
			excluded_characters = optarg;
			break;
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



	int i;
	time_t t;
	srandom(time(&t));
	for (i = 0; i < passlen; i++)
	{
		int c = getRandomChar(MIN_CHAR, MAX_CHAR);

		bool is_ok = true;
		while(*(excluded_characters) != '\0'){
			if(c == '\\' || c == *(excluded_characters)){
				printf("bad character\n");
				is_ok = false;
				break;
			}
			// printf("%c\n", *(excluded_characters));
			excluded_characters ++;
		}

		if(!is_ok){
			i--;
		} else {
			words[i] = (char)c;
		}
		// if (c == '\\')
		// {
		// 	i--;
		// }
		// else
		// {
		// 	words[i] = (char)c;
		// }
	}
	words[passlen] = '\0';
	printf("%s\n", words);
	free(words);
	return 0;
}

int getRandomChar(int min, int max)
{
	int num = (int)((double)random() * (max + 1 - min) / (double)RAND_MAX + min);
	// return num;
}
