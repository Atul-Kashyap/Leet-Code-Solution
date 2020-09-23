// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// Approach 1:
// Time Complexity: O(N)
// Space Complexity: O(N) or O(logN)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        sum -= root -> val;
        if(root->left == NULL && root->right == NULL)
            return (sum == 0);
        return ( hasPathSum(root->left, sum) || hasPathSum(root->right, sum ));
    }
};




// Approach 2: Iterations
// Time Complexity: O(N)
// Space Complexity: O(N) or O(logN)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        stack<pair<TreeNode*, int>> node;
        node.push({root, sum - root->val});
        TreeNode* curr;
        int total;
        while(!node.empty()){
            curr = node.top().first;
            total = node.top().second;
            node.pop();
            if(curr->right == NULL && curr->left == NULL && total == 0)
                return true;
            if(curr->right != NULL){
                node.push({curr->right, total - curr->right->val});
            }
            if(curr->left != NULL){
                node.push({curr->left, total - curr->left->val});
            }
        }
        return false;
    }
};
