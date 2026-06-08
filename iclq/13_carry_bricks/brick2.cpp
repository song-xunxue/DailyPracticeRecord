#include <iostream>  
#include <vector>  
using namespace std;
typedef long long ll;

ll merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    ll inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // 左子数组剩余元素均大于当前右子数组元素  
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }

    return inv_count;
}

ll mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    ll inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp(n);
    ll ans = mergeSort(arr, temp, 0, n - 1);
    cout << ans << endl;

    return 0;
}