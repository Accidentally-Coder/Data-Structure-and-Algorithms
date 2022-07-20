#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = (int)(1e6)+10;

vector<int> adj[sz];
int indeg[sz];
bool vis[sz];
int n,m;
void print(list<int> res) {
    while(!res.empty()) {
            cout << res.front() << ' ';
            res.pop_front();
    }
    cout << '\n';
}

void findAllToposort (auto &res) {

    for (int i = 0; i < n; i++) {
        if (!indeg[i] && !vis[i]) {
            for (auto u : adj[i]) {
                indeg[u]--;
            }
            res.push_back(i);
            vis[i] = 1;
            findAllToposort(res);
            for (int u : adj[i]) {
                indeg[u]++;
            }
            res.pop_back();
            vis[i] = 0;
        }
    }
    if (res.size() == n) {
        print(res);
    }
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
    list <int> res;
    cout << "\nAll Topological Sort for the given input : \n";
    findAllToposort(res);
    cout << '\n';

}

/***

6 6
5 0
5 2
2 3
3 1
4 0
4 1

*/
