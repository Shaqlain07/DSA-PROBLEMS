class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(begin(time),end(time));
        long long low = 0, high = 1LL*time[n-1]*totalTrips;
        long long mintime = 1LL*time[n-1]*totalTrips;
        while(low<high){
            long long ans = 0;
            long long mid = (low+high)/2;
            for(int j=0;j<n;j++){
                ans += mid/time[j];
            }
            if(ans >= totalTrips)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
