class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> qu; //queue declared
      vector<int> v;//declared vector
      qu.push(node);
      if(node==NULL){
          return v; //empty vector
      }
      
      while(!qu.empty()) {
          Node* front=qu.front();
          v.push_back(front->data);
          qu.pop();
          if(front->left!=NULL) {
          qu.push(front->left);
          }
          if(front->right!=NULL) {
          qu.push(front->right);
          }
      }
      return v;
    }
};
