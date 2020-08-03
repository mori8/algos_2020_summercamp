#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[1001] = {false, };
vector<int> tree[100100];

void dfs(int x) {
    visit[x] = true;
    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];
        if (!visit[next]) {
            dfs(next);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    visit[x] = true;
    q.push(x);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node][i];
            if (!visit[next]) {
                visit[next] = true;
                q.push(next);
            }
        }
    }

}

int main(int argc, const char * argv[]) {
    int m, n;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    int total = 0;

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i);
            total++;
        }
    }
    cout << total;
}
