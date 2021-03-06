83. 删除排序链表中的重复元素

https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

解法一：
快慢指针

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head, *fast = slow->next;
        while (fast != nullptr) {
            if (fast->val != slow->val) {
                slow = slow->next;
                fast = fast->next;
            } else {
                fast = fast->next;
                slow->next = fast;
            }
        }
        slow->next = nullptr;
        return head;
    }
};

解法二:
使用一个指针

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == cur->val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};
