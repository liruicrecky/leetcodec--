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
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode *head) {
        if (head == nullptr)
            return;

        deque<ListNode *> stk;
        ListNode *node = head->next;
        while (node != nullptr) {
            stk.push_front(node);
            node = node->next;
        }

        bool re = true;
        ListNode *p = nullptr;
        node = head;
        while (!stk.empty()) {
            if (re) {
                p = stk.front();
                stk.pop_front();
                re = !re;
            } else {
                p = stk.back();
                stk.pop_back();
                re = !re;
            }

            node->next = p;
            node = node->next;
        }

        node->next = nullptr;
    }
};
// @lc code=end
