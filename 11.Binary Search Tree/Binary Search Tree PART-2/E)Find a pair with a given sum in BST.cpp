//*****https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/*****


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


//BFS Approach:
//T.C: O(n*log(n)); // Height = log(n);
//S.C: O(n);
class Solution {
public:
    // Iterating in whole tree and finding if target is present or not.
    // Iterative Searching.
    bool find(TreeNode* root, int target, TreeNode* curr) {
        if(root == NULL) return false;

        while(root != NULL){
            if(root != curr && root->val == target) return true;

            else if(root -> val < target) root = root -> right;

            else root = root -> left;
        }

        return false;
    } 

    //Iterating in whole tree and finding if target is present or not.
    //Recursive Searching.
    // bool find(TreeNode* root, int target, TreeNode* curr) {
    //     if(root == nullptr) return false;
                
    //     if(root != curr && root->val == target) return true;
        
	// 	return find(root->left, target, curr) || find(root->right, target, curr);
    // }
    
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                bool isPresent = find(root, k - node->val, node);
                
                if(isPresent) return true;
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return false;
    }
};


//DFS Approach:
//T.C: O(n);
//S.C: O(n) + O(n);
class Solution {
public:
    bool dfs(TreeNode* root, int target, unordered_map<int,int>& mp) {
        if(root == nullptr) return false;
        if(mp.find(target - root->val) != mp.end()) return true;
        
        mp[root->val] ++;

        return  dfs(root->left, target, mp) || dfs(root->right, target, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        unordered_map<int,int> mp;
        return dfs(root, k, mp);   
    }
};


//Optimized Approach
//Using BST Iterator
//T.C: O(n);
//S.C: 2*O(Height);
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    } 
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp -> right);
        else pushAll(temp -> left);

        return temp -> val;
    }   
    bool hasNext(){
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node){
        while(node != NULL){
            st.push(node);
            if(reverse == true) node = node -> right;
            else node = node -> left; 
        }
    }    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next(); 
        }
        return false;
    }
};