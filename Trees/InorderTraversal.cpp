void func(Node*root,vector<int>&v){

      if(root){

          func(root->left,v);

          v.push_back(root->data);

          func(root->right,v);

      }

  }

    vector<int> inOrder(Node* root) {

        vector<int>v;

        func(root,v);

        return v;

    }
