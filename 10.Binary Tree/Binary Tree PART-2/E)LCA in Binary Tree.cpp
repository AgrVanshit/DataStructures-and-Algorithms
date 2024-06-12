//*****https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/*****


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*Bruteforce Approach:(Find the root to node path of both the nodes 
                       whose LCA to be found, storing them in the vector,
                       the last common node in both the vector is the 
                       lowest common ancestor between both the given nodes).*/
//T.C: O(3*n);
//S.C: O(2*n);
class Solution {
    bool getPath(TreeNode* root, TreeNode* x, vector<TreeNode*> &path) {
        if (root == NULL) return false;

        path.push_back(root);
        
        if(root == x) return true;

        if (getPath(root->left, x, path) || getPath(root->right, x, path))
            return true;

        path.pop_back();

        return false;
    }

    vector<TreeNode*> getPathtoNode(TreeNode* A, TreeNode* B) {
        vector<TreeNode*> path;
        if (A == NULL) return path;

        getPath(A, B, path);

        return path;
    }
    
    TreeNode* findLastCommon(vector<TreeNode*> a,vector<TreeNode*> b){
        TreeNode* lastCommon = NULL;

        for(int i = 0; i < min(a.size(), b.size()); i++){
            if(a[i] == b[i]) lastCommon = a[i];
        }

        return lastCommon;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathToP = getPathtoNode(root,p);
        vector<TreeNode*> pathToQ = getPathtoNode(root,q);

        TreeNode* LCA = findLastCommon(pathToP,pathToQ);

        return LCA;
    }
};


//Optimal Approach:
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root; //if both are not NULL, means we found our answer.
    }
};
