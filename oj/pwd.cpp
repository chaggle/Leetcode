#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if(str[i] == 'z' || str[i] == 'Z')
            {
                str[i] -= 25;
            }
            else if (('A' <= str[i] && str[i] <= 'Y') ||
                     ('a' <= str[i] && str[i] <= 'y'))
            {
                str[i]++;
            }

        }
        cout<< str <<endl;        
    }
    return 0;
}