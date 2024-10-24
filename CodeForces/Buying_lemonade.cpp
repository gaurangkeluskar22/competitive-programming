#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Sort the array to facilitate calculations.
        sort(a.begin(), a.end());
        
        ll p = 0;
        for(int i = 0; i < n; i++) {
            if (i == 0) {
                p += a[i] * (n - i);
            } else {
                p += (a[i] - a[i - 1]) * (n - i);
            }
            
            // If the current cumulative sum `p` meets or exceeds `k`, output result.
            if (k <= p) {
                cout << k + i << endl;
                break;
            }
        }
    }
    return 0;
}