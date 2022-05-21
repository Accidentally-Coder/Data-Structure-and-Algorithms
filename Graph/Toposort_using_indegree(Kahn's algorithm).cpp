#include <bits/stdc++.h>
using namespace std;

const int sz = 1010;

vector<int> adj[sz];
int indeg[sz];

vector<int> toposort(int n)
{
    /**
    globally declare :
    1. vector<int>adj[sz]
    2. int indeg[sz]   for storing of indegree
    of each node but don't forget to initialise
    it with 0 everytime before usage
    3. keep a vector<int>res to store the vector
    which will be returned by this function in the
    main(or callee) function
    4. n=number of nodes
    **/
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
    int n,m; cin >> n >> m;
    for(int i = 0; i <= n; i++)indeg[i] = 0;
    while(m--) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    vector<int> ans = toposort(n);
    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
}


/***

Test Case :
------------
6 6
5 2
5 0
4 0
4 1
2 3
3 1


*/
