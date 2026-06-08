#include <iostream>
#include <cstring>
using namespace std;

int main() {
    long long n, i, max_val, cnt, top = -1;
    long long stk[200010], a[200010] = { 0 };

    while (cin >> n) {
        memset(a, 0, sizeof(a));
        top = -1;
        max_val = 0;

        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > max_val) {
                max_val = a[i];
            }
        }

        for (i = 0; i < n; i++) {
            if (top != -1 && a[i] == stk[top]) {
                top--;
            }
            else {
                if (top != -1 && stk[top] < a[i]) {
                    break;
                }
                else {
                    stk[++top] = a[i];
                }
            }
        }

        cnt = top + 1;
        if (cnt == 0) {
            cout << "YES" << endl;
        }
        else if (cnt == 1 && stk[top] == max_val) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}