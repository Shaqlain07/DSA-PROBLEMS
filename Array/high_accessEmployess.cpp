class Solution {
public:
    bool isValid(vector<int> curr) {
        for(int i=0;i<curr.size()-2;i++) {
            if(curr[i+2]-curr[i]<60) return true;

        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& acc) {
        unordered_map<string,vector<int>> mp;
        vector<string> res;

        for(int i=0;i<acc.size();i++) {
            string emp=acc[i][0];
            string time=acc[i][1];
            string hrs=time.substr(0,2);
            string min=time.substr(2,2);

            int totalMin=stoi(hrs)*60+stoi(min);

            mp[emp].push_back(totalMin);
        }

        // iterate on map
        for(auto it: mp) {
            if(it.second.size()<3) continue;
            sort(it.second.begin(),it.second.end());
            if(isValid(it.second)) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
