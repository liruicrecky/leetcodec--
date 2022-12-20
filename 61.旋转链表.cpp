// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int len = 1;
        ListNode *p = head, *end = nullptr;
        while (p->next) {
            p = p->next;
            len++;
            end = p;
        }

        if (len == k)
            return head;

        int rem = len > k ? k : k % len;
        if (rem == 0)
            return head;

        p = head;
        for (int i = 0; i <= len - rem - 2; i++)
            p = p->next;

        end->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
// @lc code=end
