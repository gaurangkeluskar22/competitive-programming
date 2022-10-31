#include<iostream>
using namespace std ;
#include<string>
void sortedfreq(string str)
{
    int count[26] ;
    for(int i=0;i<str.length();i++)
    {
        count[str[i] - 'a']++ ;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]>0)
        {
            cout<<(char)(i+ 'a')<<count[i]<<" " ;
        }
    }
}

int main()
{
    string str = "geeksforgeeks" ;
    sortedfreq(str) ;
}
