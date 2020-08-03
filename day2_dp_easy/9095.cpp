#include <iostream>

using namespace std;

int dp[1001] = {0, };

int solve(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3) return 4;
    return dp[x] = solve(x-1) + solve(x-2) + solve(x-3);
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        cout << solve(k) << endl;
    }
}
