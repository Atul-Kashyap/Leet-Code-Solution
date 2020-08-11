Approach 1 : Recursive
Time Complexity : O(N)
Auxiliary Space : O(N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        Helper(arr, root);   
        return arr;
    }
    void Helper(vector<int> &arr, TreeNode* root){
        if(root == NULL)
            return;
        Helper(arr, root->left);
        arr.push_back(root->val);
        Helper(arr, root->right);
    }
};


Approach 2 : Iterative using stack
Time Complexity : O(N)
Auxiliary Space : O(N)


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            ans.push_back(curr -> val);
            curr = curr -> right;
            st.pop();
        }
      return ans; 
    }
   
};
