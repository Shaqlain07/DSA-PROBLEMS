#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;



// calculate sum of all nodes
int sumNodes(TreeNode<int>* root) {
    int ans=root->data;
    for(int i=0;i<root->children.size();i++) {
        ans+=sumNodes(root->children[i]);
    }
    return ans;
}

// calculating no of nodes
int countNodes(TreeNode<int>* root) {
    int ans=1; // for root count
    for(int i=0;i<root->children.size();i++) {
        ans+=countNodes(root->children[i]);
    }
    return ans; // every fn will return 1(its root) and last its add up
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

TreeNode<int>* takeInput() { // taking Input using recursion
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;

    TreeNode<int>* root=new TreeNode<int>(rootData); // creating object dynammically

    int n;
    cout<<"Enter no of children "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++) {
        TreeNode<int>* child=takeInput(); // return of recursive fn will be child of existing root
        root->children.push_back(child); // pushes child into vector of root that creates parent child relation
    }
    return root;
} 

void printTree(TreeNode<int>* root) {
    cout<<root->data<<":"; // printing data of root node
    for(int i=0;i<root->children.size();i++) { // printing children of root
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++) {
        printTree(root->children[i]); // calling recursive function to access the children of a root
    }
}

int main() {
  /*  TreeNode<int>* root=new TreeNode<int>(1); //creating obj named root and passing the data
    TreeNode<int>* node1=new TreeNode<int>(2);
    TreeNode<int>* node2=new TreeNode<int>(3);

    root->children.push_back(node1); // sending node1 address vector of root node
    root->children.push_back(node2); // by doing so..it will connect the children to its parent
  */
    TreeNode<int>* root=takeInputLevelWise();
    cout<<countNodes(root)<<endl;
    cout<<sumNodes(root)<<endl;

}
