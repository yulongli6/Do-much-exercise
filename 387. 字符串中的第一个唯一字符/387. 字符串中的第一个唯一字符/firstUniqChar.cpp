#define _CRT_SECURE_NO_DEPRECATE 1
#include<iostream>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };

		for (size_t i = 0; i < s.size(); ++i)
			count[s[i]]++;

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (1 == count[s[i]])
				return i;
		}

		return -1;
	}
};
