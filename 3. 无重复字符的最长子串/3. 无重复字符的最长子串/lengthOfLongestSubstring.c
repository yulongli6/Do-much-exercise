#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdio.h"
#include<assert.h>

int lengthOfLongestSubstring(char* s) {
	assert(s);
	int maxlen = 0;
	char* quick = s;
	char* slow = s;
	char bitmap[255] = { 0 };//并没有真的用位图，只是位图的思想
	while (*quick != '\0')
	{
		if (bitmap[*quick] == 0)
		{
			//走快指针，将字符信息置1
			bitmap[*quick] = 1;
		}
		else
		{
			if (quick - slow > maxlen)
			{
				maxlen = quick - slow;
			}
			while (*slow != *quick)
			{
				//移动慢指针slow，将字符信息置0
				bitmap[*slow] = 0;
				slow++;
			}
			slow++;
		}
		quick++;
	}
	if (quick - slow > maxlen)
	{
		//最后需要判断一遍，因为快指针指向尾的那一次并没有比较长度
		maxlen = quick - slow;
	}
	return maxlen;
}


int main()
{
	char* s = "dfdv";
	int ret = lengthOfLongestSubstring(s);
	printf("%d\n", ret);
	return 0;
}