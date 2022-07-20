#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = (int)1e5 + 10;

struct Heap {
    int tree[sz],n;
    const static int root = 1;
    Heap() {
        memset(tree,-1,sizeof(tree));
        n = 0;
    }
    void insert(int data) {
        tree[++n] = data;
        int cur = n;
        while(cur/2 >= root && tree[cur/2] < tree[cur]) {
            swap(tree[cur/2],tree[cur]);
            cur = cur/2;
        }
    }
    void heapify(int cur) {
        int left = 2*cur;
        int right = 2*cur + 1;
        int mx = cur;
        if (left <= n && tree[left] > tree[mx]) {
            mx = left;
        }
        if (right <= n && tree[right] > tree[mx]) {
            mx = right;
        }
        if (mx != cur) {
            swap(tree[mx],tree[cur]);
            heapify(mx);
        }
    }
    int top() {return tree[root];}
    void pop(){
        swap(tree[root],tree[n]);
        n--;
        heapify(root);
    }
    void printTree(int cur,string pre = " ") {
        cout << pre << cur << "(" << tree[cur] << ")" << '\n';
        int left = 2*cur;
        int right = 2*cur + 1;
        if (left <= n) printTree(left,pre+' ');
        if (right <= n) printTree(right,pre+' ');
    }
    void printTree() {
        printTree(root);
    }
};

int main() {
    int a[sz];
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    Heap heap = Heap();
    for (int i = 0; i < n; i++) {
        cout << "Inserting " << a[i] << " to the heap \n";
        heap.insert(a[i]);
        heap.printTree();
    }
    heap.printTree();
    return 0;
}

