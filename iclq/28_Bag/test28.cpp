#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000000;
const int MAXN = 2005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, V;
    cin >> n >> V;

    vector<int> p(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(V, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];

        // 继承前 i-1 的方案
        for (int j = 0; j < V; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
        }

        // 添加 p[i]
        for (int j = 0; j < V; j++) {
            int mod = (j + p[i]) % V;
            dp[i][mod] = (dp[i - 1][j] + dp[i][mod]) % MOD;
        }
    }

    cout << dp[n][0] - 1 << "\n";  // 减去空集方案
    return 0;
}
