#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = (int)(1e5)+10;

int n,m;
vector<int> adj[sz];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void delEdge(int u, int v) {
    auto iv = find(adj[u].begin(), adj[u].end(),v);
    *iv = -1;
    auto iu = find(adj[v].begin(),adj[v].end(),u);
    *iu = -1;
}


int dfs(int v, bool vis[]) {
    vis[v] = true;
    int cnt = 1;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
        if (*i != -1 && !vis[*i]) {
            cnt += dfs(*i, vis);
        }
    }
    return cnt;
}


bool isNotBridge(int u, int v) {
    int cnt = 0;
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
        if (*i != -1) cnt++;
    }
    if (cnt == 1) return true;
    bool vis[n];
    memset(vis, false, n);
    int cnt1 = dfs(u,vis);
    delEdge(u,v);
    memset(vis, false, n);
    int cnt2 = dfs(u,vis);
    addEdge(u,v);

    if (cnt1 > cnt2) return false;
    else return true;

}


void FleuryAlgo(int u) {
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;
        if (v != -1 && isNotBridge(u,v)) {
            cout << u << " - " << v << "  ";
            delEdge(u,v);
            FleuryAlgo(v);
        }
    }
}

void findSrc() {
    int src = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() & 1) {
            src = i;
            break;
        }
    }
    FleuryAlgo(src);
    cout << '\n';


}

int main() {

    while(cin >> n >> m) {
        for (int i = 1; i <= m; i++) {
            int u,v; cin >> u >> v;
            addEdge(u,v);
        }
        findSrc();
    }
    return 0;
}

/***

4 4
0 1
0 2
1 2
2 3

3 3
0 1
1 2
2 0

5 8
1 0
0 2
2 1
0 3
3 4
3 2
3 1
2 4

**/
