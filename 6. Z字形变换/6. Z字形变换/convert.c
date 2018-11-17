#define _CRT_SECURE_NO_DEPRECATE 1
#include "string.h"
#include "stdlib.h"

char* convert(char* s, int numRows) {
	int len = strlen(s);
	if (len < 3){
		return s;
	}
	if (numRows < 2){
		return s;
	}
	int i = 0;
	int n = 2 * numRows - 2;
	int* parray = (int*)malloc(sizeof(int)*len);
	char* ret = (char*)malloc(sizeof(char)*(len + 1));
	for (i = 0; i < len;){
		if (i % n == 0){
			for (int j = 0; i < len && j < numRows; j++){
				parray[i++] = j;
			}
		}
		else{
			for (int k = numRows - 2; k > 0; k--)
			{
				parray[i++] = k;
			}
		}
	}
	int k = 0;
	for (int j = 0; j < numRows; j++){
		for (i = 0; i < len; i++){
			if (parray[i] == j){
				ret[k++] = s[i];
			}
		}
	}
	ret[len] = '\0';
	return ret;
}

int main()
{
	char* s = "PAYPALISHIRING";
	char* r = convert(s, 4);
	printf("%s\n", s);
	printf("%s\n", r);

	return 0;
}