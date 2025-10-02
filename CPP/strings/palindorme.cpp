//author : seema Kumari patel      
//date   : 02-10-2025
//purpose: To check whether the given string is palindrome or not


#include<bitset/stdc++.h>

using namespace std;

void main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    int n=s.length();
    int flag=0;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"The given string is palindrome"<<endl;
    }
    else
    {
        cout<<"The given string is not palindrome"<<endl;
    }
}
