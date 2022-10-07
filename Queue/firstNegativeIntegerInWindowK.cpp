#include<bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	// Write your code here.
    vector<int> ans;
     queue<int> q;
                                                 for(int i=0;i<k-1;i++) {
                                                     if(arr[i]<0) {
                                                         q.push(arr[i]);
                                                     }
                                                 }
                                                 for(int i=k-1;i<n;i++) {
                                                     if(arr[i]<0){
                                                         q.push(arr[i]);
                                                     }
                                                     if(!q.empty()){
                                                         ans.push_back(q.front());
                                                         if(q.front()==arr[i-k+1]){
                                                             q.pop();
                                                         }
                                                     }
                                                     else{
                                                         ans.push_back(0);
                                                     }
                                                 }
                                                 return ans;
}
