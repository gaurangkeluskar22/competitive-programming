
#include <bits/stdc++.h>
using namespace std;
void reversewords(char str[] , int N)
{
    int start = 0;
    for(int end = 0;end<N;end++)
    {
        if(str[end] == ' ')
        {
            reverse(str+start , str+ end);
            start = end + 1 ;
        }
    }
    reverse(str+start , str+N);
    reverse(str+0  , str+N) ;
}

int main()
{
    string str = "welcome to gfg" ;
    char s[str.length()] ;
    strcpy(s , str.c_str());
    reversewords(s , str.length() ) ;
    for (int i = 0; i < str.length(); i++)
        cout << s[i];


}
