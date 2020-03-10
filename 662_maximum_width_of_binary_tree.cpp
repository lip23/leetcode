//  file:  662_maximum_width_of_binary_tree.cpp
//  author：lipcat
//  time：  2020-03-10 13:03


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

class Solution {
public:
    // 由于测试用例树的深度较大，所以用如下方法会越界
    // 层次遍历，并按照满二叉树的方式对每个节点进行编号，如下：
    //                   1
    //           2              3
    //       4     5         6      7
    //     8  9  10 11     12 13  14 15
    // i节点所在的层是log2(i)
    // 在遍历的过程中求每层两个节点的最大宽度
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int left_node = 1;
        queue<pair<TreeNode*, long>> que;
        if (root) {
            que.push({root, 1});
        }
        while (!que.empty()) {
            const auto elem = que.front();
            que.pop();
            //cout << "ln:" << left_node << " " <<log2(left_node) << " cur:" << elem.second << " " << log2(elem.second) << endl;
            if (static_cast<int>(log2(elem.second)) == static_cast<int>(log2(left_node))) {
                ans = max(ans, static_cast<int>(elem.second - left_node + 1));
            } else {
                left_node = elem.second;
            }
            if (elem.first->left) {
                que.push({elem.first->left, elem.second * 2l});
            }
            if (elem.first->right) {
                que.push({elem.first->right, elem.second * 2l + 1});
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int level = 1, ind = 0;
        queue<tuple<TreeNode*, int, int>> que;
        if (root) {
            que.push({root, 1, 0});
        }
        while (!que.empty()) {
            const auto elem = que.front();
            que.pop();
            if (level == std::get<1>(elem)) {
                ans = max(ans, std::get<2>(elem) - ind + 1);
            } else {
                level = std::get<1>(elem);
                ind = std::get<2>(elem);
            }
            if (std::get<0>(elem)->left) {
                que.push({std::get<0>(elem)->left, level + 1, (std::get<2>(elem) - ind) * 2});
            }
            if (std::get<0>(elem)->right) {
                que.push({std::get<0>(elem)->right, level + 1, (std::get<2>(elem) - ind) * 2 + 1});
            }
        }
        return ans;
    }
};
