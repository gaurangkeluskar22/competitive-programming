#include<iostream>
using namespace std ;
#include<string>
const int CHAR = 256 ;
int leftmostnonrepeating(string &str)
{
    int visited[CHAR] ;
    fill(visited , visited + CHAR , -1) ;
    int res = -1 ;
    for(int i=str.length()-1 ; i>=0 ; i--)
    {
        if(visited[str[i]] == -1)
        {
            res = i ;
            visited[str[i]] = -2 ;

        }
    }
    return res ;
}
int main()
{
    string s = "geeksforgeeks" ;
    int a = leftmostnonrepeating(s) ;
    cout<<a ;
}
