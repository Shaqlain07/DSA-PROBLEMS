vector<int> v;
    if(root==NULL) {
        return {}; // returning empty vector
    }
    stack<int> st;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* front=q.front();
        st.push(front->data);
        q.pop();
        
        if(front->right!=NULL) {
            q.push(front->right);
        }
        if(front->left!=NULL) {
            q.push(front->left);
    vector<int> reverseLevelOrder(Node *root)
    }
    }
    while(!st.empty()) {
        int top=st.top();
        v.push_back(top);
        st.pop();
    }
    return v;
