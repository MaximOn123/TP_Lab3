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

void DivideIntoWords(const char* str, int wordsNum, char*** words) {
	int len = strlen(str);
	int j = 0, k = 0;
	for (int i = 0; i < len - 1; ++i) {
		if (!strncmp(&str[i], ", ", 2) && i != j) {
			strncpy((*words)[k], &str[j], i - j);
			j = i + 2;
			++i;
			++k;
		}
	}
	if (strcmp(&str[j], "\0")) {
		strncpy((*words)[k], &str[j], len - j);
	}

}

int main(int argc, char* argv[]) {
	const int maxStrLength = 100;
	const int maxWordLength = 20;
	char* str = (char*)malloc(maxStrLength);
	strcpy(str, argv[1]);
	printf("%s\n", str);
	int wordsNum = CountWords(str);
	int len = strlen(str);
	printf("%d\n", wordsNum);	
	char** words = (char**)malloc(wordsNum * sizeof(char*));
	for (int i = 0; i < wordsNum; ++i) {
		words[i] = (char*)malloc(maxWordLength * sizeof(char));
	}
	DivideIntoWords(str, wordsNum, &words);
	for (int i = 0; i < wordsNum; ++i) {
		printf("Words[%d] = %s; Len = %d\n", (int)i, words[i], (int)strlen(words[i]));
	}
	return 0;
}