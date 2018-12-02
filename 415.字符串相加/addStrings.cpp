#include <algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int LSize = num1.size();
        int RSize = num2.size();

        if(LSize < RSize)
        {
            num1.swap(num2);
            swap(LSize, RSize);

        }

        string strRet;
        strRet.reserve(LSize + 1);

        char step = 0;
        char retNumber = 0;

        for(size_t i = 0; i < num1.size(); ++i)
        {
            retNumber = num1[num1.size()-1-i] -'0' + step;
            step = 0;

            if(i<num2.size())
            {
                retNumber += num2[num2.size()-1-i] - '0';

            }

            if(retNumber>9)
            {
                retNumber = retNumber-10;
                step = 1;

            }

            strRet += retNumber +'0';

        }

        if(step)
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
    cin >> s1;
    cin >> s2;
    Solution s;
    cout << s.addStrings(s1,s2) << endl;
    return 0;
}
