#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll operation=0, left=0, i=0, j=1;
	while(i<n and j<n)
	{
		if(s[i]==')' and s[j]=='(') j++;
		else
		{
			i=j+1;
			j+=2;
			operation++;
		}
	}
	cout << operation << " " << n-i << endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
