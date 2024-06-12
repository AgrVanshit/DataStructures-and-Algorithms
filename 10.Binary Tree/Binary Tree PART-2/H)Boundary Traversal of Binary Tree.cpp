//*****https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1*****


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


//T.C: O(Height) + O(n) + O(Height);
//S.C: O(n);
class Solution {
public:
    bool isLeaf(Node* node){
        if(node -> left == NULL && node -> right == NULL) return true;
        return false;
    }

    void addBoundryLeft(Node* root, vector<int>& ans){
        Node* curr = root -> left;

        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr -> data);
            
            if(curr -> left) curr = curr -> left;
            else curr = curr -> right;
        }
    }

    void addBoundryRight(Node* root, vector<int>& ans){
        Node* curr = root -> right;
        stack<int> st;

        while(curr){
            if(!isLeaf(curr)) st.push(curr -> data);
            
            if(curr -> right) curr = curr -> right;
            else curr = curr -> left;
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    
    //Preorder Traversal
    void addLeaves(Node* root, vector<int>& ans){
        if(root == NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root -> data);
        }

        if(root -> left) addLeaves(root -> left, ans);
        if(root -> right) addLeaves(root -> right, ans);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;

        if(!isLeaf(root)) ans.push_back(root -> data);
        addBoundryLeft(root, ans);
        addLeaves(root, ans);
        addBoundryRight(root, ans);
        
        return ans;
    }
};