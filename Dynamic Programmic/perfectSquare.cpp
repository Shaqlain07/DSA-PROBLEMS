class Solution {
public:
    int helper(int n,int *arr) {
        //base case
        if(n<=3) {
            return n;
        }
        //check
        if(arr[n]!=-1) {
            return arr[n];
        }
        int ans=INT_MAX;
        for(int i=1;i<=sqrt(n);i++) {
            ans=min(ans,1+helper(n-i*i,arr));
        }
        //save
        arr[n]=ans;
        return ans;

    }
    int numSquares(int n) {
        //array created
        int *arr=new int[n+1];
        for(int i=0;i<=n;i++) {
            arr[i]=-1;
        }
        return helper(n,arr);
    }
};
