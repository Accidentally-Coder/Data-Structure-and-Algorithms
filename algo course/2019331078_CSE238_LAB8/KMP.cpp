#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void LPS(string pat, int sz, int lps[]) {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < sz) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
            continue;
        } else {
            if (len) {
                len = lps[len-1];
                continue;
            } else {
                lps[i++] = 0;
                continue;
            }
        }
    }
}

void KMP(string txt, string pat) {
    int patlen = pat.size();
    int txtlen = txt.size();

    int lps[patlen+5] = {0};

    LPS(pat,patlen,lps);

    int i = 0, j = 0;
    while (i < txtlen) {
        if (pat[j] == txt[i]) {
            i++,j++;
        }
        if (j == patlen) {
            cout << "Pattern found at index " << i-j << '\n';
            j = lps[j-1];
        } else if (i < txtlen && pat[j] != txt[i]) {
            if (j) j = lps[j-1];
            else i++;
        }
    }
}

int main() {
    string txt, pat;
    while(cin >> txt >> pat)
        KMP(txt,pat);
    return 0;
}

/***

TEST CASE :
===========

abcdab
bc

Pattern found at index 1


ababdabacdababcabab
ababcabab

Pattern found at index 10


bangla
banana


pattern
pat

Pattern found at index 0


MISSISSIPPI
ISSI

Pattern found at index 1
Pattern found at index 4



*/
