class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int> &left,pair<int,int> &right) {
        return left.second<right.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> curr;
        for(int i=0;i<n;i++) {
            pair<int,int> p=make_pair(start[i],end[i]);
            curr.push_back(p);
        }
        sort(curr.begin(),curr.end(),cmp);
        int cnt=1;
        int prevE=curr[0].second;
        for(int i=1;i<n;i++) {
            if(curr[i].first>prevE) {
                cnt++;
                prevE=curr[i].second;
            }
        }
        return cnt;
    }
};
