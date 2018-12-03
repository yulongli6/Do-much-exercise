#define _CRT_SECURE_NO_DEPRECATE 1

#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	string multiply(string num1, string num2){
		if (num1.size() == 1 && num1[0] == '0')return num1;
		if (num2.size() == 1 && num2[0] == '0')return num2;

		size_t LSize = num1.size();
		size_t RSize = num2.size();
		if (LSize < RSize)
		{
			num1.swap(num2);
			swap(LSize, RSize);
		}
		string strRet;
		strRet.reserve(LSize + 1);

		char cRet = 1;
		char cstep = 0;
		string sum;
		sum.reserve(LSize + RSize);

		for (size_t i = 0; i < RSize; ++i)
		{
			strRet.clear();
			for (size_t j = 0; j < LSize; ++j)
			{
				cRet = (num1[LSize - j - 1] - '0')
					*(num2[RSize - i - 1] - '0') + cstep;
				cstep = 0;

				if (cRet > 9)
				{
					char temp = cRet;
					cRet = temp % 10;
					cstep = temp / 10;
				}
				

				strRet += cRet + '0';
			}
			if (cstep){
				strRet += cstep + '0';
				cstep = 0;
			}
			reverse(strRet.begin(), strRet.end());
			for (size_t z = 0; z < i; ++z)
			{
				strRet += '0';
			}
			sum = addStrings(sum, strRet);
		}
		return sum;
	}
	string addStrings(string num1, string num2) {
		int LSize = num1.size();
		int RSize = num2.size();

		if (LSize < RSize)
		{
			num1.swap(num2);
			swap(LSize, RSize);

		}

		string strRet;
		strRet.reserve(LSize + 1);

		char step = 0;
		char retNumber = 0;

		for (size_t i = 0; i < num1.size(); ++i)
		{
			retNumber = num1[num1.size() - 1 - i] - '0' + step;
			step = 0;

			if (i < num2.size())
			{
				retNumber += num2[num2.size() - 1 - i] - '0';

			}

			if (retNumber > 9)
			{
				retNumber = retNumber - 10;
				step = 1;

			}

			strRet += retNumber + '0';

		}

		if (step)
		{
			strRet += '1';

		}

		reverse(strRet.begin(), strRet.end());

		return strRet;

	}
};


int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	Solution s;
	cout << s.multiply(s1, s2) << endl;
	return 0;
}
