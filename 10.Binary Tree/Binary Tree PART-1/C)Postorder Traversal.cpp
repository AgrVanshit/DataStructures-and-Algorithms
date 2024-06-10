//*****https://leetcode.com/problems/binary-tree-postorder-traversal/description/*****


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
    void postorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        postorder(root, ans);
        return ans;
    }
};


//*****Iterative Approach(using 2 stacks)*****
/* preorder -> root left right,
   on swapping left right -> root right left,
   on reversing we get postorder -> left right root. 
*/
/* So in this approach we are appplying (root right left)
   type pre order on stack 1 and stack 2 we are using to 
   get answer in reverse order, instead of using stack 2 
   we can directly push elements in ans vector and retrun 
   its reverse at the last(as coded in comments below).
*/
//T.C: O(n);
//S.C: O(2*n);
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            if(root -> left != NULL) st1.push(root -> left);
            if(root -> right != NULL) st1.push(root -> right);
        }

        while(!st2.empty()){
            ans.push_back(st2.top() -> val);
            st2.pop();
        }

        return ans;
    }
};
/* Storing in ans vector directly instead of using stack 2 and returning its reverse-
   CODE:T.C - O(2*n);
        S.C - O(n)
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(!root)
                return ans;
            stack<TreeNode*> s;
            s.push(root);
            while(!s.empty()){
                TreeNode* temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                if(temp->left) s.push(temp->left);
                if(temp->right) s.push(temp->right);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
*/


//*****Iterative Approach(using 1 stack and without reversing ans vector at last)*****
//T.C: O(2*n);
//S.C: O(n);
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector < int > ans;
        TreeNode* cur = root;
        if (cur == NULL) return ans;

        stack <TreeNode*> st;
        while (cur != NULL || !st.empty()) {

            if(cur != NULL){
                st.push(cur);
                cur = cur -> left;
            } 
            else{
            TreeNode* temp = st.top() -> right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);
                    while (!st.empty() && temp == st.top() -> right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp -> val);
                    }
                } 
                else cur = temp;
            }
        }
        return ans;
    }
};