#pragma once
#include "Common.h"

class Solution {
public:
    // 41 缺失的第一个正数
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> positive_nums;
        for (int num : nums | std::views::filter([](int x) { return x > 0; })) {
            positive_nums.insert(num);
        }

        int smallest = 1;
        while (positive_nums.contains(smallest)) {  // C++20 unordered_set::contains
            smallest++;
        }

        return smallest;
    }

    //第二种方法 坐座位
    //int firstMissingPositive(vector<int>& nums) {
    //    int n = nums.size();
    //    for (int i = 0; i < n; i++)
    //    {
    //        // 因为有重复元素 不能写nums[i]=i+1; 只需要保证该元素在座位中是占据了正确的位置，而重复的元素则会向后排 
    //        while (0 < nums[i] && nums[i]<=n && nums[i]!=nums[nums[i]-1])
    //        {
    //            int j = nums[i] - 1;
    //            swap(nums[i], nums[j]);
    //        }
    //    }

    //    for (int i = 0; i < n; i++)
    //    {
    //        if (nums[i] != i + 1) return i + 1;
    //    }
    //    return n + 1;
    //}

    //42 接雨水
    int trap(vector<int>& height) {
        //暴力
        // int n=height.size();
        // if(n<=2)    return 0;
        // int res=0;
        // while(1)
        // {
        //     int flag=0;
        //     vector<int> temp;
        //     for(int i=0;i<n;i++)
        //     {
        //         if(height[i]>0)
        //         {
        //             temp.push_back(i);
        //             flag=1;   
        //             height[i]--;
        //         }
        //     }
        //     if(flag)
        //     {
        //         for(int j=0;j<temp.size()-1;j++)
        //         {
        //             res+=(temp[j+1]-temp[j]-1);
        //         }
        //     }
        //     else
        //     {
        //         return res;
        //     }
        // }
        // return res;
        //动态规划
        int n = height.size();
        if (n < 3) return 0;
        int res = 0;
        vector<int> left(n), right(n);
        left[0] = height[0], right[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        for (int j = n - 1 - 1; j >= 0; j--)
        {
            right[j] = max(right[j + 1], height[j]);
        }
        for (int i = 0; i < n; i++)
        {
            res += (min(left[i], right[i]) - height[i]);
        }

        return res;
    }


    //43 字符串相乘 
   // 写的最凌乱的一题

    void _Add(string& s1, string& s2)
    {
        //字符串相加
        ranges::reverse(s1);
        ranges::reverse(s2);
        int carry = 0;

        int cur1 = 0, cur2 = 0;
        int n1 = s1.size(), n2 = s2.size();
        if (n1 < n2)
        {
            swap(s1, s2);
            n1 = s1.size();
            n2 = s2.size();
        }
        while (cur1 < n1 && cur2 < n2)
        {
            int value = (s1[cur1] - '0') + (s2[cur2] - '0') + carry;
            s1[cur1] = static_cast<char>(value % 10 + '0');
            carry = (value) / 10;
            cur1++;
            cur2++;
        }
        while (carry != 0 && cur1 < n1)
        {
            int value = (s1[cur1] - '0') + carry;
            s1[cur1] = char((value) % 10 + '0');
            carry = (value) / 10;
            cur1++;
        }
        if (carry)   s1.push_back(carry + '0');
        ranges::reverse(s1);
    }

    string _multiply(string s, char w, int idx)
    {
        int carry = 0; // 进位
        // 从后往前遍历（处理进位）
        reverse(s.begin(), s.end());

        for (char& c : s) {
            int num = c - '0';
            int total = num * (w - '0') + carry;
            c = static_cast<char>((total % 10) + '0'); // 个位转字符
            carry = total / 10; // 计算新的进位
        }

        if (carry > 0) {
            s.push_back(static_cast<char>(carry + '0'));
        }

        reverse(s.begin(), s.end());

        while (idx--)
            s += '0';
        return s;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num2.size();
        if (num1.size() < n)  swap(num1, num2);

        if (n == 0)    return num1;
        n = num2.size();
        vector<string> v;
        for (int i = n - 1; i >= 0; i--)
        {
            v.push_back(_multiply(num1, num2[i], n - i - 1));
        }
        //for (auto it : v)  cout << it << endl;
        for (int i = 1; i < v.size(); i++)
        {
            _Add(v[0], v[i]);
        }
        return v[0];
    }

    //44 通配符匹配
    // 最近上课比较忙 
    //参考10 正则表达式匹配
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
        {
            if (p[i - 1] == '*')   dp[0][i] = true;
            else    break;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                {
                    if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = false;
                }

            }
        }
        return dp[m][n];
    }

    //45 跳跃游戏II 
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n, 0);
        for (int i = 0; i < n; i++)    hash[i] = i + nums[i];
        int idx = 0, ans = 0, left = 0, right = 0;
        //idx=n-1 就是走到最后一步了
        while (idx < n - 1)
        {
            right = max(right, hash[idx]);
            if (right == idx)
            {
                left = right;
                ans++;
            }
            idx++;
        }
        return ans;
    }

    //46 全排列 回溯
    //vector<vector<int>> permute(vector<int>& nums) {
    //    vector<vector<int>> ans;
    //    function<void(int)> dfs;
    //    int n = nums.size();
    //    dfs = [&](int idx) {
    //        if (idx == n)
    //        {
    //            ans.push_back(nums);
    //            return;
    //        }

    //        // 选择当前元素 唯一
    //        for (int i = idx; i < n; i++)
    //        {
    //            swap(nums[idx], nums[i]);
    //            dfs(idx+1);
    //            swap(nums[idx], nums[i]);
    //        }
    //    };
    //    dfs(0);
    //    return ans;
    //}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> flags(n, false);
        vector<int> temp;

        auto dfs = [&](this auto&& dfs, int idx)->void
            {
                if (idx == n)
                {
                    ans.push_back(temp);
                }
                for (int i = 0; i < n; i++)
                {
                    if (flags[i] == false)
                    {
                        flags[i] = true;
                        temp.push_back(nums[i]);
                        dfs(idx + 1);
                        temp.pop_back();
                        flags[i] = false;
                    }
                }
            };

        return ans;

    }

    //// 全排列II 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> flags(n, false);
        vector<int> temp;
        ranges::sort(nums);
        auto dfs = [&](this auto&& dfs, int idx)->void
            {
                if (idx == n)
                {
                    ans.push_back(temp);
                    return;
                }
                for (int i = 0; i < n; i++)
                {
                    if (flags[i] == false)
                    {
                        flags[i] = true;
                        temp.push_back(nums[i]);
                        dfs(idx + 1);
                        temp.pop_back();
                        flags[i] = false;
                        while (i + 1 < n && nums[i] == nums[i + 1])  i++;
                    }
                }
            };
        dfs(0);
        return ans;
    }

    //48 旋转图像
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), t = n;
        int k = 0;
        while (t > 0)
        {
            if (t == 1)    break;

            //旋转 要求原地旋转
            for (int i = 0; i < t - 1; i++)
            {
                int temp = matrix[k][k + i];
                matrix[k][k + i] = matrix[n - k - 1 - i][k];
                matrix[n - k - 1 - i][k] = matrix[n - k - 1][n - k - 1 - i];
                matrix[n - k - 1][n - k - 1 - i] = matrix[k + i][n - k - 1];
                matrix[k + i][n - k - 1] = temp;
            }
            k++;
            t -= 2;
        }
    }
    //  看了下灵神的代码，吓哭了
    //void rotate(vector<vector<int>>& matrix) {
    //    // 旋转90度=转置+行反转
    //    // 旋转270=列反转+斜对角转置 || 行反转+转置
    //    int n = matrix.size(), m = matrix[0].size();
    //    for (int i = 0; i < n; i++)
    //    {
    //        for (int j = i + 1; j < m; j++)
    //        {
    //            swap(matrix[i][j], matrix[j][i]);
    //        }
    //        ranges::reverse(matrix[i]);

    //    }

    //}
    //49 字母异位词
    // 最直观的思路
    //struct Hash
    //{
    //    int arr[26];
    //    Hash(const string& s)
    //    {
    //        memset(arr, 0, sizeof(arr));
    //        for (auto& c : s)
    //        {
    //            arr[c - 'a']++;
    //        }
    //    }
    //    ~Hash() = default;
    //    bool operator== (const Hash& h2)    const
    //    {
    //        for (int i = 0; i < 26; i++)
    //        {
    //            if (this->arr[i] != h2.arr[i]) return false;
    //        }
    //        return true;
    //    }
    //};
    //vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //    vector<vector<string>> ans;
    //    vector<Hash> hash;
    //    for (auto& s : strs)
    //    {
    //        Hash temp(s);
    //        if (hash.empty())
    //        {
    //            hash.push_back(std::move(temp));
    //            ans.push_back({ s });
    //            continue;
    //        }
    //        bool flag = false;
    //        for (int i = 0; i < hash.size(); i++)
    //        {
    //            if (hash[i] == temp)
    //            {
    //                ans[i].push_back(s);
    //                flag = true;
    //                break;
    //            }
    //        }
    //        if (!flag)
    //        {
    //            hash.push_back(std::move(temp));
    //            ans.push_back({ s });
    //        }
    //    }
    //    return ans;
    //}

    // 优化后的
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& s : strs)
        {
            string temp = s;
            ranges::sort(temp);
            hash[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            ans.push_back(std::move(it->second));
        }
        return ans;
    }

    // 50 POW
    double myPow(double x, int N) {
        if (N == 0)    return 1;
        double ans = 1;
        long long n = N;
        if (n < 0) { // x^-n = (1/x)^n
            n = -n;
            x = 1 / x;
        }
        while (n) { // 从低到高枚举 n 的每个比特位
            if (n & 1) { // 这个比特位是 1
                ans *= x; // 把 x 乘到 ans 中
            }
            x *= x; // x 自身平方
            n >>= 1; // 继续枚举下一个比特位
        }
        return ans;
    }

    //51 N 皇后
    // 回溯求解所有的方案
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queen(n, string(n, '.'));
        vector<vector<int>> attack(n, vector<int>(n, 0));
        vector<vector<string>> ans;

        auto dfs = [&](this auto&& dfs, int i, int j)
            {
                if (i >= n)    return;
                if (attack[i][j])    return;

                auto Change = [&](int i,int j,int flag)
                    {
                        static const int dx[8] = { 0,0, 1,-1, 1,1,-1,-1 };
                        static const int dy[8] = { 1,-1,0, 0, 1,-1,1,-1 };
                        attack[i][j] += flag;
                        for (int m = 1; m < n; m++)
                        {
                            for (int k = 0; k < 8; k++)
                            {
                                int nx = i + m*dx[k];
                                int ny = j + m*dy[k];
                                if (nx >= 0 && nx < n && ny >= 0 && ny < n)    attack[nx][ny] += flag;
                            }
                        }
                    };

                // 标记i，j这个位置
                Change(i, j, 1);
                queen[i][j] = 'Q';
                if (i == n - 1)// 如果是最后一行直接放入ans
                {
                    ans.push_back(queen);
                }
                else
                {
                    //如果不是则需要遍历下一行的所有位置
                    for (int k = 0; k < n; k++)
                    {
                        dfs(i+1, k);
                    }
                }

                //回溯到上一层
                queen[i][j] = '.';
                Change(i, j, -1);
                return;
            };
        for (int i = 0; i < n; i++)
        {
            dfs(0,i);
        }
        return ans;
    
    }
    // 52 N皇后的方案数
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }

};