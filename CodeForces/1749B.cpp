  #include <bits/stdc++.h>
  #include <stdio.h>
  #include <algorithm>
  #define int long long int
  #define INF 1e14
  #define pb(n) emplace_back(n)
  #define yes "YES"
  #define no "NO"
  #define all(x) x.begin(), x.end()
  using namespace std;
  const unsigned long long M = 1000000007;

  const char nl    = '\n';
  const char sp = ' ';

  void solve()
  {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;  
    int s1 = 0;
    for(auto x : a) s1+=x;
    for(auto x : b) s1+=x;

    int m = *max_element(b.begin(), b.end());
    cout<<s1-m<<nl;
  }

  int32_t main()
  {
    
    ios::sync_with_stdio(false); 
      cin.tie(NULL); cout.tie(NULL);

    int T=1; 
    cin >> T;

      for(int tc = 1; tc <= T; tc++)
      {
          //cout << "Case #" << tc << ": ";
          solve();
      }
    
    return 0;
    
  }