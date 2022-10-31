#include<iostream>
using namespace std ;
#include<string>
void lpsfill(string s , int lps[])
{
    int n = s.length();
    lps[0] = 0 ;
    int len = 0;
    int i=1;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            lps[i] = len + 1 ;
            len++ ;
            i++ ;
        }
        else{
            if(len==0)
            {
                lps[i]==0 ;
                i++ ;
            }
            else{
                lps[i] = lps[len-1] ;
            }
        }
    }
    /*for(i=0;i<5;i++)
    {
        cout<<lps[i]<<" " ;
    }*/
}


void kmp(string &text , string &pattern)
{
    int n = text.length() ;
    int m =pattern.length() ;
    int lps[m] ;
    lpsfill(pattern , lps) ;
    int i = 0 ;
    int j=0 ;
    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++ ; j++ ;
        }
        if(j==m)
        {
            cout<<i-j<<" " ;
            j = lps[j-1] ;

        }
        else if(i<n && (text[i]!=pattern[j]))
        {
            if(j==0)
            {
                i++ ;
            }
            else{
                j = lps[j-1] ;
            }
        }
    }



}
int main()
{
    string text = "aaaaab" ;
    string pattern = "aaaa" ;
    kmp(text , pattern) ;
}
