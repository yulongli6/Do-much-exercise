#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdio.h"
#include<assert.h>

int lengthOfLongestSubstring(char* s) {
	assert(s);
	int maxlen = 0;
	char* quick = s;
	char* slow = s;
	char bitmap[255] = { 0 };//��û�������λͼ��ֻ��λͼ��˼��
	while (*quick != '\0')
	{
		if (bitmap[*quick] == 0)
		{
			//�߿�ָ�룬���ַ���Ϣ��1
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
				//�ƶ���ָ��slow�����ַ���Ϣ��0
				bitmap[*slow] = 0;
				slow++;
			}
			slow++;
		}
		quick++;
	}
	if (quick - slow > maxlen)
	{
		//�����Ҫ�ж�һ�飬��Ϊ��ָ��ָ��β����һ�β�û�бȽϳ���
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