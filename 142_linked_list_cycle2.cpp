//  file:  142_linked_list_cycle2.cpp
//  author：lipcat
//  time：  2020-04-07 23:47


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // l1: 线段长度, l2: 环长度, l1 + x相交的时候所在的位置
    // ts = l1 + x;       total_slow
    // tf = 2(l1 + x);    total_fast
    // tf - ts = nl2;
    // ====> tf - ts = l1 + x = nl2
    // ====> l1 = nl2 - x;    l1的长度等于nl2的长度减去x，所以如果在环中先走x步，然后l1就会于nl2相遇
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
