#include<iostream>
using namespace std ;

#include<string>
const int CHAR = 256 ;
int leftmost(string &str)
{
    int fIndex[256] ;
    fill(fIndex , fIndex+CHAR , -1) ;
    int res = INT_MAX ;
    for(int i=0;i<str.length();i++)
    {
        int fi = fIndex[str[i]] ;
        if(fi==-1)
        {
            fIndex[str[i]] = i ;
        }
        else{
            res = min(res , fi) ;
        }
    }
    return (res==INT_MAX)? -1 : res ;

}

int main()
{
    string s = "abccbd" ;
    int a = leftmost(s) ;
    cout<<a ;
}
