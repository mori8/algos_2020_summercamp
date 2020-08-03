#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    stack<char> left, right;

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        left.push(s[i]);
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'L':
                if (!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
                break;
            case 'D':
                if (!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
                break;
            case 'B':
                if (!left.empty()) {
                    left.pop();
                }
                break;
            case 'P':
                char tmp;
                cin >> tmp;
                left.push(tmp);
                break;
            default:
                break;
        }
    }
    for (;!left.empty();) {
        right.push(left.top());
        left.pop();
    }
    for (;!right.empty();) {
        printf("%c", right.top());
        right.pop();
    }
}
