//Link to the problem "https://codeforces.com/contest/1739/problem/B"

#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int d[n];
		int count = 0;
		int out[n];
		for(int i=0;i<n;i++)
		{
			cin >> d[i];
		}
 
		out[0] = d[0];
		int j = 1;
 
		for(int i=1;i<n;i++)
		{
			if(d[i]-out[j-1]>0 || d[i]==0)
			{
				out[j] = d[i]+out[j-1];
				j++;
			}
			else
			{
				count = 1;
				break;
			}
		}
		if(count == 0)
		{
			for(int i=0;i<n;i++) cout << out[i] << " ";
			cout << endl;
		}
		else cout << "-1" << endl;
	}
}
