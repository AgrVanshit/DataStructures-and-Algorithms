//*****https://leetcode.com/problems/binary-tree-preorder-traversal/description/*****


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


//*****Recursive Approach***** 
//T.C: O(n);
//S.C: O(n) OR O(Height of the tree);
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        preorder(root, ans);
        return ans;
    }
};


//*****Iterative Approach*****
//T.C: O(n);
//S.C: O(n) OR O(Height of the tree);
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){

            root = st.top();
            st.pop();

            ans.push_back(root -> val);

            if(root -> right != NULL) st.push(root -> right);
            if(root -> left != NULL) st.push(root -> left);

        }
        return ans;
    }
};