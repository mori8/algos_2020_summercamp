#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int age;
    char name[102];
    int join;
} member [100000];

bool cmp(struct person a, struct person b) {
    if (a.age == b.age)
        return a.join < b.join;
    else
        return a.age < b.age;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d" "%s", &member[i].age, member[i].name);
        member[i].join = i;
    }
    sort(member, member + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", member[i].age, member[i].name);
    }
}
