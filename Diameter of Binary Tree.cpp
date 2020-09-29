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


// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. //This path may or may not pass through the root.
// Approach 1: DFS
// Time Complexity : O(N)
// Space Complexity : O(N)


class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;    
    }
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        int L = depth(root -> left);
        int R = depth(root -> right);
        ans = max(ans, L+R);
        return max(L, R) + 1;
    }
};
