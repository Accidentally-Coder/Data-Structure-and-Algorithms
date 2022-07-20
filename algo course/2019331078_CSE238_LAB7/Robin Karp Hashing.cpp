#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 1005;

string txt, pat;
ll Hash[2][sz], P[2][sz];
ll Base[] = {1231,1567};
ll Mod[] = {1000000000 + 7, 1000000000 + 9};

void init() {
    P[0][0] = P[1][0] = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < sz; j++) {
            P[i][j] = (P[i][j-1]*Base[i])%Mod[i];
        }
    }
}

pair<ll,ll> initHash(string s) {
    int n = s.size();
    Hash[0][0] = Hash[1][0] = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            Hash[i][j] = (Hash[i][j-1] * Base[i] + (s[j-1]-'a'+1)) % Mod[i];
        }
    }
    return make_pair(Hash[0][n], Hash[1][n]);
}

ll getHash(int l, int r, int h) {
    int n = (r-l+1);
    ll ans = (Hash[h][r] - Hash[h][l-1] * P[h][n]) % Mod[h];
    if (ans < 0) ans += Mod[h];
    return ans;
}

pair <ll,ll> getHash(int l, int r) {
    ll h0 = getHash(l,r,0);
    ll h1 = getHash(l,r,1);
    return make_pair(h0,h1);
}

int main() {
    init();
    while (cin >> txt >> pat) {
        auto patHash = initHash(pat);
        auto txtHash = initHash(txt);

        cout << patHash.first << ' ' << patHash.second << '\n';
        for (int i = 0; i < txt.size() - pat.size() + 1; i++) {
            int l = i+1, r = (i+pat.size()-1)+1;
            auto cur = getHash(l,r);
            if (cur == patHash) {
                cout << "Pattern found at " << i << '\n';
            }
        }
    }
    return 0;
}

