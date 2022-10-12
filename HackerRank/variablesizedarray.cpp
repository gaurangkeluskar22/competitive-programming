#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    int Nv,Ns;
    cin >> Nv>> Ns;
    vector<int> v[Nv];
    for(int i = 0; i < Nv; i++){
        int m;
        cin >> m;
        int o;
        for(int j = 0; j < m; j++){
            cin >> o;
            v[i].push_back(o);
        }
    }
    int r,s;
    for(int k = 1;k <= Ns; k++){
        cin >> r >> s;
        cout << v[r][s] << endl;
    }
    return 0;
}
