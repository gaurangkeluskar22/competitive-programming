#include<iostream>
#include<string>
#include<vector>
using namespace std ;

#define d  10
const int q = 101 ;

vector<int> rabinKarp(string &text , string &pattern , int n , int m)
{
    int h=1 ;
    vector<int> res ;
    for(int i=1;i<m;i++)
    {
        h = (h*d)%q ;
    }
    int p = 0;
    int t = 0;
    for(int i=0;i<m;i++)
    {
        p = (p*d + pattern[i])%q ;
        t = (t*d + text[i])%q;
    }
    for(int i=0;i<=(n-m);i++)
    {
        if(p==t)
        {
            bool flag = true ;
            for(int j=0;j<m;j++)
            {
                if(pattern[j]!=text[i+j])
                {
                    flag = false ;
                    break ;
                }
            }
            if(flag)
            {
                res.push_back(i);
            }
        }
        if(i<n-m)
        {
            t = ((d*(t - text[i]*h)) + text[i+m])%q ;
        }
        if(t<0)
        {
            t = t +q ;
        }
    }
    return res ;
}
int main()
{
    string text = "ABCABCDABCD" ;
    string pattern = "ABCD" ;
    vector<int>a ;
    a = rabinKarp(text , pattern , 10 , 4);
    for(int x : a)
    {
        cout<<x<< " " ;
    }
}
