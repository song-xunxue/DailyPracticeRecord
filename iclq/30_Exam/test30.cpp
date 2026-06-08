#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> t(m), w(m), v(m), dp(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> t[i] >> w[i];
        v[i] = t[i] * w[i];  // º€÷µ
    }

    for (int i = 0; i < m; i++) {
        for (int j = n; j >= t[i]; j--) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
