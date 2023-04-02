#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 65
#define MIN_NUM 33
#define MAX_NUM 126

int GetRondom(int min, int max);

int main(int argc, char *argv[]){
	char words[MAX_SIZE];

	time_t t;
	srandom(time(&t));
		
	int i;
	for(i = 0; i < MAX_SIZE; i++){
		words[i] = GetRondom(MIN_NUM, MAX_NUM);
		if(words[i] == 92){
			i--;	
		}
	}
	words[65] = '\0';

	printf("%s\n", words);

	return 0;
}


int GetRondom(int min, int max){
	int num =0;
	time_t t;
	num = (int)((double)random() * (max + 1 - min) / (double)RAND_MAX + min);

	return num;
}
