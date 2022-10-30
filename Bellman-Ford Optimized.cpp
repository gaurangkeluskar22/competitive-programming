#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

int head[N], to[M], cost[M], nxt[M], ne;

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int a, int b, int c){
    addEdge(a, b, c);
    addEdge(b, a, c);
}


/// Time Complexity O(N * M), N = number of node & M = number of edges
ll dist[N];
bool inQ[N];
bool bellmanOptimized(ll src, ll dest){
    memset(inQ, 0, sizeof inQ);
    for(int i = 0; i < n; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    /// queue that has all candidates
    queue<int> q;
    q.push(src);
    inQ[src] = 1;
    for(int i = 0; i < n; ++i){
        /// Loop over all edges (of all candidates)
        int s = q.size();
        while(s--){
            int u = q.front();
            q.pop();
            inQ[u] = 0;
            /// Iterate neighbours
            for(int e = head[u]; ~e; e = nxt[e]){
                int v = to[e], c = cost[e];
                if(dist[u] + c < dist[v]){
                    dist[v] = dist[u] + c;
                    if(!inQ[v]){
                        q.push(v);
                        inQ[v] = 1;
                    }
                }
            }
        }
        if(i == n - 1 && q.size()) return true;
        if(q.empty()) break;
    }
    return false;
}

int main(){
     cin >> n >> m;
     init();
     for(ll i = 0; i < m; ++i){
        ll u, v, c;
        cin >> u >> v >> c;
        addBiEdge(u, v, c);
     }
     ll src, dest;
     cin >> src >> dest;
     if(bellmanOptimized(src, dest)){
        cout << "There is a negative cycle\n";
     }
     else{
        cout << "No negative cycles found.\n";
        cout << dist[dest] << '\n';
     }

}
/*
5 7
0 1 3
0 2 1
1 2 7
3 1 5
2 3 -13
1 4 100
3 4 7
0 4
*/
