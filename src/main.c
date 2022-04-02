/* hello.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int CountWords (const char* str) {
	int wordsNum = 0;
	int len = strlen(str);
	int j = 0;
	for (int i = 0; i < len - 1; ++i) {
		if (!strncmp(&str[i], ", ", 2) && i != j) {
			++wordsNum;
			j = i + 2;
			++i;
		}		
	}
	if (strcmp(&str[j], "\0")) {
		++wordsNum;
	}
	return wordsNum;
}

int main(int argc, char* argv[]) {
	const int maxStrLength = 100;
	const int maxWordLength = 20;
	char* str = (char*)malloc(maxStrLength);
	strcpy(str, argv[1]);
	int wordsNum = CountWords(str);
	int len = strlen(str);
	return 0;

}