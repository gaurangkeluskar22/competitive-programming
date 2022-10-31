#include<iostream>
#include<string>
using namespace std ;

bool palindromecheck(string &str)
{
    int low = 0 ;
    int high = str.length() - 1 ;
    while(low<high)
    {
        if(str[low]!=str[high])
        {
            return false ;
        }
        low++ ;
        high-- ;
    }
    return true ;
}
int main()
{
    string str = "ABCDCBA" ;
    bool a = palindromecheck(str) ;
    cout<<a ;
}
