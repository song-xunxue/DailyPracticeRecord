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
}

