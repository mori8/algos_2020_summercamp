#include <iostream>
#include <algorithm>

#define MOD 1000000000
using namespace std;

int dp[102][10] = {0, };

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i == 0 || i == 1) {
                dp[i][j] = 1;
            } else if (j - 1 == 0) {
                dp[i][j] = (dp[i - 2][j] + dp[i - 1][j + 1]) % MOD;
            } else if (j + 1 == 10) {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    long long sum = 0;
    for (int i = 1; i <= 9; i++) {
        sum += dp[n][i];
    }
    cout << sum % MOD;
}
