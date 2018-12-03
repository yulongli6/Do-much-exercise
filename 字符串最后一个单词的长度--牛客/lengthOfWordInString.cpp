#include<iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int count = 0;
    
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] == ' ')
            break;
        
        count++;
        
    }

    cout << count << endl;
    return 0;
}
