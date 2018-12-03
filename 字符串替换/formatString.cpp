#include<iostream>
using namespace std;
#include<vector>
class StringFormat {
public:
    string formatString(string A, int n, vector<char> arg, int m) {
        size_t j = 0;
        string ret;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] == '%' && A[i + 1] == 's')
            {
                ++i;
                ret += arg[j++];

            }
            else
                ret += A[i];

        }

        for(int i = j; i < m; ++i)
        {
            ret += arg[i];

        }

        return ret;

    }

};
