class Solution{
    public:
    //O(N)..time complexity
    vector<int> removeDuplicate(int A[], int N) {
        unordered_map<int,bool> mp;//map declared
        vector<int> v;
        for(int i=0;i<N;i++) {
            if(mp.count(A[i])==0) {// check a[i] is present in map or not 
                mp[A[i]]=true;
                v.push_back(A[i]);
            }
        }
        return v;
    }
};
