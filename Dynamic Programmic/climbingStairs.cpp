class Solution {
public:
    int helper(int n,int arr[]) {
        //base case
        if(n<0) return 0;
        if(n == 0) return 1;
    
        //if saved earlier
        if(arr[n]!=-1) {
            return arr[n];
        }
        //calculate,save and return
        int a=helper(n-1,arr);
        int b=helper(n-2,arr);
        int ans=a+b;
        arr[n]=ans;
        return arr[n];
    }
    int climbStairs(int n) {
        int arr[n+1];//array declared
        for(int i=0;i<=n;i++) {
            arr[i]=-1;
        }
        return helper(n,arr);
    }
};
