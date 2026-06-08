#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 比较函数，用于从大到小排序
bool compare(int a, int b) {
    return a > b;
}

// 检查函数，判断是否可以将绳子切割成至少K段长度为mid的绳子
bool check(int mid, const vector<int>& L, int K) {
    if (mid == 0) return false; // 防止除以零
    int count = 0;
    for (int length : L) {
        count += length / mid;
        if (count >= K) return true; // 提前终止，提高效率
    }
    return count >= K;
}

// 二分查找函数
int binary_search(int l, int r, const vector<int>& L, int K) {
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, L, K)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N, K;
    cin >> N;
    vector<int> L(N);
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> L[i];
        sum += L[i];
    }

    // 从大到小排序
    sort(L.begin(), L.end(), compare);

    cin >> K;

    int l = 1;
    int r = sum / K; // 最大可能长度

    int ans = binary_search(l, r, L, K);
    cout << ans << endl;

    return 0;
}