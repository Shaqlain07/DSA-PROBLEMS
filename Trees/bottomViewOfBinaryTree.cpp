class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;//for returning answer
        if(root==NULL) {
            return ans;
        }
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            auto it=q.front();//iterator for front node
            q.pop();
            Node* front=it.first;
            int line=it.second;
            mp[line]=front->data;//mapping
            if(front->left!=NULL) {
                q.push({front->left,line-1});
            }
            if(front->right!=NULL) {
                q.push({front->right,line+1});
            }
        }
        for(auto it:mp) {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
