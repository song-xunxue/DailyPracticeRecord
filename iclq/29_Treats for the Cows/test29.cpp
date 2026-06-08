#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
int v[MAXN];
int dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    // 区间 DP，从小区间逐步扩展
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            int day = n - (r - l);  // 当前卖糖果的天数
            if (l == r) {
                dp[l][r] = v[l] * day;
            }
            else {
                dp[l][r] = max(v[l] * day + dp[l + 1][r],
                    v[r] * day + dp[l][r - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}
