    // function should return level of the target node
    void solve(struct Node* node,int key,int level,int &ans) {
        if(node==NULL){
            return;
        }
        if(node->data==key) {
            ans=level;
            return;
        }
        solve(node->left,key,level+1,ans);
        solve(node->right,key,level+1,ans);
    }
    
    int getLevel(struct Node *node, int target)
    {
    	//code here
    	if(node==NULL){
    	    return 0;
    	}
    	int ans=0;
    	solve(node,target,1,ans);
    	return ans;
    }
