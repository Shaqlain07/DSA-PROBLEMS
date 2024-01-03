typedef long long ll;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Intitution
        // In every subarray if the min and max diff < 2 then
        // all elements has <2 diff.

        // Having 2 pq for track of max and min with index
        priority_queue<pair<ll,ll>> pqmx;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll>>> pqmn;

        ll cnt=0, i=0, j=0;
        ll n=nums.size();

        while(j<n) {
            // push element into queue
            pqmx.push({nums[j],j});
            pqmn.push({nums[j],j});

            // Now we have to check for condition, <=2
            // and out of bound top(max,min) uska index should to be >=i

            while(i<=j) {

            while(!pqmx.empty() && pqmx.top().second<i) pqmx.pop();
            while(!pqmn.empty() && pqmn.top().second<i) pqmn.pop();

            // shifting i if condition fails
            if(!pqmx.empty() && !pqmn.empty() && abs(pqmx.top().first-pqmn.top().first)>2) i++;
            else {
                break;
            } 

            }
            // no of subarray that is ending with j
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};
