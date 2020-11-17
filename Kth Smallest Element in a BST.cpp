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
 
// Approach 1: Recursive Inorder Traversal
// Time complexity : O(N) to build a traversal.
// Space complexity : O(N) to keep an inorder traversal. 
    
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return NULL;
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];
    }
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL)
            return ;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};



// Approach 2: Iterative Inorder Traversal
// Time complexity : O(N+k) to build a traversal when tree is completely unbalanced.
// Space complexity :  O(H) to keep the stack, where HHH is a tree height. That makes O(N) in the worst case of the skewed tree, and O(log⁡N) in the average case of the balanced tree. 


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            if(--k == 0)
                return (root -> val);
            root = root -> right;
        }
      return NULL;
    }
};
