// Celebraty problem..
#include<iostream>
#include<stack>
using namespace std;

bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

void celebraty(int arr[][4],int n) {
    stack<int> st; // stack declaration
    int counter=0;
    while(counter<n) { // putting all index to stack
        st.push(counter);
        counter++;
    }
    while(st.size()>1) { // poping first two element..checking it and pushing one..
        int temp1=st.top();
        st.pop();
        int temp2=st.top();
        st.pop();

        if(arr[temp1][temp2]==0) {
            st.push(temp1);
        }
        else {
            st.push(temp2);
        }
    }
    int z=0;
    while(arr[st.top()][z]==0 && arr[z][st.top()]==1 && z<n) { //checking the last element of stack for celebraty
        z++;
    }
    if(z!=n) {
        cout<<"No celebraty";
    }
    else {
        cout<<st.top() <<" is celebraty";
    }
}

int main() {
    int arr[][4]={{0,1,1,1,1},
                 {1,0,0,1,0},
                 {1,0,0,1,0},
                 {0,0,0,0,0},
                 {0,1,0,1,1}};
    int n=4;

    celebraty(arr,n);

    return 0;
}