#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = 1e3;

vector<int>adj[sz], cost[sz];
priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
int par[sz];

void init(int n) {
    for (int i = 0; i <= n; i++)
        par[i] = i;
}

int find(int n) {
    if (par[n] == n) {
        return n;
    }
    return par[n] = find(par[n]);
}

int kruskal(int n) {
    int p, q, w, tot = 0, u, v;
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < adj[u].size(); i++) {
            p = min(u, adj[u][i]);
            q = max(u, adj[u][i]);
            pq.push({cost[u][i],{p,q}});
        }
    }
    vector <pair <int, pair <int,int>>> ans;

    while(!pq.empty()) {
        int w = pq.top().first;
        int p = pq.top().second.first;
        int q = pq.top().second.second;
        pq.pop();

        u = find(p);
        v = find(q);

        if (u!=v) {
            par[u] = v;
            ans.push_back({w,{p,q}});
            tot += w;
        }
    }
    cout << "Edge List in Minimum Spanning Tree (using Kruskal) : \n";
    for (auto &x : ans) {
        w = x.first;
        p = x.second.first;
        q = x.second.second;
        cout << "( " << p << ", " << q << " )  =  " << w << '\n';
    }
    return tot;
}

int main() {
    int n,m; cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    int tot = kruskal(n);
    cout << "Minimum Cost = " << tot << '\n';

    return 0;
}
