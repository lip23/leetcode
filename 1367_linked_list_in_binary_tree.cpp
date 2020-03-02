//  file:  1367_linked_list_in_binary_tree.cpp
//  author：lipcat
//  time：  2020-03-02 15:13


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 双层dfs
    // 先已root为起点判断是否匹配list，若不匹配则继续已左右节点为起点进行判断
    // 每次从起点开始对list进行匹配时也都是用dfs算法
    // 第一次解该题的时候用了最下面的方法，
    // 那个解法存在多次重复以某个节点为起点进行list的匹配运算，所以会导致超时
    bool isSubPath(ListNode* head, TreeNode* root) {
        // 题目描述中指明head为非空，所以此处只需判断root
        if (nullptr == root) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    bool dfs(ListNode* head, TreeNode* root) {
        if (nullptr == head) {
            return true;
        }
        if (nullptr == root) {
            return false;
        }
        return root->val == head->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};


/*
bool isSubPath(ListNode* head, TreeNode* root) {
        return IsSubPath(head, head, root);
    }
    bool IsSubPath(ListNode* head, ListNode* cur, TreeNode* root) {
        if (nullptr == cur) {
            return true;
        }
        if (nullptr == root) {
            return false;
        }
        if (root->val == cur->val && (
            IsSubPath(head, cur->next, root->left) || IsSubPath(head, cur->next, root->right))) {
            return true;
        }
        return IsSubPath(head, head, root->left) || IsSubPath(head, head, root->right);
    }
*/
