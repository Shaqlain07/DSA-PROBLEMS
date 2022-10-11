class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int sum=0,mx=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum==0){
                mx=i+1;//length will be from starting
            }
            else {
                if(mp.find(sum)!=mp.end()){
                    mx=max(mx,i-mp[sum]);
                }
                else{
                    mp[sum]=i;
                }
            }
    }
    return mx;
    }
};
