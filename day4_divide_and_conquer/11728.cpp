#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n];
    int arr2[m];
    int answer[n+m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    int p1 = 0, p2 = 0, idx = 0;
    while (p1 < n && p2 < m) {
        if (arr1[p1] <= arr2[p2]) {
            answer[idx++] = arr1[p1++];
        } else {
            answer[idx++] = arr2[p2++];
        }
    }
    while (p1 < n) {
        answer[idx++] = arr1[p1++];
    }
    while (p2 < m) {
        answer[idx++] = arr2[p2++];
    }
    for (int i = 0; i < n + m; i++) {
        printf("%d ", answer[i]);
    }
    return 0;
}
