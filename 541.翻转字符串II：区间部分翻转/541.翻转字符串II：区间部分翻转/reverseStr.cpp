#define _CRT_SECURE_NO_DEPRECATE 1
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	/*string reverseStr(string s, int k) {
		if (s.size() == 1)return s;
		if (k == 1)return s;
		for (size_t i = 0; i < s.size(); i += 2 * k)
		{
			size_t z = i;
			size_t j;
			if (i + k - 1 < s.size())
				j = i + k - 1;
			else
				j = s.size() - 1;
			while (z < j)
			{
				swap(s[z], s[j]);
				++z;
				--j;
			}
		
		}
		return s;
	}
	*/
	string reverseStr(string s, int k)
	{
		string::iterator it = s.begin();
		while (1)
		{
			if (it+k>s.end())
			{
				reverse(it, s.end());
				break;
			}
			reverse(it, it + k);
			it += 2 * k;
		}
		return s;
	}

};



int main()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	Solution s;
	cout <<s.reverseStr(str, k)<<endl;
	return 0;
}
