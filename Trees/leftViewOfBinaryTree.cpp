//easy solution .

 

void PreOrder(Node* root,int level,vector<int>& ans){

    

    if(!root) return;

    

    if(level == ans.size()){

        ans.push_back(root->data);

    }

    

    PreOrder(root->left,level + 1,ans);

    PreOrder(root->right,level + 1,ans);

    

}

 

 

vector<int> leftView(Node *root){

   

   if(!root){

       return {};

   }

   

   /*

   //using queue.

   vector<int>ans;

   queue<Node*>q;

   

   q.push(root);

   

   while(!q.empty()){

       

       int sz = q.size();

       

       for(int i = 1;i <= sz;++i){

           

           Node* t = q.front();

           q.pop();

           

           if(i == 1){

               ans.push_back(t->data);

           }

           

           if(t->left){

               q.push(t->left);

           }

           

           if(t->right){

               q.push(t->right);

           }

       }

       

   }

   

   return ans;

   */

   

   //apply reverse preorder traversal recursion

   //Root-Left-Right reverse Root-Right-Left for Right View

   

   vector<int>ans;

   int level = 0;

   

   PreOrder(root,level,ans);

   

   return ans;

   

}
