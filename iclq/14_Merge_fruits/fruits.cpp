//哈夫曼树实现
//
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    // 使用最小堆（优先队列）
//    priority_queue<int, vector<int>, greater<int>> min_heap;
//
//    for (int i = 0; i < n; i++) {
//        int weight;
//        cin >> weight;
//        min_heap.push(weight);
//    }
//
//    int total_energy = 0;
//
//    // 当堆中不止一个元素时，继续合并
//    while (min_heap.size() > 1) {
//        // 取出两个最小的元素
//        int first = min_heap.top();
//        min_heap.pop();
//        int second = min_heap.top();
//        min_heap.pop();
//
//        // 计算合并消耗的体力
//        int sum = first + second;
//        total_energy += sum;
//
//        // 将合并后的新堆加入优先队列
//        min_heap.push(sum);
//    }
//
//    cout << total_energy << endl;
//
//    return 0;
//}