class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low < high)
        {
            int pivotidx = partition(arr,low,high);
            quickSort(arr,low,pivotidx-1);
            quickSort(arr,pivotidx+1,high);
        }
    }
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
        int pivot = arr[low], i = low, j = high;
        while(i < j)
        {
            while(pivot >= arr[i])
                i++;
            while(pivot < arr[j])
                j--;
            if(i < j)
                swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }
};
