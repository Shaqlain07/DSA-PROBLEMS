// Find Right smallest index..
#include<iostream>
#include<stack>
using namespace std;

void rightSmallestIndex(int hist[],int n) {
    stack<int> st; // stack declaration
    int rsi[n]; // array for putting right smallest element

    rsi[n-1]=-1; // since there is no right smallest element
    st.push(n-1);

    for(int i=n-2;i>=0;i--) {
        while( !st.empty() && hist[i]<hist[st.top()] ) { // pop until find smallest element or empty
            st.pop();
        }
        if(st.empty()) { // if empty i+1
            rsi[i]=-1;
        }
        else {
            rsi[i]=st.top(); 
        }
        st.push(i);
    }
    for(int i=0;i<n;i++) {
        cout<<rsi[i]<<" ";
    }

}

int main() {
    int hist[7]= {6,2,5,4,5,7,6};
    int n=7;

    rightSmallestIndex(hist,n);
    return 0;
}
