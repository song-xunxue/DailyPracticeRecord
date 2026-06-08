#include <iostream>
#include<vector>
#include <bitset>
#include <queue>


using namespace std;
struct Node {
    int x, y, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    pair<int, int> start, target;
    vector<pair<int, int>> portals;
    bool foundN = false, foundC = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'N') {
                start = make_pair(i, j);
                foundN = true;
            }
            if (grid[i][j] == 'C') {
                target = make_pair(i, j);
                foundC = true;
            }
            if (grid[i][j] == 'E') portals.push_back(make_pair(i, j));
        }
    }

    if (!foundN || !foundC) {
        cout << "Bad Eureka\n";
        return 0;
    }

    // visited 压缩存储
    vector< bitset<2000> > visited(n);
    queue<Node> q;
    visited[start.first][start.second] = 1;
    q.push({ start.first, start.second, 0 });

    bool teleport_used = false;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, d = cur.d;

        if (x == target.first && y == target.second) {
            cout << d << "\n";
            return 0;
        }

        // 四方向扩展
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] != 'M' && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({ nx, ny, d + 1 });
                }
            }
        }

        // 传送点展开
        if (grid[x][y] == 'E' && !teleport_used) {
            teleport_used = true;
            for (size_t i = 0; i < portals.size(); i++) {
                int px = portals[i].first, py = portals[i].second;
                if (!visited[px][py]) {
                    visited[px][py] = 1;
                    q.push({ px, py, d }); // 瞬移不耗时
                }
            }
        }
    }

    cout << "Bad Eureka\n";
    return 0;
}


//bitset压缩，16MB限制 全都能过了