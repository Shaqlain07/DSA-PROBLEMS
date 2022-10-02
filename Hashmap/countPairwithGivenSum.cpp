class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<n;i++) {
            if(mp.count(k-arr[i])>0) {
                count+=mp[k-arr[i]];//adding the freq..how many times it comes earlier
            }
            mp[arr[i]]++;//it is mapped..we are increasing frequency
            
        }
        return count;
    }
};
