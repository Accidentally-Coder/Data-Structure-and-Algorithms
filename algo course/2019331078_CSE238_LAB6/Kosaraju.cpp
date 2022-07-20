#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = (int)(1e5)+5;

vector<int> adj[sz],trans[sz];
vector<int> order,scc;
bool vis[sz];

void dfs(int src) {

    vis[src] = true;
    for(int i = 0; i < adj[src].size(); i++) {
        int child = adj[src][i];
        if(!vis[child])dfs(child);
    }
    order.push_back(src);
}

void dfs1(int src) {
    vis[src]=true;

    for(int i = 0; i < trans[src].size(); i++){
        int child = trans[src][i];
        if (!vis[child]) dfs1(child);
    }
    scc.push_back(src);
}

int main() {
    int n,m;
    while(cin >> n >> m) {
        for (int i = 0; i <= n; i++) {
            adj[i].clear(),trans[i].clear(),vis[i] = false;
        }
        order.clear();
        for (int i = 1; i <= m; i++) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            trans[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        memset(vis,0,sizeof vis);
        cout << "Following are the Strongly Connected Components in the given graph : \n";
        for (int i = 1; i <= n; i++) {
            if (!vis[order[n-i]]) {
                scc.clear();
                dfs1(order[n-i]);
                for (auto x : scc) {
                    cout << x << ' ';
                }
                cout << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}


/**

Test Case :
-----------
8 12
0 1
7 1
1 6
6 7
6 0
0 4
6 4
6 5
5 3
3 4
4 2
2 3


5 5
0 3
1 0
2 1
0 2
3 4


*/
