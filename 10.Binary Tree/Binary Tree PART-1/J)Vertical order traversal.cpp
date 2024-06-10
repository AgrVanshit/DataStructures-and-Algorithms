//*****https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/*****


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


//*****Iterative Approach(Level Order Traversal)*****
//T.C: O(n*log(n));
//S.C: O(n);
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while(!todo.empty()){

            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(node -> val);

            if(node -> left) todo.push({node -> left, {x-1, y+1}});
            if(node -> right) todo.push({node -> right, {x+1, y+1}});
        }

        vector<vector<int>> ans;

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                for(auto it : q.second) col.push_back(it);
            }
            ans.push_back(col);
        }
        return ans;
    }
};


//*****Recursive Approach(Using Inorder Traversal)***** 
//We can also use preorder or post order traversal.
//T.C: O(n*log(n));
//S.C: O(n);
class Solution {
public:
    void inorder(TreeNode* node,int vertical,int level,map<int,map<int,multiset<int>>> &nodes){
        if(node == NULL) return;
        
        inorder(node->left,vertical-1,level+1,nodes);
        nodes[vertical][level].insert(node->val);
        inorder(node->right,vertical+1,level+1,nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        inorder(root,0,0,nodes);
        vector<vector<int>> ans;
        
        for(auto p:nodes){
            vector<int> col;
            for(auto q : p.second){
                for(auto it : q.second) col.push_back(it);
            }
            ans.push_back(col);
        }
        return ans;
    }
};