class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> indicesOfValue;
        for(int i=0;i<arr.size();i++) {
            indicesOfValue[arr[i]].push_back(i);
        }
        vector<bool> visited(arr.size());
        visited[0]=true;
        queue<int> q;
        q.push(0);
        int step=0;
        while(!q.empty()) {
            for(int size=q.size();size>0;--size) {
                int i=q.front();
                q.pop();
                if(i==arr.size()-1) return step;
                vector<int> &next=indicesOfValue[arr[i]];
                next.push_back(i-1);next.push_back(i+1);
                for(int j:next) {
                    if(j>=0 && j<arr.size() && !visited[j]) {
                        visited[j]=true;
                        q.push(j);
                    }
                }
                indicesOfValue[arr[i]].clear();
            }
            step++;
        }
        return 0;
    }
};
