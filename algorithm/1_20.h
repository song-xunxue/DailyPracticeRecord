
#include "Common.h"

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

    //8 字符串转换整数 模拟
    int _8_myAtoi(string s) {
        int i = 0, n = s.length();
        while (s[i] == ' ')
            i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '+' ? 1 : -1;

        int ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            int cur = s[i] - '0';
            if (ans > INT_MAX / 10 || ans * 10 > INT_MAX - cur)
                return sign == 1 ? INT_MAX : INT_MIN;

            ans *= 10;
            ans += cur;
            i++;
        }
        return ans * sign;
    }
     
    //9 回文数 模拟
    bool _9_isPalindrome(int x) {
        //如果这个数字不是回文数 转字符串翻转有可能溢出 直接判断回文字符串
        //auto s = to_string(x);
        //int left = 0, right = s.length() - 1;
        //while (left <= right)
        //{
        //    if (s[left] != s[right])    return false;
        //    left++;
        //    right--;
        //}
        //return true;

        if (x < 0 || x > 0 && x % 10 == 0) {
            return false;
        }
        int rev = 0;
        while (rev < x / 10)
        {
            int d = x % 10;
            x /= 10;
            rev = rev * 10 + d;
        }
        return rev == x / 10 || rev == x;
    }

    //10 正则表达式匹配 
    bool _10_isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;

        auto mattch = [&](int i, int j) {
            if (i == 0)    return false;
            return p[j - 1] == '.' ? true : s[i - 1] == p[j - 1];
            };
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    //匹配0次
                    dp[i][j] |= dp[i][j - 2];
                    //匹配多次
                    if (mattch(i, j - 1))
                    {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
                else
                {
                    if (mattch(i, j))
                    {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }

    // 11 盛最多水的容器 双指针
    int _11_maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n - 1, h = 0;
        while (left < right)
        {
            h = min(height[left], height[right]);
            int cur = h * (right - left);
            ans = max(ans, cur);
            if (height[left] > height[right])    right--;
            else    left++;
        }
        return ans;
    }

    //12  转化罗马数字
    string _12_intToRoman(int num) {
        const pair<int, string> valueSymbols[] = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"},
        };
        string roman;
        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
    // 13 罗马转数字
    int _13_romanToInt(string s) {
        unordered_map<char, int> hash = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = hash[s[i]];
            if (i < n - 1 && value < hash[s[i + 1]]) {
                ans -= value;
            }
            else {
                ans += value;
            }
        }
        return ans;
    }

    //14 最长公共子串
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (auto s : strs)
        {
            ans = CommonPrefix(ans, s);
        }
        return ans;
    }
    string CommonPrefix(const string& s1, const string& s2)
    {
        int length = min(s1.size(), s2.size());
        int index = 0;
        while (index < length && s1[index] == s2[index]) {
            ++index;
        }
        return s1.substr(0, index);
    }

    //15  三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1;)
        {
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] > target)  r--;
                else if (nums[l] + nums[r] < target) l++;
                else
                {
                    res.push_back({ nums[i],nums[l],nums[r] });
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])    l++;
                    while (l < r && nums[r] == nums[r + 1])    r--;
                }
            }
            i++;
            while (i < n - 1 && nums[i] == nums[i - 1])    i++;
        }
        return res;
    }

    //16 最接近的三数之和
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        int d = 1e7;
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(d - target)) {
                d = cur;
            }
            };

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r] + nums[i];
                update(sum);
                if (sum == target) {
                    return target;
                }
                if (sum > target)
                {
                    int r0 = r - 1;
                    // 移动到下一个不相等的元素
                    while (l < r0 && nums[r0] == nums[r]) {
                        --r0;
                    }
                    r = r0;
                }
                else if (sum < target)
                {
                    int l0 = l + 1;
                    while (l0 < r && nums[l0] == nums[l])
                    {
                        ++l0;
                    }
                    l = l0;
                }
            }
        }
        return d;
    }
    //18四数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (const auto& v : nums)
        {
            cout << v << " ";
        }
        cout << endl;
        vector<vector<int>> v;
        if (nums.size() < 4)   return {};
        for (int j = 0; j < nums.size() - 2;)
        {
            for (int i = j + 1; i < nums.size() - 1;)
            {
                int left = i + 1, right = nums.size() - 1;
                long long Mytarget = (long long)target - nums[i] - nums[j];


                while (left < right)
                {

                    if (nums[left] + nums[right] > Mytarget)
                    {
                        right--;
                    }
                    else if (nums[left] + nums[right] < Mytarget)
                    {
                        left++;
                    }
                    else
                    {
                        v.push_back({ nums[j],nums[i],nums[left],nums[right] });
                        right--;
                        left++;
                        while (left < right && nums[left] == nums[left - 1])   left++;
                        while (left < right && nums[right] == nums[right + 1])   right--;
                    }
                }

                i++;
                while (i < nums.size() - 1 && nums[i] == nums[i - 1])   i++;
            }
            j++;
            while (j < nums.size() - 2 && nums[j] == nums[j - 1])   j++;

        }
        return v;
    }

    //19  删除链表的第N个结点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode* cur = head;
        while (cur)
        {
            N++;
            cur = cur->next;
        }
        N -= n;
        ListNode* prev = head;
        cur = head;
        if (N == 0)
        {
            head = head->next;
            delete prev;
            return head;
        }
        while (N > 0)
        {
            prev = cur;
            cur = cur->next;
            N--;
        }
        prev->next = cur ? cur->next : nullptr;
        delete cur;
        return head;
    }

    //20 有效括号
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)  return false;

        stack<char> stc;
        unordered_map<char, char> hash = { {'(',')'},{'[',']'},{'{','}'} };


        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stc.push(c);
            else
                if (stc.empty()) return false;
                else
                {
                    char top = stc.top();
                    stc.pop();
                    if (c != hash[top])  return false;
                }

        }
        if (!stc.empty())    return false;
        return true;
    }




};


