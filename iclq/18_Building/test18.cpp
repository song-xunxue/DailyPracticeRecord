//这是copy的代码改为C++的，
// https://blog.csdn.net/Cosmo9/article/details/133101435?fromshare=blogdetail&sharetype=blogdetail&sharerId=133101435&sharerefer=PC&sharesource=Song_qingxun&sharefrom=from_link
//我的代码最后一个用例一直出现无效内存引用，我觉得可能是超出内存限制了

#include <iostream>
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <cstdbool>  
using namespace std;
#define WIDTH 1000010  
#define HASH_SIZE 1000003  
int T, i, n, temp, color_class, top_color = -1, top_height = -1;
int color[WIDTH], height[WIDTH], stack_color[WIDTH], stack_height[WIDTH];
typedef struct HashNode
{
    int key;
    int value;
    bool used;
}HashNode;
HashNode hashTable[HASH_SIZE];
unsigned int _hash(int key)
{
    unsigned int h = 0;
    h = key % HASH_SIZE;
    return h;
}
void insert(int key, int value)
{
    unsigned int pos = _hash(key);
    while (hashTable[pos].used && hashTable[pos].key != key)  pos = (pos + 1) % HASH_SIZE;
    hashTable[pos].key = key;
    hashTable[pos].value = value;
    hashTable[pos].used = true;
}
int search(int key)
{
    unsigned int pos = _hash(key);
    while (hashTable[pos].used && hashTable[pos].key != key)  pos = (pos + 1) % HASH_SIZE;
    if (hashTable[pos].used)  return hashTable[pos].value;
    else  return 0;
}
int main()
{
    cin >>T;
    while (T-- > 0)
    {
        while (top_color != -1)
        {
            top_color--;
            top_height--;
        }
        memset(hashTable, 0, sizeof(hashTable));
        color_class = 0;
        cin >> n;
        for (i = 0; i < n; i++)  cin>>color[i];
        for (i = 0; i < n; i++)  cin >> height[i];
        for (i = 0; i < n; i++)
        {
            if (top_height == -1 || height[i] < stack_height[top_height])
            {
                stack_color[++top_color] = color[i];
                stack_height[++top_height] = height[i];
                int count = search(color[i]) + 1;
                insert(color[i], count);
                if (count == 1)  color_class++;
            }
            else
            {
                while (top_height != -1 && height[i] >= stack_height[top_height])
                {
                    int count = search(stack_color[top_color]) - 1;
                    insert(stack_color[top_color], count);
                    if (count == 0)  color_class--;
                    top_height--;
                    top_color--;
                }
                if (top_height == -1 || height[i] < stack_height[top_height])
                {
                    stack_color[++top_color] = color[i];
                    stack_height[++top_height] = height[i];
                    int count = search(color[i]) + 1;
                    insert(color[i], count);
                    if (count == 1)  color_class++;
                }
            }
            printf("%d%c", color_class, i == n - 1 ? '\n' : ' ');

        }
    }
    return 0;
}


//我的代码
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <stack>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int T;
//    cin >> T;
//
//    while (T--) {
//        int n;
//        cin >> n;
//
//        vector<int> color(n), height(n);
//        for (int i = 0; i < n; i++) cin >> color[i];
//        for (int i = 0; i < n; i++) cin >> height[i];
//
//        // 使用栈来存储颜色和高度
//        stack<int> color_stack, height_stack;
//        unordered_map<int, int> color_count;
//        int color_class = 0;
//
//        vector<int> result;
//
//        for (int i = 0; i < n; i++) {
//            // 当栈为空或当前高度小于栈顶高度时，直接入栈
//            if (height_stack.empty() || height[i] < height_stack.top()) {
//                color_stack.push(color[i]);
//                height_stack.push(height[i]);
//
//                // 更新颜色计数
//                if (color_count[color[i]] == 0) color_class++;
//                color_count[color[i]]++;
//            }
//            else {
//                // 弹出所有高度小于等于当前高度的元素
//                while (!height_stack.empty() && height[i] >= height_stack.top()) {
//                    int top_color = color_stack.top();
//                    color_count[top_color]--;
//                    if (color_count[top_color] == 0) color_class--;
//
//                    color_stack.pop();
//                    height_stack.pop();
//                }
//
//                // 将当前元素入栈
//                if (height_stack.empty() || height[i] < height_stack.top()) {
//                    color_stack.push(color[i]);
//                    height_stack.push(height[i]);
//
//                    if (color_count[color[i]] == 0) color_class++;
//                    color_count[color[i]]++;
//                }
//            }
//
//            result.push_back(color_class);
//        }
//
//        // 输出结果
//        for (int i = 0; i < n; i++) {
//            cout << result[i];
//            if (i < n - 1) cout << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
