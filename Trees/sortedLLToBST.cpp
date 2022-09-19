class Solution{
  public:
    TNode* bst(vector<int> &v,int s,int e) {
        if(s>e) {
            return NULL;
        }
        int m=(s+e+1)/2;//middle 
        TNode* root=new TNode(v[m]);//root created
        root->left=bst(v,s,m-1);
        root->right=bst(v,m+1,e);
        
        return root;
    }
    TNode* sortedListToBST(LNode *head) {
        //code here
        //converting LL to vector so that we can get mid iterator easily
        vector<int> v;
        int cnt=0;
        while(head) { //it will give no of nodes
            v.push_back(head->data);
            head=head->next;
            cnt++;
        }
        int start=0;// indexing start from 0
        int end=cnt-1;
        return bst(v,start,end);//it will retuen root of bst 
    }
};
