class Solution {
public:
    struct AccumulateMapValues
{
    template<class V, class Pair>
    V operator()(V value, const Pair &pair) const {
        return value + pair.second;
    }
};
	int longestKSubstr(string s, int k) {
		// Your code goes here
        unordered_map<char,int> mp;
        int res=-1;
        int j=0;//iteration for cancelling
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
            if(mp.size()==k) {
                res=max(res,accumulate(mp.begin(),mp.end(),0,AccumulateMapValues()));
            }
                while(mp.size()>k) {
                    mp[s[j]]--;
                    if(mp[s[j]]==0) {
                        mp.erase(s[j]);
                    }
                    j++;
                }
        }
        return res;
	}
};
