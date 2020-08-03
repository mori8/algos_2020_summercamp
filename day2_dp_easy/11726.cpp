#include <iostream>

using namespace std;

int dp[1001] = {0, };

int t(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (dp[x] != 0) return dp[x];
    return dp[x] = (t(x-1) + t(x-2)) % 10007;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    cout << t(n) << endl;
}
