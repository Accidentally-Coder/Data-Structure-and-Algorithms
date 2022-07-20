#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = (int)(1e6)+10;

vector<int> adj[sz];
int indeg[sz];
int n,m;

void init() {
    for (int i = 0; i <= n; i++) {
        indeg[i] = 0;
    }
}

vector<int> toposort()
{
    queue<int>q;
    vector<int>res;
    for (int i = 0; i<n; i++)
        if(indeg[i]==0) q.push(i);
    if(q.empty()) return res;
    int x;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        res.push_back(x);
        for (int i = 0; i<adj[x].size(); i++)
            if( --indeg[ adj[x][i] ]==0 ) q.push(adj[x][i]);
    }
    return res;
}

int main() {
    init();
    cout << "Enter node number = ";
    cin >> n;
    cout << "\nEnter edge number = ";
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cout << "\nFrom node = "; cin  >> u;
        cout << "\nTo node = "; cin >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<int> res = toposort();
    cout << "The topological sort for the given input is : \n";
    for (auto i : res) {
        cout << i << ' ';
    }
    cout << '\n';

}
