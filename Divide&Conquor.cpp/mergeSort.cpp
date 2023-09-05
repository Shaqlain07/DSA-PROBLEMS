class Solution {
public:
    void merge(vector<int>& arr,int l,int mid,int r) {
        //create two temp array
        int start=l;
        int end=mid+1;
        vector<int> nums;
        while(start<=mid && end<=r) {
            if(arr[start]<arr[end]) {
                nums.push_back(arr[start]);
                start++;
            }
            else {
                nums.push_back(arr[end]);
                end++;
            }
        }
        while(start<=mid) {
            nums.push_back(arr[start]);
            start++;
        }
        while(end<=r) {
            nums.push_back(arr[end]);
            end++;
        }
        int k=0;
        for(int i=l;i<=r;i++) {
            arr[i]=nums[k];
            k++;
        }
       
    }
    void mergeSort(vector<int>& arr,int l,int r) {
        //base case
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
	vector<int> sortArray(vector<int>& arr, int l, int r) {
		// Your code goes here
        mergeSort(arr,l,r);
        return arr;
	}
};
