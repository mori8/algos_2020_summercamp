#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = {0, };

int main(int argc, const char * argv[]) {
    int n, max;
    cin >> n;
    int pay[n + 1];
    pay[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pay[i];
    }
    dp[1] = pay[1];
    for (int i = 2; i <= n; i++) {
        max = 0;
        for (int j = i; j >= 0; j--) {
            if (pay[j] + dp[i-j] > max) {
                dp[i] = max = pay[j] + dp[i-j];
            }
        }
    }
    cout << dp[n];
}
