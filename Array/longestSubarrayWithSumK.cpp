 // Write your code here
    unordered_map<int,int> mp;
    int sum=0;
    int len=0;
    for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if(sum==k) {
            len=i+1;
        }
        int rem=sum-k;
        if(mp.find(rem)!=mp.end()) {
            int diff=i-mp[rem];
            len=max(len,diff);
        }
        //If we have mapped a particular sum previous
        //then we are not mapping since we want index to be leftmost 
        //for a particular sum 
        if(mp.find(sum)==mp.end()) {
            mp[sum]=i;    
        }
    }
    return len;
