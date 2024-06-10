//*****https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1*****


//Using Vertical order Traversal:
//T.C: O(n*log(n));
//S.C: O(2*n);
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
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
            
            if(mpp.find(line) == mpp.end()) mpp[line] = node -> data;
            
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

  CODE:(Recursive Traversal).
        class Solution
        {
            public:
            void dfs(Node* root, map<int, pair<int,int>> &mpp, int level, int column){
                if(root == NULL) return;
                if(mpp.find(column) == mpp.end() || level < mpp[column].second){
                    mpp[column]= {root->data, level};
                }
                dfs(root->left, mpp, level+1, column-1);
                dfs(root->right, mpp, level+1, column+1);
            }
            vector<int> topView(Node *root){
                vector<int> ans;    
                if(root == NULL ) return ans;
                map<int, pair<int,int> > mpp;
                dfs(root, mpp, 0, 0);
                for(auto it : mpp){
                    ans.push_back(it.second.first);
                }
                return ans;
            }
        };
*/