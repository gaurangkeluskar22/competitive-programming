#include<iostream>
#include<string>
#include<vector>
using namespace std  ;

void patternsearching(string &text , string &pattern)
{
    int m = pattern.length();
    int n = text.length();
    for(int i=0;i<=(n-m);)
    {
        bool flag = true ;
        int j ;
        for(int j=0;j<m;j++)
        {
            if(pattern[j]!=text[i+j])
            {
              flag = false ;
              break;
            }
        }
        if(flag)
        {
            cout<<i<<" " ;
        }
        else if(j==0)
        {
            i++ ;
        }
        else{
            i=i+j ;
        }
    }

}

int main()
{
    string text = "ABCEABEFABCD" ;
    string pattern = "ABCD" ;
    patternsearching(text , pattern) ;

}
