/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* root) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n=q.size();
            for(int i=0;i<n;i++) {
                root=q.front();
                q.pop();
                if(i==n-1) {
                    root->next=NULL;
                }
                else {
                    root->next=q.front();
                }
                //put its children in queue
                if(root->left) {
                    q.push(root->left);
                }
                if(root->right) {
                    q.push(root->right);
                }
            }
        }
    }
    Node* connect(Node* root) {
        //edge case
        if(root==NULL) return NULL;
        helper(root);
        return root;
    }
};
