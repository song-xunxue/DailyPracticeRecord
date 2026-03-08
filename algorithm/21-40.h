#pragma once
#include "Common.h"

class Solution {
public:
    //21 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //if (!list1 || !list2)    return list1 ? list1 : list2;
        //ListNode* newhead = new ListNode();
        //ListNode* cur = newhead;
        //while (list1 || list2)
        //{
        //    if (list1 && list2)
        //    {
        //        if (list1->val > list2->val)
        //        {
        //            cur->next = list2;
        //            cur = cur->next;
        //            list2 = list2->next;
        //        }
        //        else
        //        {
        //            cur->next = list1;
        //            cur = cur->next;
        //            list1 = list1->next;
        //        }
        //    }
        //    else
        //    {
        //        cur->next = list1 ? list1 : list2;
        //        if (list1)   list1 = list1->next;
        //        else list2 = list2->next;
        //        cur = cur->next;
        //    }
        //}
        //return newhead->next;
        // 可读性更好
        if (!list1 || !list2)    return list1 ? list1 : list2;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* newhead = new ListNode();
        ListNode* cur = newhead;
        while (cur1 && cur2)
        {
            if (cur1->val >= cur2->val)
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }
        if (cur1)    cur->next = cur1;
        else    cur->next = cur2;
        return newhead->next;
    }

    //22 生成括号
    // 经典的组合型回溯 剪枝
    void dfs(vector<string>& ans, string& temp, int left, int right, int n)
    {
        if (left > n)  return;
        if (left == right && right == n)
        {
            ans.emplace_back(temp);
            return;
        }
        //左
        if (left < n)
        {
            temp += '(';
            dfs(ans, temp, left + 1, right, n);
            temp.pop_back();
        }
        if (right < left)
        {
            temp += ')';
            dfs(ans, temp, left, right + 1, n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        dfs(ans, temp, 0, 0, n);
        return ans;
    }

    //23 合成K个有序链表 类似归并排序
    ListNode* mergeKList(ListNode* list1, ListNode* list2)
    {
        if (!list1 || !list2) return list1 ? list1 : list2;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (list1 && list2)
        {
            if (list1->val >= list2->val)
            {
                cur->next = list2;
                list2 = list2->next;
            }
            else
            {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy->next;
    }
    // 上面是合并两个的 可以遍历合并
    ListNode* _mergeKLists(vector<ListNode*>& lists, int begin, int end) {
        if (begin == end)     return lists[begin];
        int mid = (begin + end) / 2;
        ListNode* head = _mergeKLists(lists, begin, mid);
        ListNode* head2 = _mergeKLists(lists, mid + 1, end);
        return mergeKList(head, head2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)    return nullptr;
        return _mergeKLists(lists, 0, n - 1);
    }

    //24 两两交换链表中的节点
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode* newhead = new ListNode();
        ListNode* pHead = newhead;
        ListNode* p1 = head;
        while (p1 && p1->next)
        {
            ListNode* p2 = p1->next;
            ListNode* p3 = p2->next;

            pHead->next = p2;
            p2->next = p1;
            p1->next = p3;
            pHead = p1;
            p1 = p3;
        }
        return newhead->next;
    }

    // 25 K个一组的翻转 合上一题一样的
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead = new ListNode();
        ListNode* newcur = newhead;
        ListNode* cur = head;
        stack<ListNode*> s;
        while (cur)
        {
            s.push(cur);
            cur = cur->next;
            if (s.size() == k)
            {
                while (s.size())
                {
                    newcur->next = s.top();
                    s.pop();
                    newcur = newcur->next;
                }
                newcur->next = cur;
            }
        }
        return newhead->next;
    }
    

    //26 删除有序数组中的重复项
    int removeDuplicates(vector<int>& nums) {
        //双指针一次遍历
        int left = 0, right = 0, n = nums.size();
        for (; right < n; right++)
        {
            if (nums[left] != nums[right])
            {
                nums[++left] = nums[right];
            }
        }
        return left + 1;
    }

    //27 移除元素
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n)
        {
            if (nums[right] != val)
            {
                swap(nums[left++], nums[right]);
            }
            right++;
        }
        return left;
    }

    //28 匹配字符串
    // 暴力枚举
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }

    //29   两数相除 
    int divide(int dividend, int divisor) {
        int ans = 0;
        bool flag = false;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend < 0 && divisor>0 || dividend > 0 && divisor < 0) flag = true;
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;
        while (dividend <= divisor) {
            int d = divisor, q = -1;
            while (d >= dividend - d) {
                d <<= 1;
                q <<= 1;
            }
            dividend -= d;
            ans += q;
        }
        return flag ? ans : -ans;
    }

    //30 串联所有单词的子串 双指针 卡了我好久
    vector<int> findSubstring(string s, vector<string>& words)
    {
        int n = s.size(), m = words.size(), len = words[0].size();
        vector<int> ret;
        if (n < m)   return ret;

        unordered_map<string, int> hash1;
        for (const auto& w : words)    hash1[w]++;

        for (int i = 0; i < len; i++)
        {

            unordered_map<string, int> hash2;
            for (int left = i, right = i, count = 0; right + len <= n; right += len)
            {
                string in = s.substr(right, len);
                if (++hash2[in] <= hash1[in])  count++;
                if (right - left + 1 > len * m)
                {
                    string out = s.substr(left, len);
                    if (hash2[out]-- <= hash1[out])    count--;
                    left += len;
                }
                if (count == m)    ret.push_back(left);
            }
        }
        return ret;
    }

    //31 下一个排列 
    // 从后向前找降序排列[i+1,n),的前一个元素 i 为较小值，元素i  < 元素 i+1
    // 再找降序排列中的刚好小于较大值的元素j 为较大值 ， j > i
    //交换两者 i,j ( [i+1,n-1] 必定为降序序列 )并 对降序序列重排为升序 
    // [j i+1 ...j-1  i  j+1...n-1]->[j n-1 n-2 ... i ... i+1]
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

    //32  最长匹配括号
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                if (stk.size() > 1) {
                    // s[i]==')' && stk.size() >1
                    stk.pop();
                    ans = max(ans, i - stk.top());
                }
                else        stk.top() = i;
            }
        }
        return ans;
    }

    // 33 旋转数组中查找目标值
    // 二分查找 分类
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)    return nums[0] == target ? 0 : -1;
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid])
            {
                if (nums[mid] > target && target >= nums[0]) right = mid - 1;
                else left = mid + 1;
            }
            else //nums[mid] < nums[n-1]
            {
                // if(nums[mid]>target) r=mid-1;
                // else if(target > nums[mid] && target <nums[n-1])
                //     left=mid+1;
                // eles if(target > nums[n-1])
                //     r=mid-1;
                if (target > nums[mid] && target <= nums[n - 1])   left = mid + 1;
                else right = mid - 1;
            }
        }
        return  -1;
        // 查找最小值
        // int left=0,right=nums.size()-1;
        // int x=nums[right];
        // while(left<right)
        // {
        //     int mid=left+(right-left)/2;
        //     if(nums[mid] > x)   left=mid+1;
        //     else right=mid;
        // }
        // return nums[left]==target ? left :-1;
        //
    }

    //34 排序数组中查找元素的第一个位置和最后一个位置 二分模版
    vector<int> searchRange(vector<int>& nums, int target) {
        // 查找区间的左端点和右端点
        int n = nums.size();
        if (!n)  return { -1,-1 };
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[left] == target) break;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        int begin = 0;
        if (nums[left] != target) return{ -1,-1 };
        else
        {
            begin = left;
            right = n - 1;
        }

        while (left < right)
        {
            if (nums[right] == target) break;
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        return { begin,right };
    }

    //调用库函数法
    int My_lower_bound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();//  左闭右开 返回下标[0,n]
        while (left < right)
        {
            // if (nums[left] == target)    return left;
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    vector<int> searchRange2(vector<int>& nums, int target) {
        if (nums.size() == 0)  return { -1,-1 };
        int begin = My_lower_bound(nums, target);
        if (begin == nums.size() || nums[begin] != target) return { -1,-1 };
        if (begin == nums.size() - 1)    return { begin,begin };
        int end = My_lower_bound(nums, target + 1) - 1;
        return { begin,end };
    }

    //35 搜索插入位置
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)    left = mid + 1;
            else    right = mid;
        }
        return right;
    }

    //36 判断数独是否有效
    //暴力枚举
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto& v : board)
        {
            int arr[10] = { 0 };
            for (auto& c : v)
            {
                if (c != '.' && ++arr[c - '0'] > 1)    return false;
            }
        }
        static int n = 9;
        for (int i = 0; i < n; i++)
        {
            int arr[10] = { 0 };
            for (int j = 0; j < n; j++)
            {
                auto c = board[j][i];
                if (c != '.' && ++arr[c - '0'] > 1)    return false;
            }
        }
        for (int i = 0; i < n; i += 3)
        {
            for (int j = 0; j < n; j += 3)
            {
                //i,j为左上角的坐标
                auto Jude = [&](int i, int j) {
                    int arr[10] = { 0 };
                    for (int k = i; k < i + 3; k++)
                    {
                        for (int l = j; l < j + 3; l++)
                        {
                            auto c = board[k][l];
                            if (c != '.' && ++arr[c - '0'] > 1)    return true;
                        }
                    }
                    return false;
                    };

                if (Jude(i, j))   return false;
            }
        }
        return true;
    }

    //  简化一次遍历
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10];
        bool cows[9][10];
        bool palaces[3][3][10];

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                auto c = board[i][j];
                if (c == '.')  continue;
                int x = c - '0';
                if (rows[i][x] || cows[j][x] || palaces[i / 3][j / 3][x])
                {
                    return false;
                }

                rows[i][x] = cows[j][x] = palaces[i / 3][j / 3][x] = true;
            }
        }
        return true;
    }

    // 37 解数独 回溯
    void solveSudoku(vector<vector<char>>& board) {
        int nums[9] = { 0,1,2,3,4,5,6,7,8 };
        bool rows[9][9]{ false };
        bool cols[9][9]{ false };
        bool palaces[3][3][9]{ false };


        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                int x = c - '1';
                rows[i][x] = true;
                cols[j][x] = true;
                palaces[i / 3][j / 3][x] = true;
            }
        }

        function<bool(vector<vector<char>>&, int, int)> dps;
        dps = [&](vector<vector<char>>& board, int i, int j)
            {
                for (int row = i; row < 9; row++)
                {
                    int start_col = (row == i) ? j : 0;
                    for (int col = start_col; col < 9; col++)
                    {
                        auto& c = board[row][col];
                        if (c != '.')  continue;
                        for (auto x : nums)
                        {
                            if (!rows[row][x] && !cols[col][x] && !palaces[row / 3][col / 3][x])
                            {
                                rows[row][x] = cols[col][x] = palaces[row / 3][col / 3][x] = true;
                                c = char(x + '1');

                                if (dps(board, row, col + 1))  return    true;

                                c = '.';
                                rows[row][x] = cols[col][x] = palaces[row / 3][col / 3][x] = false;
                            }
                        }
                        return false;
                    }
                }
                return true;
            };
        dps(board, 0, 0);
    }

    // 38 表观数组
    string countAndSay(int n) {
        string ans = "1";
        while (--n)
        {
            string temp = "";
            int m = ans.size();
            int l = 0, r = 0;
            while (r < m)
            {
                while (ans[l] == ans[r] && r < m)    r++;
                temp += (r - l) + '0';
                temp += ans[l];
                l = r;
            }
            ans = move(temp);//移动赋值
            cout << ans << endl;
        }
        return ans;
    }

    //39 组合总和
    //void dfs(vector<int>& candidates, vector<vector<int>>& r, vector<int>& path, int target, int index)
    //{
    //    if (index == candidates.size())    return;
    //    if (target == 0)
    //    {
    //        r.emplace_back(path);
    //        return;
    //    }
    //    //跳过
    //    dfs(candidates, r, path, target, index + 1);
    //    //选择
    //    if (target - candidates[index] >= 0)
    //    {
    //        path.emplace_back(candidates[index]);
    //        dfs(candidates, r, path, target - candidates[index], index);
    //        path.pop_back();
    //    }
    //    return;
    //}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        // dfs(candidates,r,temp,target,0);
        // return r;

        // 使用 auto 自调用 lambda 实现 DFS
        function<void(int index, int current_target)> dfs;
        dfs = [&](int index, int current_target) {
            if (index == candidates.size()) {
                return;
            }
            if (current_target == 0) {
                result.push_back(path);
                return;
            }

            dfs(index + 1, current_target);

            if (current_target - candidates[index] >= 0) {
                path.push_back(candidates[index]);
                dfs(index, current_target - candidates[index]);
                path.pop_back();
            }
            };

        dfs(0, target);

        return result;
    }

    // 组合总和II
    void dps(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& path, int target, int idx)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        if (idx == candidates.size())  return;
        //跳过
        // dps(candidates,ans,path,target,idx+1);

        //选择
        for (int i = idx; i < candidates.size(); i++)
        {
            // 遍历去重 +
            if (i > idx && candidates[i] == candidates[i - 1])   continue;
            // 剪枝跳过
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            dps(candidates, ans, path, target - candidates[i], i + 1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        ranges::sort(candidates);
        dps(candidates, ans, path, target, 0);
        return ans;
    }
};

