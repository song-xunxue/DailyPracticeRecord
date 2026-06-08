#include <iostream>  
#include <queue>  
#include <cstring>  
using namespace std;

struct Node {
    int x, y;
    int step;
};

const int dir_x[4] = { 0, 0, 1, -1 };
const int dir_y[4] = { 1, -1, 0, 0 };

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    char map[n][m];
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    queue<Node> q;
    bool visited[n][m];
    memset(visited, false, sizeof(visited));

    q.push({ x1, y1, 0 });
    visited[x1][y1] = true;

    int ans = -1;
    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= k; ++j) {
                int x = current.x + dir_x[i] * j;
                int y = current.y + dir_y[i] * j;

                if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#') {
                    break;
                }
                if (visited[x][y]) {
                    continue;
                }
                if (x == x2 && y == y2) {
                    ans = current.step + 1;
                    cout << ans << endl;
                    return 0;
                }
                q.push({ x, y, current.step + 1 });
                visited[x][y] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}