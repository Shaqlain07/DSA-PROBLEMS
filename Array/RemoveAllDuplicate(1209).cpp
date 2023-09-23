class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> v;
        string res="";
       
        for(int i=0;i<s.size();i++) {
            if(!v.empty() && v.back().first==s[i]) {
                v.back().second++;
            }
            else {
                v.push_back({s[i],1});
            }
            if(v.back().second>=k) {
                v.pop_back();
            }
        }
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].second;j++) {
                res.push_back(v[i].first);
            }
        }
        return res;

    }
};
