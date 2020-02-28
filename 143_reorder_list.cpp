//  file:  143_reorder_list.cpp
//  author：lipcat
//  time：  2020-02-28 13:17


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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }

        // 1. find mid node
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 2. constuct list1 and list2
        auto* l2_head = slow->next;
        slow->next = nullptr;
        ListNode l2(0);
        while (l2_head) {
            auto* cur = l2_head;
            l2_head = l2_head->next;
            cur->next = l2.next;
            l2.next = cur;
        }
        // 3. merge list1 and list2
        ListNode *p1 = head, *p2 = l2.next;
        while (p1 && p2) {
            ListNode *cur = p2;
            p2 = p2->next;
            cur->next = p1->next;
            p1->next = cur;
            p1 = p1->next->next;
        }
    }
};
