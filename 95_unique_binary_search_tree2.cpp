//  file:  95_unique_binary_search_tree2.cpp
//  author：lipcat
//  time：  2020-03-02 23:04


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
    // 依次以i为根节点，然后递归求解1～i和i+1～n所构成的子树
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : GenTrees(1, n);
    }
    vector<TreeNode*> GenTrees(const int beg, const int end) {
        if (beg > end) {
            return {nullptr};
        }
        vector<TreeNode*> trees;
        for (int i = beg; i <= end; ++i) {
            vector<TreeNode*> lt = GenTrees(beg, i - 1);
            vector<TreeNode*> rt = GenTrees(i + 1, end);
            for (TreeNode* left : lt) {
                for (TreeNode* right : rt) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
