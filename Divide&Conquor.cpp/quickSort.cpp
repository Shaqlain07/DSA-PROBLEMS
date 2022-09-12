class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low < high) {
            int pivot=partition(arr,low,high);
            
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int i=low;//left most index of array
       int j=high;
       
       while(i < j) {
           do{//searching index which is greater than pivot
               i++;
           }while(arr[i]<=pivot);
           
           while(arr[j] > pivot) {//searching index which is smaller than pivot
               j--;
           }
           
           if(i < j) {
               swap(arr[i] , arr[j]);
           }
       }
       swap(arr[low],arr[j]);
       return j;//it is sorted index and element here is also sorted
    }
};
