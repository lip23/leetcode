//  file:  23_merge_k_sorted_lists.cpp
//  author：lipcat
//  time：  2020-02-26 13:39


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
    // 每次遍历从集合中选一个最小的点
    // 将最小的点插入到结果链表中，
    // 更新最小点所在的链表，链表头变为最小点的下一个节点
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ans(0);
        ListNode *pre = &ans;
        while (true) {
            ListNode **cur = nullptr;
            for (auto& list : lists) {
                if (nullptr == list) {
                    continue;
                }
                if (nullptr == cur || (*cur)->val > list->val) {
                    cur = &list;
                }
            }
            if (nullptr == cur) {
                break;
            }
            pre = pre->next = *cur;
            *cur = (*cur)->next;
        }
        pre->next = nullptr;
        return ans.next;
    }
};

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
    // 两两合并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ans(0);
        for (auto* list : lists) {
            ListNode ml(0);
            ListNode* p1 = list, *p2 = ans.next, *pre = &ml;
            while (p1 && p2) {
                if (p1->val < p2->val) {
                    pre = pre->next = p1;
                    p1 = p1->next;
                } else {
                    pre = pre->next = p2;
                    p2 = p2->next;
                }
            }
            nullptr != p1 ? pre->next = p1 : pre->next = p2;
            ans = ml;
        }
        return ans.next;
    }
};
