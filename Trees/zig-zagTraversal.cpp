class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> v;
    	if(root==NULL) {
    	    return  v;
    	}
    	queue<Node*> q;
    	q.push(root);
    	//R->L=true,l->r=false
    	bool flag=true;
    	while(!q.empty()) {
    	    int size=q.size();//nodes available in queue in 1 level
    	    vector<int> row(size);//to store nodes at 1 level
    	    for(int i=0;i<size;i++) {
    	        Node* front=q.front();
    	        q.pop();
    	        //now if flag is true.nodes will be pushed from front in row
    	        //else from back
    	        int index=flag? i:size-1-i;
    	        row[index]=front->data;
    	        if(front->left) {
    	            q.push(front->left);
    	        }
    	        if(front->right) {
    	            q.push(front->right);
    	        }
    	    }
    	    //after that level
    	    flag=!flag;//change the flag
    	    for(auto i:row) {
    	        v.push_back(i);
    	    }
    	    }
    	
    	return v;
    }
};
