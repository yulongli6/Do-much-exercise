#define _CRT_SECURE_NO_DEPRECATE 1
#include<iostream>
using namespace std;
class Solution {
public:
	string reverseString(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return s;
	}
};