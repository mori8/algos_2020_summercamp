#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    int miro[n][m];
    for(int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            scanf("%d", &miro[i][j]);
        }
    }
    dp[1][1] = miro[0][0];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j != 1) {
                dp[i][j] = dp[i][j-1] + miro[i-1][j-1];
            } else {
                dp[i][j] = max(max(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + miro[i-1][j-1];
            }
        }
    }
    printf("%d", dp[n][m]);
}
