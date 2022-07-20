#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n+5][m+5];
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                dp[i][j] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                cout << dp[i][j] << " \n"[j==m];
        return dp[n][m];

}

int main()
{
    string text1, text2; cin >> text1 >> text2;
    int ans = longestCommonSubsequence(text1,text2);
    cout << ans << '\n';
    return 0;
}



