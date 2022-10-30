#include<iostream>
#include<string>
using namespace std ;

bool rotation(string s1 , string s2)
{
    int n = s1.length() ;
    int m = s2.length() ;
    if(n!=m)
    {return false ;}
    return ((s1+s1).find(s2)!= string::npos) ;

}

int main()
{
    string s1 = "ABCD" ;
    string s2 = "CDAB" ;
    bool a = rotation(s1 , s2);
    cout<<a ;
}
