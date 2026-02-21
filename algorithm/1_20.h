
#include <iostream>
#include <string> 
#include <vector>
#include <unordered_map>
#include <ranges>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:

    //1.两数之和 哈希
    vector<int> _1_twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]].push_back(i);
        }
        for (const auto& x : nums)
        {
            if (x * 2 == target)
            {
                auto it = hash[x];
                if (it.size() > 1)     return { it[0],it[1] };
            }
            else
            {
                auto it = hash.find(target - x);
                if (it != hash.end())  return { hash[x][0],it->second[0] };
            }
        }
        return {};
    }
    //2. 两数相加 链表 模拟
    ListNode* _2_addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l2 : l1;
        ListNode* cur = new ListNode();
        ListNode* newhead = cur;
        int key = 0, temp = 0;
        while (l1 || l2)
        {
            cur->next = new ListNode();
            cur = cur->next;
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            key = (x + y + temp) % 10;
            cur->val = key;
            temp = (x + y + temp) / 10;
            if (l1)  l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (temp)    cur->next = new ListNode(temp);
        return newhead->next;
    }
    
    //3 求无重复字符的最长子串
    int _3_lengthOfLongestSubstring(string s) {
        if (!s.size())   return 0;
        int l = 0, r = 0, n = s.size(), len = 0;
        int hash[129];
        while (r < n)
        {
            char in = s[r++];
            hash[in]++;
            while (hash[in] > 1)
            {
                char out = s[l++];
                hash[out]--;
            }
            len = max(len, r - l);
        }
        return len;
    }

    //4 求两个正序数组的中位数
    double _4_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //朴素解法，直接合并
        //int n = nums1.size(), m = nums2.size();
        //vector<int> nums(n + m);
        //int cur1 = 0, cur2 = 0, index = 0;
        //while (cur1 < n && cur2 < m) {
        //    if (nums1[cur1] > nums2[cur2]) nums[index++] = nums2[cur2++];
        //    else nums[index++] = nums1[cur1++];
        //}
        //while (cur1 < n) {
        //    nums[index++] = nums1[cur1++];
        //}
        //while (cur2 < m) {
        //    nums[index++] = nums2[cur2++];
        //}
        //for (auto x : nums)
        //{
        //    cout << x;
        //}
        //int x = (n + m) % 2 - 1;
        //int y = (n + m) / 2;
        //return (nums[y + x] + nums[y]) / (2.0);
        int n=nums1.size(),m=nums2.size();
        int total = n + m;
        int target = total / 2; 
        int cur1 = 0, cur2 = 0; 
        int prev_val = 0, curr_val = 0; // 记录前一个值和当前值

        for (int i = 0; i <= target; ++i) {
            prev_val = curr_val; 
            
            if (cur1 < n && (cur2 >= m || nums1[cur1] < nums2[cur2])) {
                curr_val = nums1[cur1++];
            } else {
                curr_val = nums2[cur2++];
            }
        }

        if (total % 2 == 1) {
            return curr_val;
        }
        else {
            return (prev_val + curr_val) / 2.0;
        }
    }

    //5 求最长回文子串 manachar算法 dp
    string _5_longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)    return s;
        string exp_s(s.size() * 2 + 1, '#');
        int index = 0;
        for (int i = 1; i < exp_s.size(); i += 2)
        {
            exp_s[i] = s[index++];
        }


        int max_radius = -1;
        int max_center = -1;
        int m = exp_s.size();
        vector<int> radiuses(m);

        int right_radius = -1;
        int right_center = -1;
        for (int i = 0; i < m; i++)
        {
            int radius = i < right_radius ? min(radiuses[2 * right_center - i], right_radius - i) : 1;
            while (i + radius < m && i - radius >= 0)
            {
                if (exp_s[i + radius] == exp_s[i - radius])    radius++;
                else break;
            }
            radiuses[i] = radius;

            if (radius + i > right_radius)
            {
                right_radius = i + radius;
                right_center = i;
            }
            if (radius > max_radius)
            {
                max_radius = radius;
                max_center = i;
            }
        }
        string exp_ans = exp_s.substr(max_center - max_radius + 1, 2 * max_radius - 1);
        string ans = "";
        for (auto c : exp_ans)
        {
            if (c != '#')  ans += c;
        }
        return ans;
    }

    //Z字变换 模拟
    string _6_convert(string s, int numRows) {
        string ret = "";
        if (numRows == 1 || numRows > s.size())  return s;
        vector<string> st(numRows);
        int i = 0, flag = 1;
        for (char c : s)
        {
            st[i] += c;
            i += flag;
            if (i == numRows - 1 || i == 0)    flag = -flag;
        }
        for (const string& str : st)
        {
            ret += str;
        }
        return ret;
    }
    //7 整数翻转 模拟
    int _7_reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }

        int flag = 1;
        if (x < 0) {
            flag = -1;
            x = -x; // 仅当x≠INT_MIN时可安全取反
        }

        //  转为字符串并通过C++20 views反转
        string temp = to_string(x);
        
        auto reversed_view = temp | views::reverse;
        string reversed_str(reversed_view.begin(), reversed_view.end());

        int result = 0;
        for (char c : reversed_str) {
            int digit = c - '0';

            //  result > INT_MAX / 10 → 乘10后必超
            //  result == INT_MAX / 10 且 digit > INT_MAX % 10 → 加digit后超
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return 0; // 溢出则返回0
            }

            // 无溢出时累加
            result = result * 10 + digit;
        }

        return flag * result;
    }

};


