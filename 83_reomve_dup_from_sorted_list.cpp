//  file:  83_reomve_dup_from_sorted_list.cpp
//  author：lipcat
//  time：  2020-02-25 07:58


class Solution {
public:
    // 每次从当前cur开始找到跟当前元素重复的所有元素, [cur, end)
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ListNode *pre = &ans, *cur = head;
        while (cur) {
            pre->next = cur;
            pre = cur;
            ListNode *end = cur;
            while (nullptr != end && end->val == cur->val) {
                end = end->next;
            }
            cur = end;
        }
        pre->next = nullptr;
        return ans.next;
    }
};

class Solution {
public:
    // 每次判断当前元素cur是否和上次已插入的元素是否val相同
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ListNode *pre = &ans, *cur = head;
        while (cur) {
            if (cur == head || cur->val != pre->val) {
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        pre->next = nullptr;
        return ans.next;
    }
};
