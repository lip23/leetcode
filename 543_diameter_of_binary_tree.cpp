//  file:  543_diameter_of_binary_tree.cpp
//  author：lipcat
//  time：  2020-03-10 09:34


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
    // 二叉树的问题是要找到每一层的计算方法
    // 本问题，在每一个root节点要先算出左右子树的直径，然后算出过该root节点的直径，去最大值
    // 计算过root节点的直径时需要用到左右子树的最长路径
    int diameterOfBinaryTree(TreeNode* root) {
        int lp = 0;
        return root ? GetDia(root, lp) : 0;
    }
    // lp: longest path
    int GetDia(TreeNode* root, int& lp) {
        if (!root->left && !root->right) {
            lp = 0;
            return 0;
        }
        int ld = 0, l_lp = 0;
        int rd = 0, r_lp = 0;
        if (root->left) {
            ld = GetDia(root->left, l_lp);
            ++l_lp;
        }
        if (root->right) {
            rd = GetDia(root->right, r_lp);
            ++r_lp;
        }
        lp = max(l_lp, r_lp);
        return max(l_lp + r_lp, max(ld, rd));
    }
};
