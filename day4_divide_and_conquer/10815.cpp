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
        if (binary_search(a, a + n, k)) printf("1 ");
        else printf("0 ");
    }
    return 0;
}
