#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    queue<pair<int, int>> q;
    int m, n;
    cin >> m >> n;
    int tomato[n][m];
    int days[n][m];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            days[i][j] = -1;
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                days[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (tomato[nx][ny] == 0 && days[nx][ny] == -1) {
                    days[nx][ny] = days[a][b] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int max_day = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0 && days[i][j] == -1) {
                cout << -1 <<"\n";
                return 0;
            }
            if (days[i][j] > max_day) {
                max_day = days[i][j];
            }
        }
    }
    cout << max_day << "\n";
    return 0;
}
