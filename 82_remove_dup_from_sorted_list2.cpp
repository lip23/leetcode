//  file:  82_remove_dup_from_sorted_list2.cpp
//  author：lipcat
//  time：  2020-02-24 23:59

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
    // 用beg和end两个指针，每次找到当前元素的集合[beg, end), 如果beg->next == end则表示没有重复元素
    // 则将结果直接放到结果链表的最后部
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ListNode *beg = head, *end = head, *pre = &ans;
        int cnt = 0;
        while (nullptr != end) {
            while (nullptr != end && beg->val == end->val) {
                end = end->next;
            }
            if (end == beg->next) {
                pre->next = beg;
                pre = pre->next;
            }
            beg = end;
        }
        // 注意，之前忘记这个处理，排查了很久
        pre->next = nullptr;
        return ans.next;
    }
};
