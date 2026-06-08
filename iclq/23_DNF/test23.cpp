#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

const int N = 100;
const int M = 100;
const int K = 100;

struct Node {
    int x, y, step;
};

int main() {
    int T;
    cin >> T;

    int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

    while (T--) {
        int n, m, k, Sx, Sy;
        cin >> n >> m >> k;

        vector<vector<char>> map(n, vector<char>(m));
        bool visited[N][M][K];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'S') {
                    Sx = i;
                    Sy = j;
                }
            }
        }

        int ans = INT_MAX;
        queue<Node> q;
        q.push({ Sx, Sy, 0 });
        visited[Sx][Sy][0] = true;

        while (!q.empty()) {
            Node tmp = q.front();
            q.pop();

            if (map[tmp.x][tmp.y] == 'E') {
                ans = tmp.step;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int x = tmp.x + dir[i][0];
                int y = tmp.y + dir[i][1];
                int step = tmp.step + 1;

                if (x < 0 || x >= n || y < 0 || y >= m ||
                    map[x][y] == '#' || visited[x][y][step % k]) {
                    continue;
                }

                if (map[x][y] == '*' && (step % k != 0)) {
                    continue;
                }

                q.push({ x, y, step });
                visited[x][y][step % k] = true;
            }
        }

        if (ans == INT_MAX) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;
}