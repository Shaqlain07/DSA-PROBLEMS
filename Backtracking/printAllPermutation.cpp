class Solution {
public:
    void permutation(vector<int> &nums,vector<vector<int>> &ans,vector<int> v,int ci,unordered_map<int,bool>  mp) {
        //base case
        if(ci==nums.size()) {
            //now push v into ans 
            ans.push_back(v);
            return;
        }
        //itrating on boxes(v) to put value at every level
        for(int i=0;i<nums.size();i++) {
            //we have not put the value at that index
            if(mp[i]==false) {
                v[i]=nums[ci];
                mp[i]=true;//we have put the value there
            //call the recursive function
            permutation(nums,ans,v,ci+1,mp);
            
            //we are comming back to that level and putting that value at diff index
            v[i]=-1;
            mp[i]=false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool>  mp;
        for(int i=0;i<nums.size();i++) {
            mp[i]=false;
        }
        vector<vector<int>> ans;//2d vector
        vector<int> v(nums.size(),-1);//1d vector

        permutation(nums,ans,v,0,mp);
        return ans;
    }
};
