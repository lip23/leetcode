//  file:  160_intersection_of_two_linked_lists.cpp
//  author：lipcat
//  time：  2020-04-08 00:19


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
    // l1 : a*   （*表示相交部分，可以为null）
    // l2 : b*
    // a*b* 则 b*a* 一定会存在两个相同的节点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != pb) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};
