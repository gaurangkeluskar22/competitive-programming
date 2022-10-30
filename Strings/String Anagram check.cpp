#include<iostream>
using namespace std ;
#include<string>

bool anagram(string &s1 , string &s2)
{
    const int CHAR = 256 ;
    int n = s1.length() ;
    int m = s2.length() ;
    int count[CHAR] = {0} ;
    if(m!=n)
    {
        return false ;
    }
    for(int i=0;i<n;i++)
    {
        count[s1[i]]++ ;
        count[s2[i]]-- ;
    }
    for(int i=0;i<CHAR;i++)
    {
        if(count[i]!=0)
        {
            return false ;
        }

    }
    return true ;
}
int main()
{
    string s1 = "b" ;
    string s2 = "d" ;
    bool a = anagram(s1 , s2) ;
    cout<<a ;
}
