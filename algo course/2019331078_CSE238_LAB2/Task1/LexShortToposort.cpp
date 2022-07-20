#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = (int)(1e6)+10;

vector<int> adj[sz];
int indeg[sz];
int n,m;

vector<int> toposort()
{
    vector<int> res;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        if (!indeg[i]) s.insert(i);
    }
    if(s.empty()) return res;
    int x;
    while(!s.empty())
    {
        x = *s.begin();
        s.erase(s.begin());
        res.push_back(x);
        for (int i = 0; i<adj[x].size(); i++)
            if( --indeg[ adj[x][i] ]==0 ) s.insert(adj[x][i]);
    }
    return res;
}

int main() {
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
    if (res.size() == 0) {cout << "No Topological sort exists! Cycle detected!"; return 0;}
    cout << "The topological sort for the given input is : \n";
    for (auto i : res) {
        cout << i << ' ';
    }
    cout << '\n';

}
