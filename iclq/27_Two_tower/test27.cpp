#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    int caseNum = 1;

    while (cin >> n1 >> n2) {
        if (n1 == 0 && n2 == 0) break;

        vector<int> A(n1), B(n2);
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int j = 0; j < n2; j++) cin >> B[j];

        // DP สýื้
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << "Twin Towers #" << caseNum++ << "\n";
        cout << "Number of Tiles : " << dp[n1][n2] << "\n\n";
    }

    return 0;
}
