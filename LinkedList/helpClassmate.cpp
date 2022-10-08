class Solution{
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int> ans;
        stack<int> stack;
        
        stack.push(-1);
        ans.push_back(-1);
        
        for(int i=n-2; i>=0; i--){
            if(arr[i+1]<arr[i]){
                stack.push(arr[i+1]);
                ans.push_back(arr[i+1]);
            }
            else{
                if(stack.top()<arr[i]){
                    ans.push_back(stack.top());
                }
                else{
                    while(stack.top() >= arr[i]){
                        stack.pop();
                    }
                    ans.push_back(stack.top());
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
      return ans;
        
    } 
};
