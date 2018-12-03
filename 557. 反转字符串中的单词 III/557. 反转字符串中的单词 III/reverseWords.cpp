#define _CRT_SECURE_NO_DEPRECATE 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		size_t j = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				reverse(s.begin() + j, s.begin() + i);
				j = i + 1;
			}
		}
		reverse(s.begin() + j, s.end());
		return s;
	}
};

int main()
{
	string str;
	Solution s;
	while (getline(cin, str))
	{
		cout << s.reverseWords(str) << endl;
	}
	return 0;
}