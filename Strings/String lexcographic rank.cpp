#include<iostream>
#include<string>
using namespace std ;
const int CHAR = 256 ;
int fac(int n)
{
    if(n==0)
    {
        return 1 ;
    }
    return n*fac(n-1) ;
}
int lexrank(string &txt)
{
    int res = 1 ;
    int n = txt.length();
    int mul = fac(n) ;
    int count[CHAR] = {0} ;
    for(int i=0;i<n;i++)
    {
        count[txt[i]]++ ;
    }
    for(int i=1;i<CHAR;i++)
    {
        count[i] += count[i-1] ;
    }
    for(int i=0;i<n-1;i++)
    {
        mul = mul/(n-i) ;
        res = res + count[txt[i]-1]*mul ;
        for(int j=txt[i];j<CHAR;j++)
        {
            count[j]-- ;
        }
    }
    return res  ;
}


int main()
{
    string txt = "DCBA" ;
    int a = lexrank(txt);
    cout<<a ;
}
