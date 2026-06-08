#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int initial;
        cin >> initial;
        a[i] = h - initial;
    }

    long long ans = a[0];
    for (int i = 1; i < n; i++) {
        ans += max(0, a[i] - a[i - 1]);
    }

    cout << ans << endl;

    return 0;
}