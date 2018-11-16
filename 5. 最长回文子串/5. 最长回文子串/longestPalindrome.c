#define _CRT_SECURE_NO_DEPRECATE 1
//±©Á¦ÆÆ½â·¨
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int judge(char* left, char* right){
	while (left < right){
		left++;
		right--;
		if (*left != *right){
			return 0;
		}
	}
	return 1;
}


char* longestPalindrome(char* s) {
	int len = strlen(s);
	if (len == 0){ return s; }
	char* left = s;
	char* right = s + len - 1;
	int maxlen = 0;
	char* save = NULL;
	while (right!=s){
		for (left = s; left != right; left++){
			if (*left == *right){
				int ret = judge(left, right);
				if (ret == 1){
					if (maxlen < right - left + 1){
						maxlen = right - left + 1;
						save = (char*)malloc(sizeof(char)*(maxlen + 1));
						memcpy(save, left, maxlen);
						save[maxlen] = '\0';
					}
				}
			}
		}
		right--;
	}
	if (maxlen == 0){
		maxlen = 1;
		save = (char*)malloc(sizeof(char)*(maxlen + 1));
		memcpy(save, s, maxlen);
		save[maxlen] = '\0';
	}
	return save;
}

