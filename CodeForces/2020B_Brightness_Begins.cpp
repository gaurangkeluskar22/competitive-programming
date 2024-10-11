// problem link: https://codeforces.com/problemset/problem/2020/B

#include <iostream>
#include <vector>
#include <math.h>
#define lli long long int

#define vi vector<int>

#define vlli vector<lli>

using namespace std;

lli logic(lli k){
    lli l = ((2*k+1)-sqrt(4*k + 1))/double(2);
    lli r = ((2*k+1)+sqrt(4*k + 1))/double(2);
    while (1){
        lli mid = (l+r)/2;
        if (mid-(lli)sqrt(mid) == k){
            if ((mid - 1)-(lli)sqrt(mid-1)<k){
                return mid;
            }
            r = mid;
        }else if(mid - (lli)sqrt(mid) < k){
            l = mid+1;
        }
        
        
    }
    return l - (lli)sqrt(l);
}


int main(){

    int t;
    cin >> t;

    while(t--){
        lli k;
        cin >> k;
        cout << logic(k) << endl;
    }

    return 0;
}