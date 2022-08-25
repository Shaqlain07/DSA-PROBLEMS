//count no of leaf nodes
#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//No of Leaf nodes
int leafNodes(TreeNode<int>* root) {
    if(root==NULL) { //edge case
        return 0;
    }
    int count=0; // for counting leaf nodes
    if(root->children.size()==0) { //base case
        return 1;
    }
    for(int i=0;i<root->children.size();i++) {
         count+=leafNodes(root->children[i]);
    }
    return count;
}

TreeNode<int>* takeInputLevelWise() { // taking Input using queue
    int rootData;
    cout<<"Enter root Data:"<<endl;
    cin>>rootData;

    TreeNode<int>* root=new TreeNode<int>(rootData); // creating object named root

    queue<TreeNode<int>*> pendingNodes; // created queue..in node means data inside is a node
    pendingNodes.push(root);

    while(pendingNodes.size()!=0) { // Untill queue becomes empty
        TreeNode<int>* front=pendingNodes.front(); // created a node named front
        pendingNodes.pop(); // pop front nodes

        int numChild;
        cout<<"Enter no of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++) {
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>* child=new TreeNode<int>(childData); //creating object of children of front
            front->children.push_back(child); // parent child connection    
            pendingNodes.push(child); // pushing into queue
        }
    } 
    return root;
}

int main() {
    TreeNode<int>* root=takeInputLevelWise();
    cout<<leafNodes(root);

}
