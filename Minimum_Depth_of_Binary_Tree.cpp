Approach 1: Recursive
Time Complexity : O(N)
Space Complexity : O(H)
H is the height of the Binary tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
       if (!root) return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }
};
