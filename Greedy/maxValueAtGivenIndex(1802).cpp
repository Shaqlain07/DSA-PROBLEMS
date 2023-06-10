class Solution {
public:
    long check(int mid,int index,int n) {
        long totalSum=0;
        //going from index to right
        if(mid>=n-index) {
            totalSum+=(long)(mid+mid-n+1+index)*(n-index)/2;
        }
        else {
            totalSum+=(long)(mid+1)*mid/2+n-index-mid;
        }
        //going from index to left
        //when res[index]<=index
        if(mid>index) {
            totalSum+=(long)(mid+mid-index)*(index+1)/2;
        }
        else {
            totalSum+=(long)(mid+1)*mid/2+index-mid+1;
        }
        totalSum-=mid;
        return totalSum;

    }
    int maxValue(int n, int index, int maxSum) {
        int left=1,right=maxSum;
        while(left<right) {
            int mid=(left+right+1)/2;
            if(check(mid,index,n)<=maxSum) {
                left=mid;
            }
            else {
                right=mid-1;
            }
        }
        return left;
    }
};
