#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    int m, k;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);

        auto s = lower_bound(a, a + n, k);
        auto e = upper_bound(a, a + n, k);
        printf("%lu ", e - s);
    }
    return 0;
}
