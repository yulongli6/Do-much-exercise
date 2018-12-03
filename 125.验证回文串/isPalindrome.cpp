#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)return true;
        size_t left = 0;
        size_t right = s.size() - 1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(left < right)
        {
            if(!((s[left] >= 'a' && s[left] <= 'z') 
                 ||(s[left] >= '0' && s[left] <= '9')))
            {
                left++;
                continue;

            }
            if(!((s[right] >= 'a' && s[right] <= 'z') 
                 ||(s[right] >= '0' && s[right] <= '9')))
            {
                right--;
                continue;

            }

            if(s[left] != s[right])
            {
                return false;

            }
            left++;
            right--;

        }

        return true;


    }

};

int main()
{
    string str;
    Solution s1;
    while(getline(cin, str))
    {
        cout << s1.isPalindrome(str)<<endl;
    }
    return 0;
}
