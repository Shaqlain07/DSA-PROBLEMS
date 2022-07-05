// Bubble sort
#include<iostream>
using namespace std;

int main() {
    int arr[6]={5,2,16,7,1,10};

    int counter=1;
    while (counter<=6-1)
    {
        for(int i=0; i<6-counter; i++) {
            if (arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
            
        }
        counter++;
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}