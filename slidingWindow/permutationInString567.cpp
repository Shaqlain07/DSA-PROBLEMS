class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //create map which will store the frequency of char of s1
        unordered_map<char,int> mp;
        for(int it:s1) {
            mp[it]++;
        }
        int count=mp.size();
        int k=s1.size();//wwindow size
        int i=0;//iterate on window again when it is finished
        int j=0;//iterating on s2

        while(j<s2.size()) {
            if(mp.find(s2[j])!=mp.end()) {//check if char matches with map
                mp[s2[j]]--;
                if(mp[s2[j]]==0) {
                    count--;
                }
            }
            if(j-i+1<k) {
                j++;
            }
            else if(j-i+1==k) {//window completed
                if(count==0) {
                    return true;
                }
                if(mp.find(s2[i])!=mp.end()) {
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1) {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return false;
    }
};
