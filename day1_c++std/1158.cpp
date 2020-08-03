#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    queue<int> q;
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int count = 0;
    while (!q.empty()) {
        count++;
        if (count == 0) count++;
        if (count % m != 0) {
            q.push(q.front());
            q.pop();
        } else {
            v.push_back(q.front());
            q.pop();
        }
    }
    printf("<");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf(">");
}
