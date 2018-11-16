#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void judge(char* s, int len, int left, int right,int* pos, int* maxlen){
	while (left >= 0 && right < len && s[left] == s[right]){
		left--;
		right++;
	}
	if (*maxlen < right - left - 1){
		*pos = left + 1;
		*maxlen = right - left - 1;
	}
}
char* longestPalindrome(char* s) {
	int maxlen = 0;
	int pos = 0;
	int len = strlen(s);
	if (len < 2){
		return s;
	}
	int i = 0;
	for (i = 0; i < len; i++){
		judge(s, len, i, i,&pos, &maxlen);
		judge(s, len, i, i + 1,&pos, &maxlen);
	}
	char*save = (char*)malloc(sizeof(char)*(maxlen + 1));
	memcpy(save, s + pos, maxlen);
	save[maxlen] = '\0';
	return save;
}
int main()
{
	char* s = "babad";
	char* ret = longestPalindrome(s);
	printf("%s\n", ret);
	return 0;
}

