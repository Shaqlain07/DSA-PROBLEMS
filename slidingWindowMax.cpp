// Sliding Window Maximum..
#include<iostream>
#include<stack>
using namespace std;

void slidingWindowMax(int arr[],int size,int k) {
    //Next Greater Element..
    stack<int> st;
    int resarr[size];

    for(int i=size-1;i>=0;i--) {
        if(st.empty()) {
            st.push(i);
            resarr[i]=size;
            continue;
        }
        
        if(arr[st.top()]<arr[i]) {
            while(!st.empty() && arr[st.top()]<arr[i]) 
                st.pop();
            if(!st.empty()) {
                resarr[i]=st.top();
            }
            else {
                resarr[i]=size;
            }    
        }
        else {
            resarr[i]=st.top();
        }
        st.push(i);
    }
    // Sliding Window Maximum..
    int windowMax[size-k-1]; // array for putting 
    for(int i=0;i<=size-k;i++) { // outer loop
        int j=i;
        while(resarr[j]<i+k) { // Inner loop..for finding next greater undex in window
            j=resarr[j];
        }
        windowMax[i]=arr[j];
    }
    // Print Window Maximum..
    for(int i=0;i<size-k-1;i++) {
        cout<<windowMax[i]<<" ";
    }   
}

int main() {
    int arr[]={2,9,3,8,1,7,12,6,14,4,32,0,7,19,8,12,6};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k=4;

    slidingWindowMax(arr,n,k);
    return 0;
}