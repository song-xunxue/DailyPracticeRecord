#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXT = 256; // 16*16=256

//输入处理：读取网格的尺寸和初始状态。
//矩阵构建：将每个灯的状态变化方程转换为矩阵形式，每个方程对应一个灯，变量表示按钮的按下状态。
//高斯消元：将矩阵转化为行阶梯形式，识别主元变量和自由变量。
//自由变量枚举：枚举所有自由变量的可能组合，计算对应的主元变量值，并统计按下次数的最小值。
//输出结果：打印最少按下次数。
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    int tot = n * m;
    vector<bitset<MAXT + 1>> mat(tot);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = i * m + j;
            mat[id][id] = 1;
            if (i > 0) mat[id][(i - 1) * m + j] = 1;
            if (i < n - 1) mat[id][(i + 1) * m + j] = 1;
            if (j > 0) mat[id][i * m + j - 1] = 1;
            if (j < m - 1) mat[id][i * m + j + 1] = 1;
            mat[id][tot] = grid[i][j];
        }
    }

    vector<int> pivot(tot, -1);
    int row = 0;
    for (int col = 0; col < tot && row < tot; col++) {
        int r = row;
        for (; r < tot; r++) {
            if (mat[r][col]) break;
        }
        if (r == tot) continue;
        swap(mat[row], mat[r]);
        for (int i = row + 1; i < tot; i++) {
            if (mat[i][col]) {
                mat[i] ^= mat[row];
            }
        }
        pivot[row] = col;
        row++;
    }

    for (int i = row; i < tot; i++) {
        if (mat[i][tot]) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<bool> is_free(tot, true);
    for (int i = 0; i < row; i++) {
        is_free[pivot[i]] = false;
    }

    vector<int> free_cols;
    for (int i = 0; i < tot; i++) {
        if (is_free[i]) {
            free_cols.push_back(i);
        }
    }

    int free_count = free_cols.size();
    int min_flips = INT_MAX;

    for (int mask = 0; mask < (1 << free_count); mask++) {
        int flips = 0;
        vector<int> val(tot, 0);
        for (int i = 0; i < free_count; i++) {
            if (mask & (1 << i)) {
                int col = free_cols[i];
                val[col] = 1;
                flips++;
            }
        }

        for (int i = row - 1; i >= 0; i--) {
            int col = pivot[i];
            int value = mat[i][tot];
            for (int j = col + 1; j < tot; j++) {
                if (mat[i][j]) {
                    value ^= val[j];
                }
            }
            val[col] = value;
            if (value) flips++;
        }

        min_flips = min(min_flips, flips);
    }

    cout << min_flips << endl;
    return 0;
}
