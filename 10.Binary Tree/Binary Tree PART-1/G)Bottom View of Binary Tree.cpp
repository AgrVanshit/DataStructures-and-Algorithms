//*****https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1*****


//Using Vertical order Traversal:
//T.C: O(n*log(n));
//S.C: O(2*n);
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            mpp[line] = node -> data;
            
            if(node -> left) q.push({node -> left, line - 1});
            if(node -> right) q.push({node -> right, line + 1});
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*This can also be done using Recursive traversal but in that case
  we need to keep the track of level also, so it is recommended to 
  do the iterative vertical order traversal here.
*/