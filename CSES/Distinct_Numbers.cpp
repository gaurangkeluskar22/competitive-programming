#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n;
    cin>>n;
    int val=0;
    set<int> s1;
    for(int i=0;i<n;i++){
        cin>>val;
        s1.insert(val);
    }
    cout<<s1.size()<<endl;
    return 0;
}