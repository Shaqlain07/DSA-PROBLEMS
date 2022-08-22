// Left smallest index..
#include<iostream>
#include<stack>
using namespace std;

void leftSmallestIndex(int hist[],int n) {
    stack<int> st; // stack declaration
    int lsi[n]; // array declaration for left smallest index

    for(int i=0;i<n;i++) {
        while(!st.empty() && hist[i]<=hist[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            lsi[i]=-1;
        }
        else {
            lsi[i]=st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++) {
        cout<<lsi[i]<<" ";
    }
}

int main() {
    int hist[7]={6,2,5,4,5,1,6};
    int n=7;

    leftSmallestIndex(hist,n);
    return 0;
}