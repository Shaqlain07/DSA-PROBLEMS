class Solution {
public:
    set<string> res;
    string  curr;
    unordered_map<int,int> mp;
    void solve(string s) {
        for(int i=0;i<s.size();i++) {
            if(mp[i]!=1) {
                curr.push_back(s[i]);
                mp[i]=1;
                res.insert(curr);
                solve(s);
                //backtrack
                curr.pop_back();
                mp[i]=0;            }
        }
    }
    int numTilePossibilities(string tiles) {
        solve(tiles);
        return res.size();
    }

};
