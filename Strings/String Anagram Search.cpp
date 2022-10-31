#include<iostream>
#include<string>
using namespace std ;
const int CHAR =256 ;
bool areSame(int CT[] , int CP[])
{
    for(int i=0;i<CHAR;i++)
    {
        if(CT[i]!=CP[i])
        {
            return false ;
        }
    }
    return true ;
}
bool anagram(string &txt , string &pat )
{
    int CT[CHAR] = {0} ;
    int CP[CHAR] ={0} ;
    for(int i=0;i<pat.length();i++)
    {
        CT[txt[i]]++ ;
        CP[pat[i]]++ ;
    }
    for(int i=pat.length();i<txt.length();i++)
    {
        if(areSame(CP , CT))
        {
            return true ;
        }
        CT[txt[i]]++ ;
        CT[txt[i-pat.length()]]-- ;
    }
    return false ;
}

int main()
{
    string txt = "geeks" ;
    string pat ="ek" ;
    bool a = anagram(txt , pat);
    cout<<a ;
}
