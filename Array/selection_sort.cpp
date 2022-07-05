// selection sort
#include<iostream>
using namespace std;

int main() {
    int arr[6] ={5,2,16,7,1,10};

    for (int i = 0; i < 5; i++)
    {
        int mn=i;
        for (int j = i+1; j < 6; j++)
        {
            if (arr[j]<arr[mn])
            {
                mn=j;
            }
            
        }
        if (mn!=i)
        {
            swap(arr[i],arr[mn]);
        }   
    }
    //output array
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}