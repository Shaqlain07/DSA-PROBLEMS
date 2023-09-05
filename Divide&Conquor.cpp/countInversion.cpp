#include <bits/stdc++.h> 

void merge(long long *arr, int l, int m, int r)

{

    int i, j, k;

    int n1 = m - l + 1;

    int n2 = r - m;

 

    // Create temp arrays

    int L[n1], R[n2];

 

    // Copy data to temp arrays L[] and R[]

    for (i = 0; i < n1; i++)

        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)

        R[j] = arr[m + 1 + j];

 

    // Merge the temp arrays back into arr[l..r

    i = 0;

    j = 0;

    k = l;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {

            arr[k] = L[i];

            i++;

        }

        else {

            arr[k] = R[j];

            j++;

        }

        k++;

    }

 

    // Copy the remaining elements of L[],

    // if there are any

    while (i < n1) {

        arr[k] = L[i];

        i++;

        k++;

    }

 

    // Copy the remaining elements of R[],

    // if there are any

    while (j < n2) {

        arr[k] = R[j];

        j++;

        k++;

    }

}

int counter(long long *arr,int s,int mid,int e){

    int count=0;

    int r=mid+1;

    int i=s;

    while(s<=mid){

        while(r<=e&&arr[s]>arr[r]) r++;

        count+=r-(mid+1);

        s++;

    }

    return count;

}

int mergesort(long long *arr,int s,int e){

    int count=0;

    if(s>=e) return count;

    else{

        int mid=(s+e)/2;

        count+=mergesort(arr,s,mid);

        count+=mergesort(arr,mid+1,e);

        count+=counter(arr,s,mid,e);

        merge(arr,s,mid,e);

        return count;

    }

}

long long getInversions(long long *arr, int n){

 

    // long long cnt=0;

    // for(int i=0;i<n;i++){

    //     for(int j=i+1;j<n;j++){

    //         if(arr[j]<arr[i]) cnt++;

    //     }

    // }

    // return cnt;

    return mergesort(arr,0,n-1);

}
