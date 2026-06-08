#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 2005;

int n, m;
char grid[MAXN][MAXN];
int distS[MAXN][MAXN];
int distC[MAXN][MAXN];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    cin >> n >> m;
    int sx, sy, cx, cy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if (grid[i][j] == 'C') {
                cx = i;
                cy = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            distS[i][j] = -1;
            distC[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    distS[sx][sy] = 0;
    q.push({ sx, sy });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] != '.' && grid[nx][ny] != 'E' && grid[nx][ny] != 'S' && grid[nx][ny] != 'C') continue;
            if (distS[nx][ny] == -1) {
                distS[nx][ny] = distS[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    distC[cx][cy] = 0;
    q.push({ cx, cy });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] != '.' && grid[nx][ny] != 'E' && grid[nx][ny] != 'S' && grid[nx][ny] != 'C') continue;
            if (distC[nx][ny] == -1) {
                distC[nx][ny] = distC[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    int minS = INF, minC = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'E') {
                if (distS[i][j] != -1 && distS[i][j] < minS) {
                    minS = distS[i][j];
                }
                if (distC[i][j] != -1 && distC[i][j] < minC) {
                    minC = distC[i][j];
                }
            }
        }
    }

    int ans = INF;
    if (distS[cx][cy] != -1) {
        ans = distS[cx][cy];
    }
    if (minS != INF && minC != INF) {
        if (minS + minC < ans) {
            ans = minS + minC;
        }
    }

    if (ans == INF) {
        cout << "Bad Eureka" << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}