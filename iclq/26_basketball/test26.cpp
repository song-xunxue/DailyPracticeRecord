#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_knight_move(int x1, int y1, int x2, int y2) {
    return (abs(x1 - x2) == 2 && abs(y1 - y2) == 1) ||
        (abs(x1 - x2) == 1 && abs(y1 - y2) == 2);
}

bool is_blocked(int x, int y, int Cx, int Cy) {
    return (x == Cx && y == Cy) || is_knight_move(x, y, Cx, Cy);
}

long long count_paths(int Bx, int By, int Cx, int Cy) {
    vector<vector<long long>> dp(Bx + 1, vector<long long>(By + 1, 0));

    if (!is_blocked(0, 0, Cx, Cy)) dp[0][0] = 1;

    for (int i = 1; i <= By; i++) {
        if (!is_blocked(0, i, Cx, Cy)) dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i <= Bx; i++) {
        if (!is_blocked(i, 0, Cx, Cy)) dp[i][0] = dp[i - 1][0];
    }
    for (int i = 1; i <= Bx; i++) {
        for (int j = 1; j <= By; j++) {
            if (!is_blocked(i, j, Cx, Cy)) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[Bx][By];
}

int main() {
    int Bx, By, Cx, Cy;
    cin >> Bx >> By >> Cx >> Cy;
    cout << count_paths(Bx, By, Cx, Cy) << endl;
    return 0;
}
